//https://cses.fi/problemset/task/2134
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int,int>
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define ppi pair<pair<int,int>,int>
#define pb push_back
#define F first
#define S second
#define forEC(var, container) for( const auto& var: container)
#define forE(var, container) for( const auto& var: container)
const int MOD=1e9+7;
using namespace std;

const int MAXN = 200005;
const int LOG = 20; // suficiente para n <= 2e5

struct node{
    int val;
    vi nbr;
};

node nodes[MAXN];
int parent[MAXN], sz[MAXN], depth[MAXN];
int n, queries;

// HLD estructuras
int heavy[MAXN], pos[MAXN], baseArr[MAXN], head[MAXN], currPos;

// Tabla para LCA
int up[MAXN][LOG];

// ---------------- DFS1: sizes, parent, depth, heavy ----------------
int dfs_sz(int x, int par){
    parent[x] = par;
    depth[x] = depth[par] + 1;
    sz[x] = 1;
    heavy[x] = -1;
    int maxChild = 0;
    for(int y : nodes[x].nbr){
        if(y == par) continue;
        sz[x] += dfs_sz(y, x);
        if(sz[y] > maxChild){
            maxChild = sz[y];
            heavy[x] = y;
        }
    }
    return sz[x];
}
// ------------------------------------------------------------------

// ---------------- Build LCA table (binary lifting) ----------------
void buildLCA(){
    for(int v = 1; v <= n; ++v) up[v][0] = parent[v];
    for(int j = 1; j < LOG; ++j){
        for(int v = 1; v <= n; ++v){
            int mid = up[v][j-1];
            up[v][j] = (mid ? up[mid][j-1] : 0);
        }
    }
}

int lca(int a, int b){
    if(a == b) return a;
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int j = 0; j < LOG; ++j){
        if(diff & (1<<j)) a = up[a][j];
    }
    if(a == b) return a;
    for(int j = LOG-1; j >= 0; --j){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return parent[a];
}
// ------------------------------------------------------------------

// ---------------- DFS2: decompose and fill baseArr ----------------
void decompose(int x, int h){
    head[x] = h;
    pos[x] = currPos;
    baseArr[currPos] = nodes[x].val;
    currPos++;

    if(heavy[x] != -1) decompose(heavy[x], h);
    for(int y : nodes[x].nbr){
        if(y == parent[x] || y == heavy[x]) continue;
        decompose(y, y);
    }
}
// ------------------------------------------------------------------

// ---------------- Segment tree (range max, point update) ----------
struct Segment{
    vi st;
    int sz;
    const int NEG = -1e18;

    void init(int _n){
        this->sz = _n;
        this->st.assign(4*_n + 5, NEG);
    }

    void build(int node, int s, int e, int* a){
        if(s == e){ st[node] = a[s]; return; }
        int m = (s + e) >> 1;
        build(node<<1, s, m, a);
        build(node<<1|1, m+1, e, a);
        st[node] = max(st[node<<1], st[node<<1|1]);
    }

    int qry(int node, int s, int e, int l, int r){
        if(s > r || e < l) return NEG;
        if(s >= l && e <= r) return st[node];
        int m = (s + e) >> 1;
        return max(qry(node<<1, s, m, l, r), qry(node<<1|1, m+1, e, l, r));
    }

    void upd(int node, int s, int e, int idx, int val){
        if(s == e){ st[node] = val; return; }
        int m = (s + e) >> 1;
        if(idx <= m) upd(node<<1, s, m, idx, val);
        else upd(node<<1|1, m+1, e, idx, val);
        st[node] = max(st[node<<1], st[node<<1|1]);
    }
};
// ------------------------------------------------------------------

// ---------------- pathUp and qryPath (HLD + LCA) ------------------
// pathUp: maximum on path from u up to anc (excluding anc). Assumes anc is ancestor of u.
int pathUp(int u, int anc, Segment &st){
    int res = -1;
    while(u != anc){
        if(head[u] == u){
            // chain size 1 (head is itself) -> use direct node value
            res = max(res, (int)nodes[u].val);
            u = parent[u];
        } else if(depth[ head[u] ] > depth[ anc ]){
            // can take entire chain head[u]..u
            int h = head[u];
            res = max(res, st.qry(1, 1, n, pos[h], pos[u]));
            u = parent[h];
        } else {
            // chain intersects anc -> take pos[anc]+1 .. pos[u] then break
            int l = pos[anc] + 1;
            int r = pos[u];
            if(l <= r) res = max(res, st.qry(1, 1, n, l, r));
            break;
        }
    }
    return res;
}

int qryPath(int a, int b, Segment &st){
    int L = lca(a, b);
    int r1 = pathUp(a, L, st);
    int r2 = pathUp(b, L, st);
    int ans = max(max(r1, r2), (int)nodes[L].val);
    return ans;
}
// ------------------------------------------------------------------

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    //cin >> T;
    while(T--){
        cin >> n >> queries;
        for(int i = 1; i <= n; ++i){
            cin >> nodes[i].val;
            nodes[i].nbr.clear();
        }
        for(int i = 0; i < n-1; ++i){
            int u, v;
            cin >> u >> v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }

        // init
        for(int i = 1; i <= n; ++i) heavy[i] = -1;
        depth[0] = 0;

        // DFS1
        dfs_sz(1, 0);

        // build LCA table
        buildLCA();

        // DFS2
        currPos = 1;
        decompose(1, 1);

        // segment tree
        Segment st;
        st.init(n);
        st.build(1, 1, n, baseArr);

        // queries
        while(queries--){
            int type;
            cin >> type;
            if(type == 1){
                int s, x;
                cin >> s >> x;
                st.upd(1, 1, n, pos[s], x);
                nodes[s].val = x; // keep nodes[].val consistent
            } else {
                int a, b;
                cin >> a >> b;
                int ans = qryPath(a, b, st);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
