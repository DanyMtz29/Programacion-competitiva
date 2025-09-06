//https://atcoder.jp/contests/abc202/tasks/abc202_e
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
int n, depth[MAXN], tin[MAXN], tout[MAXN], timer, mxD;

void dfs(int node, int par){
    depth[node] = depth[par] + 1;
    mxD = max(mxD, depth[node]);
    tin[node] = timer++;

    forEC(x,nodes[node].nbr){
        if( x == par ) continue;
        dfs(x,node);
    }

    tout[node] = timer++;
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
        for( int i = 2; i <=n ; i++ ){
            int x;cin>>x;
            nodes[x].nbr.pb(i);
        }
        depth[0] = -1;
        dfs(1,0);

        vvi D(mxD+1);
        for( int i = 1; i <= n ; i++ ){
            int depthNode = depth[i];
            D[depthNode].pb(tin[i]);
        }

        for( int i = 1; i <= mxD ; i++ ){
            sort(all(D[i]));
        }

        int q;cin>>q;
        while(q--){
            int v,d;
            cin>>v>>d;
            int diffDepth = d - depth[v];
            
            if( diffDepth < 0 || d > mxD){
                cout<<"0\n";
                continue;
            }
            int total = upper_bound(all(D[d]), tout[v])- lower_bound( all(D[d]),tin[v]) ;
            cout<<total<<"\n";
        }
    }
    return 0;
}