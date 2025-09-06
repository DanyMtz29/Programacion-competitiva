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

const int MAXN = 100005;

vector<pi> nodes[MAXN];
int n, m, par[MAXN];

//Vectores para Dijkstra
int dist[MAXN];
bool vis[MAXN];

void dijkstra(int source, int dest){
    //inicializacion
    for( int i = 1; i <=n ; i++ ){
        dist[i] = 1e18;
        vis[i] = 0;
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[source] = 0;
    par[source] = -1;
    pq.push({0,source});
    
    while(!pq.empty()){
        int u = pq.top().S;
        pq.pop();

        if( vis[u] ) continue;
        vis[u] = 1;

        forEC(v, nodes[u]){
            if( dist[v.S] > dist[u] + v.F ){
                dist[v.S] = dist[u]+v.F;
                par[v.S] = u;
                pq.push({dist[v.S], v.S});
            }
        }
    }
    if( dist[dest] == 1e18 ){
        cout<<"-1\n";
        return;
    }
    stack<int> ans;
    ans.push(dest);
    int p = par[dest];
    while( p!=-1 ){
        ans.push(p);
        p = par[p];
    }
    while(!ans.empty()){
        cout<<ans.top()<<(ans.size()==1?"\n":" ");
        ans.pop();
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
        cin>>n>>m;
        for( int i = 0; i < m; i++ ){
            int u,v,c;
            cin>>u>>v>>c;
            nodes[u].pb({c,v});
            nodes[v].pb({c,u});
        }
        dijkstra(1,n);
    }
    return 0;
}