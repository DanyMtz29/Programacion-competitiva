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
    //int val;
    vi nbr;
};

node nodes[MAXN];
int n,subordinates[MAXN];

int dfs(int node, int par){

    int subs = 0;
    for( const auto& nbrNode: nodes[node].nbr ){
        //if( nbrNode.val == par ) continue;
        subs += 1 + dfs( nbrNode, node );
    }

    subordinates[node] = subs;
    return subs;
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
        subordinates[1]=0;
        for( int i = 2; i <= n; i++ ){
            int x;
            cin>>x;
            nodes[x].nbr.pb(i);
            subordinates[i] = 0;
        }
        dfs( 1,-1 );
    }
    
    for( int i = 1; i <= n; i++ ){
        cout<<subordinates[i]<<" ";
    }
    cout<<"\n";

    return 0;
}