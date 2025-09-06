//https://cses.fi/problemset/task/1694
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define pi pair<int,int>
using namespace std;

const int MAXN = 505; // Ajustar segun problema

struct Edge {
    int to;
    int cap;
    int rev; // índice de la arista inversa en nodes[to].nbr
    Edge(int _to, int _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {}
};

struct Node {
    vector<Edge> nbr;
};

Node nodes[MAXN];
int n, m;
const int INF_FLOW = (int)1e18;
int level[MAXN];
int ptr[MAXN];

// añade arista dirigida u->v con capacidad c (y la arista residual v->u con cap 0)
void add_edge(int u, int v, int c){
    int idx_u = nodes[u].nbr.size(); // índice que tendrá la nueva arista en nodes[u].nbr
    int idx_v = nodes[v].nbr.size(); // índice que tendrá la nueva arista en nodes[v].nbr (antes de empujar)
    nodes[u].nbr.pb( Edge(v, c, idx_v) ); // forward
    nodes[v].nbr.pb( Edge(u, 0, idx_u) ); // backward con cap 0
}

bool bfs(int s, int t){
    //Reiniciando niveles
    for(int i = 1; i <= n; ++i) level[i] = -1;
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(const Edge &e : nodes[v].nbr){
            if(e.cap > 0 && level[e.to] == -1){//Si la arista no esta saturada y aun no tiene nivel
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1; // true si t es alcanzable en el residual graph
}

int dfs(int v, int t, int pushed){
    if(pushed == 0) return 0;
    if(v == t) return pushed;
    // iteramos desde ptr[v] para no reexaminar aristas ya saturadas
    for(int &cid = ptr[v]; cid < (int)nodes[v].nbr.size(); ++cid){
        Edge &e = nodes[v].nbr[cid];
        if(level[e.to] == level[v] + 1 && e.cap > 0){
            int tr = dfs(e.to, t, min(pushed, e.cap));
            if(tr > 0){
                // aplicar el flujo en forward/backward
                e.cap -= tr;
                nodes[e.to].nbr[e.rev].cap += tr;
                return tr;
            }
        }
    }
    return 0;
}

long long dinic(int s, int t){
    long long flow = 0;
    while(bfs(s, t)){
        // reiniciar punteros
        for(int i = 1; i <= n; ++i) ptr[i] = 0;
        while(true){
            int pushed = dfs(s, t, INF_FLOW);
            if(pushed == 0) break;
            flow += pushed;
        }
    }
    return flow;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) nodes[i].nbr.clear();

    for(int i = 0; i < m; ++i){
        int from, to, speed;
        cin >> from >> to >> speed;
        add_edge(from, to, speed);
    }

    int s = 1;
    int t = n;
    long long maxflow = dinic(s, t);
    cout << maxflow << '\n';
    return 0;
}
