#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int, int>
#define INFS 1e9
#define INFI -1e9
#define F first
#define S second
const int MOD = 1e9 + 7;
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int n)
    {
        this->V = n;
        l = new list<pair<int, int>>[V + 1];
    }

    void addEdge(int u, int v, int w)
    {
        l[u].push_back({v, w});
    }

    int dijkstra(int src)
    {
        vi dist(V + 1, INT_MAX);
        set<pair<int, int>> s;

        s.insert({0, src});

        int i = 100;
        while (!s.empty() && i-- > 0)
        {
            auto it = s.begin();
            int node = it->S;
            int distCurr = it->F;
            // cout << "Node: " << node << endl;
            // cout << "Dist: " << distCurr << "\n";
            s.erase(it);

            for (auto nbrPair : l[node])
            {

                int nbr = nbrPair.F;
                int wNbr = nbrPair.S;

                if (distCurr + wNbr < dist[nbr])
                {
                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end())
                        s.erase({dist[nbr], nbr});

                    dist[nbr] = distCurr + wNbr;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        return dist[src] == INT_MAX ? -1 : dist[src];
    }

    vi solve()
    {
        vi ans(V);
        for (int i = 0; i < V; i++)
        {
            ans[i] = this->dijkstra(i + 1);
        }
        return ans;
        // return vi(this->dijkstra(1));
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        Graph g(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        }

        vi ans = g.solve();
        for (auto x : ans)
            cout << x << "\n";
    }
    return 0;
}