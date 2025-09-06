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
int n, total;

bool dfs(int node, int par){
    bool flag = false;
    for( const auto& nbrNode: nodes[node].nbr ){
        if( nbrNode == par ) continue;

        if( nodes[nbrNode].nbr.size() == 1){
            if( !flag ){
                flag = true;
                total++;
            }
        }
        else{
            bool sub = dfs( nbrNode, node );
            if( !sub && !flag){
                total++;
                flag = true;
            }
        }
    }

    return flag;

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
        total = 0;
        for( int i = 1; i < n; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }

        dfs( 1,-1 );
        cout<<total<<"\n";
    }

    return 0;
}