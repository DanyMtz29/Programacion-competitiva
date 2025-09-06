#include <bits/stdc++.h>
#define int long long int
#define umGraph unordered_map<int, vector<int>>
using namespace std;

vector<int> profundidad;
vector<vector<int>> padres;
umGraph graph;
const int M = 20;

void dfs(int curr, int parent)
{
    profundidad[curr] = profundidad[parent] + 1;

    padres[curr][0] = parent;
    for (int j = 1; j < M; j++)
        padres[curr][j] = padres[padres[curr][j - 1]][j - 1];
    for (int nbr : graph[curr])
    {
        if (nbr == parent)
            continue;
        dfs(nbr, curr);
    }
}

int LCA(int u, int v)
{
    if (u == v)
        return u;
    if (profundidad[u] < profundidad[v])
        swap(u, v);

    int diff = profundidad[u] - profundidad[v];
    for (int j = M - 1; j >= 0; j--)
    {
        if ((diff >> j) & 1)
            u = padres[u][j];
    }

    for (int j = M - 1; j >= 0; j--)
    {
        if (padres[u][j] != padres[v][j])
        {
            u = padres[u][j];
            v = padres[v][j];
        }
    }

    if (u == v)
        return u;
    if (padres[u][0] == 0)
        return u;
    return padres[u][0];
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        while (m-- > 0)
        {
            int nbr;
            cin >> nbr;
            graph[i].push_back(nbr);
            graph[nbr].push_back(i);
        }
    }

    profundidad.resize(n + 1);
    padres.resize(n + 1, vector<int>(M));

    dfs(1, 0);

    int Q;
    cin >> Q;
    while (Q--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    int t = 1;
    while (t <= T)
    {
        cout << "Case " << t++ << ":" << endl;
        solve();
        padres.clear();
        graph.clear();
        profundidad.clear();
    }
    return 0;
}