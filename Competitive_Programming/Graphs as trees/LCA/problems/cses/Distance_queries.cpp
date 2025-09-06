//https://cses.fi/problemset/task/1135
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
const int M = 20;

struct node{
    int val;
    vi nbr;
};

node nodes[MAXN];
int n,q, depth[MAXN], parents[MAXN][M];

void dfs(int node, int par){

    depth[node] = depth[par]+1;
    parents[node][0] = par;
    for( int j = 1; j < M; j++ ){
        parents[node][j] = parents[parents[node][j-1]][j-1];
    }

    forEC(nbrNode, nodes[node].nbr){
        if( nbrNode == par) continue;

        dfs( nbrNode, node );
    }
}

int lca(int a, int b){
    if( a == b ) return a;

    if( depth[a] < depth[b] ) swap(a,b);
    
    //Diferencia para subir al mismo nivel
    int diff = depth[a]-depth[b];
    for( int i = M-1; i >= 0; i-- ){
        if( (diff>>i)&1 ){
            a = parents[a][i];
        }
    }

    if( a==b ) return a;
    //Como ya estan en el mismo nivel, buscamos el padre
    for( int i = M-1; i >=0 ; i-- ){
        if( parents[a][i] != parents[b][i]){
            a = parents[a][i];
            b = parents[b][i];
        }
    }

    //Retornamos el primer padre hacia arriba de 
    //cualquiera de los dos nodos
    return parents[a][0];
}

int distFromAtoB(int a, int b){
    int LCA = lca(a,b);
    return depth[a] + depth[b] - 2 * depth[LCA];
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
        for( int i = 1; i <= n-1 ; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }
        
        dfs(1,0);

        while( q-- ){
            int a,b;
            cin>>a>>b;
            cout<<distFromAtoB(a,b)<<"\n";
        }
    }
    return 0;
}