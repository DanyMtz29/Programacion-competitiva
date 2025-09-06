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
    vector<int> nbr;
};

int n;
node nodes[MAXN];

//Variables para el algoritmo
int sz;
int subtree_sz[MAXN], vis[MAXN];

void dfs(int x, int p){
    sz++;
    subtree_sz[x] = 1;
    for( auto const& y: nodes[x].nbr ){
        if( y != p && !vis[y]){
            dfs( y, x);
            subtree_sz[x]+=subtree_sz[y];
        }
    }
}

int getCentroid(int x, int p){
    bool is_centroid = true;
    int heavy_child = -1;
    for( const auto& y : nodes[x].nbr ){
        if( y != p  && !vis[y]){
            if( subtree_sz[y] > sz/2 )
                is_centroid = false;
            if( heavy_child == -1 || subtree_sz[y] > subtree_sz[heavy_child] )
                heavy_child = y;
        }
    }

    return (is_centroid && sz - subtree_sz[x] <= sz/2) ? x : getCentroid(heavy_child, x);
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
        for( int i = 1; i <= n; i++ ){
            vis[i]=0;
        }
        for( int i = 0; i < n-1; i++ ){
            int u,v;cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }

        sz = 0;
        dfs(1,-1);
        cout<<getCentroid(1,-1)<<"\n";
    }
    return 0;
}