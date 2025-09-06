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

int n,m,k, cont;

int dist[MAXN];
bool trains[MAXN];
bool vis[MAXN];

void dijkstra(int source){
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    dist[source] = 0;
    pq.push( {0,source} );

    for( int i = 2; i <=n ; i++ )
        if( dist[i] != 1e18 )
            pq.push({dist[i], i});

    while( !pq.empty() ){
        int u = pq.top().S;
        pq.pop();

        if( vis[u] ) continue;
        vis[u] = 1;

        forEC(pr, nodes[u]){
            int v = pr.S;
            int c = pr.F;
            if( dist[v] > dist[u] + c ){
                if( dist[v] != 1e18 && trains[v]){
                    trains[v] = 0;
                    cont++;
                }
                dist[v] = dist[u] + c;
                pq.push( {dist[v],v} );
            }else if( dist[v] == dist[u] + c && trains[v]){
                trains[v] = 0;
                cont++;
            }
        }
    }

    // for( int i = 1; i <= n; i++ ){
    //     cout<<dist[i]<<(i==n?"\n":" ");
    // }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for( int i = 0; i < m; i++ ){
            int u,v,x;
            cin>>u>>v>>x;

            nodes[u].pb( {x,v} );
            nodes[v].pb( {x,u} );
        }

        for( int i = 1; i <=n ; i++ ){
            trains[i] = false;
            dist[i] = 1e18;
            vis[i] = 0;
        }

        cont = 0;
        for( int i = 0; i < k; i++ ){
            int city, cost;
            cin>>city>>cost;
            if( dist[city] != 1e18 ) cont++;
            dist[city] = min(dist[city], cost);
            trains[city] = 1;
        }

        dijkstra(1);

        cout<<cont<<"\n";
    }
    return 0;
}