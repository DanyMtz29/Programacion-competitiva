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
 
const int MAXN = 50005;
 
struct node{
    vector<int> nbr;
};
 
int n,k, ans;
node nodes[MAXN];
 
//Variables para el algoritmo
int sz;
int subtree_sz[MAXN], vis[MAXN];

unordered_map<int,int> mp,aux;
 
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

void dfs2(int x, int p, int dist){
  if(dist > k) return;
  if( mp.count(k-dist)){
    ans += mp[k-dist];
  }

  for( const auto& y: nodes[x].nbr ){
    if( y != p && !vis[y] ){
      dfs2(y,x,dist+1);
    }
  }
  aux[dist]++;
}

int decompose(int x, int p){
  sz = 0;
  dfs(x,-1);
  int cur_centroid = getCentroid(x, -1);
  mp.clear();
  mp[0] = 1;
  //dfs2(cur_centroid, -1, 0);
  vis[cur_centroid] = true;
  for( const auto& y: nodes[cur_centroid].nbr ){
    if(!vis[y]){
        aux.clear();
        dfs2(y,cur_centroid,1);
        for( const auto& pr: aux )
            mp[pr.F] += pr.S;
    }
  }
  for( const auto& y : nodes[cur_centroid].nbr ){
    if( !vis[y] ){
      decompose(y,x);
    }
  }
  return cur_centroid;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cin>>n>>k;
        for( int i = 1; i <= n; i++ ){
            vis[i]=0;
        }
        for( int i = 0; i < n-1; i++ ){
            int u,v;cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }
        ans = 0;
        decompose(1,-1);
        cout<<ans<<"\n";
    }
    return 0;
}
/*
10 3
1 2
1 3
2 4
2 5
4 10
5 9
3 6
3 7 
7 8
*/