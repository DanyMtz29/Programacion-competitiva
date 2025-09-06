//https://codeforces.com/problemset/problem/1324/F
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
    //false -> black, true -> white
    bool color;
    vi nbr;
};

node nodes[MAXN];
int n, sz[MAXN], dp[MAXN], whites[MAXN];

int dfs(int node, int par){
    whites[node] = nodes[node].color?1:-1;

    forEC(nbrNode, nodes[node].nbr){
        if( nbrNode == par ) continue;
        int ds = dfs(nbrNode,node);
        whites[node] += ds>0?ds:0;
    }
    return whites[node];
}

void reroot(int node, int par){

    forEC(nbrNode, nodes[node].nbr){
        if( nbrNode == par ) continue;

        int a = whites[node], b = whites[nbrNode];

        whites[node] -= whites[nbrNode]>0?whites[nbrNode]:0;
        whites[nbrNode] += whites[node]>0?whites[node]:0;

        dp[nbrNode] = whites[nbrNode];
        reroot(nbrNode, node);
        whites[node] = a, whites[nbrNode] = b;
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
        for( int i = 1; i <=n ; i++ ){
            cin>>nodes[i].color;
            dp[i] =  sz[i] = whites[i] = 0;
        }

        for( int i = 0; i < n-1; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }

        dfs(1,-1);
        dp[1] = whites[1];

        reroot(1,-1);
        for( int i = 1; i <=n; i++ )
            cout<<dp[i]<<" ";
        
    }
    return 0;
}