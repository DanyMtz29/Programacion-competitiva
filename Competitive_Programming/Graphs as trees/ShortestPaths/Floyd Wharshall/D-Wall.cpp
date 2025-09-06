//https://atcoder.jp/contests/abc079/tasks/abc079_d
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

const int V = 10;

void floyd(vvi &graph)
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            if (k == i)
                continue;
            for (int j = 0; j < V; j++)
            {
                if (j == i || k == j)
                    continue;
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
        int h, w;
        cin >> h >> w;
        vvi costs(V, vi(V));
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                cin >> costs[i][j];

        floyd(costs);

        int ans = 0;
        for (int i = 0; i < h * w; i++)
        {
            int e;
            cin >> e;
            if (e == -1)
                continue;
            ans += costs[e][1];
        }
        cout << ans << "\n";
    }
    return 0;
}