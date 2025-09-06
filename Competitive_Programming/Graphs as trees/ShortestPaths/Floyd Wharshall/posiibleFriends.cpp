//https://www.spoj.com/problems/SOCIALNE/
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

pair<int, int> floyd(vvi &graph)
{
    pair<int, int> mx(-1, -1);
    int V = graph.size();

    for (int i = 0; i < V; i++)
    {
        int ans = 0;
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] || i == j)
                continue;

            for (int k = 0; k < V; k++)
            {
                if (k == i || k == j)
                    continue;

                if (graph[i][k] && graph[k][j])
                {
                    ans++;
                    break;
                }
            }
        }
        if (ans > mx.first)
        {
            mx.first = ans;
            mx.second = i;
        }
        else if (ans == mx.first)
            mx.second = min(mx.second, i);
    }
    return mx;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    cin.get();
    while (T--)
    {
        string fila0;
        cin >> fila0;
        int M = fila0.size();

        vector<vector<int>> graph(M, vector<int>(M, 0));
        for (int j = 0; j < M; j++)
        {
            graph[0][j] = (fila0[j] == 'Y' ? 1 : 0);
        }
        for (int i = 1; i < M; i++)
        {
            string fila;
            cin >> fila;
            for (int j = 0; j < M; j++)
            {
                graph[i][j] = (fila[j] == 'Y' ? 1 : 0);
            }
        }
        auto ans = floyd(graph);
        cout << ans.second << " " << ans.first << "\n";
        cin.get();
    }
    return 0;
}