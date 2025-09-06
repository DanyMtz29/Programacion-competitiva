//https://cses.fi/problemset/task/1133
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

struct node{//Nodo
    int val;
    vi nbr;
};

node nodes[MAXN];
int n, sz[MAXN], dp[MAXN];

int dfs(int node, int par){
    sz[node] = 1;
    forEC(nbrNode, nodes[node].nbr){
        if( nbrNode == par ) continue;

        sz[node] += dfs(nbrNode, node);
    }

    return sz[node];
}

void reroot( int node, int par ){
    forEC(nbrNode, nodes[node].nbr){
        if( nbrNode == par ) continue;

        int szNode = sz[node], szNbrNode = sz[nbrNode];

        dp[nbrNode] = dp[node];

        dp[nbrNode] -= sz[node] , dp[nbrNode] -= sz[nbrNode];
        sz[node] -= sz[nbrNode], sz[nbrNode] = n;
        dp[nbrNode] += sz[node], dp[nbrNode] += sz[nbrNode];
        reroot(nbrNode, node);
        sz[node] = szNode, sz[nbrNode] = szNbrNode;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){

        cin>>n;//Total de nodos

        //Leyendo las conexiones del arbol
        for( int i = 0; i < n-1; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }
        for( int i = 1; i <= n; i++ )
            sz[i] = 0, dp[i] = 0;

        dfs(1,-1);

        for( int i = 1; i <=n ; i++ )
            dp[1] += sz[i];

        reroot(1,0);

        for( int i = 1; i <= n ; i++ )
            cout<<dp[i]-n<<" ";
        cout<<"\n";
    }
    return 0;
}