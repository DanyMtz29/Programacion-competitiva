//https://cses.fi/problemset/task/1681
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;
vvi graph(N);
vi visited(N);
vi dp(N);

int addM(int a, int b)
{
    return (a + b) % MOD;
}

int dfs(int cur)
{
    if (cur == 1)
        return 1;

    visited[cur] = 1;
    int cont = 0;
    for (auto x : graph[cur])
        if (visited[x] == 0)
            cont = addM(cont, dfs(x));
        else if (visited[x] == 2)
            cont = addM(cont, dp[x]);

    visited[cur] = 2;
    return dp[cur] = cont % MOD;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[y].push_back(x);
    }
    cout << dfs(n) << "\n";

    return 0;
}