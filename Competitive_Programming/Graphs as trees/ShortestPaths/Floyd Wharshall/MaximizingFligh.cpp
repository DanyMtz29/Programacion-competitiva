//https://codeforces.com/gym/104555/problem/M
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

int floyd(vvi &graph)
{

    int V = graph.size();

    int cont = 0;
    // Phases, in kth phase we included vertices (1,2,...k) as intermediate vertices
    for (int k = 0; k < V; k++)
    {
        // Iterate over entire 2D Matrix
        for (int i = 0; i < V; i++)
        {
            bool flag = false;
            for (int j = 0; j < V; j++)
            {

                if (k == i || k == j)
                    continue;
                // if vertex k is included, and can we minimise the dist ?
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    return -1;
                else if (graph[i][j] == (graph[i][k] + graph[k][j]))
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                cont++;
        }
    }
    return cont;
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
        int n;
        cin >> n;
        vvi graph(n, vi(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];

        cout << floyd(graph) << "\n";
    }
    return 0;
}