#include <bits/stdc++.h>
// #define int long long int
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
const int MOD = 1e9 + 7;
using namespace std;

int dijkstra(int src, int end, int totalNodes, list<pair<int, int>> *graph)
{
    // Estructuras a utilizar
    vi dist(totalNodes, INT_MAX);
    set<pair<int, int>> s;

    // 1. Init
    dist[0] = 0;
    // Weight-Source
    s.insert({0, src});

    while (s.size())
    {
        auto it = s.begin();
        int node = it->second;
        int distCurr = it->first;
        s.erase(it); // pop

        // itarete over the nbrs of node
        for (auto nbrPair : graph[node])
        {
            int nbr = nbrPair.first;
            int currentWeight = nbrPair.second;

            if (currentWeight + distCurr < dist[nbr])
            {

                // Si ya se encuentra el nodo con un peso mayor
                // se elimina
                auto f = s.find({dist[nbr], nbr});
                if (f != s.end())
                    s.erase(f);

                // Se agrega el nodo con peso menor nuevamente
                // a la estructura
                dist[nbr] = currentWeight + distCurr;
                s.insert({dist[nbr], nbr});
            }
        }
    }
    for (int i = 0; i < totalNodes; i++)
        cout << "Nodee i: " << i << ", Dist: " << dist[i] << "\n";

    return dist[end];
}

int32_t main()
{
    int n;
    cin >> n;
    list<pair<int, int>> *graph = new list<pair<int, int>>[n];
    for (int i = 0; i < 6; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout << dijkstra(0, 4, n, graph) << "\n";

    delete graph;
    return 0;
}