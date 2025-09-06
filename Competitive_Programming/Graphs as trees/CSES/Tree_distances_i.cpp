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

struct node{
    vi nbr;
};

node nodes[MAXN];
int n,mxD,lastNode, distances[MAXN];

void dfs(int node, int par, int depth){

    forEC(nbrNode, nodes[node].nbr){
        if( nbrNode == par ) continue;

        dfs( nbrNode, node, depth + 1 );
    }

    distances[node] = max(distances[node],depth);

    if( depth > mxD ){
        mxD = depth;
        lastNode = node;
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
        cin>>n;
        for( int i = 0; i < n-1; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }
        for( int i = 1; i <= n; i++ ) distances[i] = 0;

        mxD = 0;
        dfs(1,-1, 0);
        mxD = 0;
        dfs(lastNode, -1,0);
        mxD = 0;
        dfs(lastNode, -1,0);
        for( int i = 1; i <= n; i++ )
            cout<<distances[i]<<" ";
        cout<<"\n";

    }
    return 0;
}