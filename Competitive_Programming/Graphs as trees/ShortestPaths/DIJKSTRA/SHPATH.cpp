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

const int MAXN = 10005;

vector<pi> nodes[MAXN];
int n;
unordered_map<string,int> mp;

int dist[MAXN];
bool vis[MAXN];

int dijkstra(int source, int dest){
    for( int i = 1; i <= n; i++ ){
        dist[i] = 1e18;
        vis[i] = 0;
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[source] = 0;
    pq.push( {0,source} );

    while( !pq.empty() ){
        int u = pq.top().S;
        pq.pop();

        if( vis[u] ) continue;
        if( u == dest ) return dist[u];
        vis[u] = 1;

        forEC(v, nodes[u]){
            if( dist[v.S] > dist[u] + v.F ){
                dist[v.S] = dist[u] + v.F;
                pq.push( {dist[v.S], v.S} );
            }
        }
    }
    return -1;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--){
        cin>>n;
        mp.clear();
        for( int i = 1; i <= n; i++ ){
            nodes[i].clear();
            string name;
            int nbr;
            cin>>name;
            cin>>nbr;

            mp[name] = i;
            for( int j = 0; j < nbr; j++ ){
                int v,c;
                cin>>v>>c;
                nodes[i].pb({c,v});
            }
        }

        int paths;
        cin>>paths;
        while( paths-- ){
            string source, dest;
            cin>>source>>dest;
            cout<<dijkstra(mp[source], mp[dest])<<"\n";
        }
    }
    return 0;
}