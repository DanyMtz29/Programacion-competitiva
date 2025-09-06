#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int,int>
#define INFS 1e18
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

const int MAXN = 1e5+5;

vector<pi> nodes[MAXN];
int n, m;

//Vectores para Dijkstra
int dist[MAXN];
bool vis[MAXN];

void dijkstra(int source){
    //inicializacion
    for( int i = 1; i <=n ; i++ ){
        dist[i] = INFS;
        vis[i] = 0;
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[source] = 0;
    pq.push({0,source});
    
    while(!pq.empty()){
        int u = pq.top().S;
        pq.pop();

        if( vis[u] ) continue;
        vis[u] = 1;

        forEC(v, nodes[u]){
            if( dist[v.S] > dist[u] + v.F ){
                dist[v.S] = dist[u]+v.F;
                pq.push({dist[v.S], v.S});
            }
        }
    }
    for( int i = 1; i <=n ; i++ ){
        cout<<dist[i]<<(i==n?"\n":" ");
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
            int u,v,x;
            cin>>u>>v>>x;
            nodes[u].pb({x,v});
        }

        dijkstra(1);
    }
    return 0;
}