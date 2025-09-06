//https://codeforces.com/problemset/problem/620/E
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

const int MAXN = 400005;

struct node{
    int color;
    vi nbr;
};

node nodes[MAXN];
int n,N,q, tin[MAXN], tout[MAXN], timer, euler[2*MAXN];
int st[8*MAXN], lz[8*MAXN];

void build( int x, int s, int e){
    if( s==e ){st[x]= (1LL<<nodes[euler[s]].color);return;}
    int m = (s+e)>>1;
    build(x<<1, s,m);
    build(x<<1|1, m+1,e);
    st[x] = st[x<<1]|st[x<<1|1];
}

void push(int x, int l, int r){
    if( lz[x] != 0 ){
        st[x] = lz[x];
        if( l<r ){
            lz[x<<1] = lz[x];
            lz[x<<1|1] = lz[x];
        }
        lz[x] = 0;
    }
}

void upd(int x, int s, int e, int l, int r, int val){
    push(x,s,e);
    if( s>r || e < l ) return;
    if( s>=l && e<=r ){
        lz[x] = (1LL<<val);
        push(x,s,e);
        return;
    }
    if( s==e ){
        st[x] = (1LL<<val);
        return;
    }
    int m = (s+e)>>1;
    upd(x<<1, s,m,l,r,val);
    upd(x<<1|1,m+1,e,l,r,val);
    st[x] = st[x<<1] | st[x<<1|1];
}


int qry(int x, int s, int e, int l, int r){
    push(x,s,e);
    if( s > r || e < l) return 0;
    if( s>=l && e<=r ) return st[x];
    int m = (s+e)>>1;
    return qry(x<<1,s,m,l,r)|qry(x<<1|1,m+1,e,l,r);
}

void dfs(int node, int par){
    euler[timer] = node;
    tin[node] = timer++;

    forEC(x,nodes[node].nbr){
        if( x == par ) continue;
        dfs(x,node);
    }
    euler[timer] = node;
    tout[node] = timer++;
}

int count_bits(int x){
    int ans = 0;
    while( x > 0){
        x = x&(x-1);
        ans++;
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cin>>n>>q;
        N = 2*n;
        timer = 0;
        for( int i = 1; i <= n ; i++ ){
            cin>>nodes[i].color;
        }
        for( int i = 0; i < n-1; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }
        dfs(1,0);
        build(1,0,N-1);

        while(q--){
            int opt,v,c;
            cin>>opt;
            if( opt == 1){
                cin>>v>>c;
                int tn = tin[v], tt=tout[v];
                upd(1,0,N-1,tn,tt,c);
            }else{
                cin>>v;
                int tn = tin[v],tt=tout[v];
                cout<<count_bits(qry(1,0,N-1,tn,tt))<<"\n";
            }
        }

    }
    return 0;
}