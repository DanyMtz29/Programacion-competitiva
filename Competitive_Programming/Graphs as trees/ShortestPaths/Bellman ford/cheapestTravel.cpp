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

int bellmanFord(int V, int src, int dest, vvi edges, int k)
{
    vi dist(V + 1, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i <= k; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            -1; // There is a cicyle
    }
    return dist[dest];
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
    }
    return 0;
}