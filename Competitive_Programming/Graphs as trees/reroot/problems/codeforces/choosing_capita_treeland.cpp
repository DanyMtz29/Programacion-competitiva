//https://codeforces.com/problemset/problem/219/D
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
    vector<pi> nbr;
};

node nodes[MAXN];
int n, dp[MAXN];
int inversiones[MAXN];

void dfs(int node, int par){
    forEC(prNode, nodes[node].nbr){
        int nbrNode = prNode.F;
        if( nbrNode == par ) continue;

        bool inversion = prNode.S;
        dfs( nbrNode, node );
        inversiones[node] += inversiones[nbrNode] + inversion;
    }
}

void reroot(int node, int par){
    forEC( prNode, nodes[node].nbr ){
        int nbrNode = prNode.F;
        if( nbrNode == par ) continue;

        int inversion = prNode.S;
        int a = inversiones[node], b = inversiones[nbrNode];

        inversiones[node] -= inversiones[nbrNode];
        inversiones[node] -= inversion;

        inversiones[nbrNode] += inversiones[node];
        inversiones[nbrNode] += !inversion;

        dp[nbrNode] = inversiones[nbrNode];

        reroot( nbrNode,node );
        inversiones[node] = a, inversiones[nbrNode] = b;
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
            nodes[u].nbr.pb({v,0});
            nodes[v].nbr.pb({u,1});
        }
        for( int i = 1; i <=n ; i++ ){
            inversiones[i]=0;
        }
        dfs(1,-1);

        dp[1] = inversiones[1];
        reroot(1,-1);

        vector<int> ans;
        int mn = INT_MAX;
        for( int i = 1; i <= n; i++ ){
            if( dp[i] < mn ){
                ans.clear();
                mn = dp[i];
                ans.pb(i);
            }else if( dp[i]==mn )
                ans.pb(i);
        }
        sort( all(ans) );
        cout<<mn<<"\n";
        forEC(x,ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}