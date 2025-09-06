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
const int MOD=1e9+7;
using namespace std;

const int MAXN = 200005;

struct node{
    int val;
    vector<int> nbr;
};

vector<int> tin,tout;
node nodes[MAXN];
int n,m,temp;


void dfs(int node, int par){
    tin[node] = temp++;
    for( const auto nbrNode: nodes[node].nbr ){
        if( nbrNode == par ) continue;

        dfs( nbrNode, node );
    }
    tout[node] = temp;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cin>>n>>m;

        tin.resize(n+1);
        tout.resize(n+1);
        
        temp = 0;

        for( int i = 1; i <= n; i++ ){
            cin>>nodes[i].val;
        }

        for( int i = 0; i < n-1; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }

        dfs(1,-1);
        
        map<int,vi> mp;
        for( int i = 1; i <= n; i++ ){
            mp[ nodes[i].val ].pb( tin[i] );
        }

        for( auto& pr: mp ){
            sort( all(pr.second) );
        }

        for( int i = 0; i < m; i++ ){
            int x,k;
            cin>>x>>k;
            int total = upper_bound(all(mp[k]),tout[x]-1) -lower_bound(all(mp[k]), tin[x]);
            cout<<total<<"\n";
        }

    }
    return 0;
}