//https://atcoder.jp/contests/abc143/tasks/abc143_e
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

void floyd(vvi &m, int V)
{
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
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
        int V, E, L;
        cin >> V >> E >> L;
        vvi dist(V + 1, vi(V + 1, INT_MAX));

        for (int i = 1; i <= V; i++)
            dist[i][i] = 0;

        for (int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = w;
            dist[v][u] = w;
        }

        floyd(dist, V);

        vvi newDist(V + 1, vi(V + 1, INT_MAX));
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (i == j)
                    newDist[i][j] = 0;
                else if (dist[i][j] <= L)
                    newDist[i][j] = 1;
            }
        }

        floyd(newDist, V);

        int Q;
        cin >> Q;

        while (Q--)
        {
            int src, dest;
            cin >> src >> dest;
            if (newDist[src][dest] == INT_MAX)
                cout << "-1" << "\n";
            else
                cout << newDist[src][dest] - 1 << "\n";
        }
    }
    return 0;
}