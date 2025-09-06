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
const int MOD = 1e9 + 7;
using namespace std;

void floyd(vvi &graph)
{
    int V = graph.size();
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            if (k == i)
                continue;
            for (int j = 0; j < V; j++)
            {
                if (k == j || i == j)
                    continue;
                if (graph[i][k] != LONG_LONG_MAX && graph[k][j] != LONG_LONG_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vvi graph(n, vi(n, LONG_LONG_MAX));

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = min(graph[v][u], w);
        }

        for (int i = 0; i < n; i++)
            graph[i][i] = 0;

        floyd(graph);

        while (q--)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if (graph[u][v] == LONG_LONG_MAX)
                cout << "-1" << "\n";
            else
                cout << min(graph[u][v], graph[v][u]) << "\n";
        }
    }
    return 0;
}
