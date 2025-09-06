//https://atcoder.jp/contests/dp/tasks/dp_g
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int dfs(unordered_map<int, vector<int>> &graph, vector<int> &dp, int curr)
{
    int ans = 0;
    for (int nbr : graph[curr])
    {
        if (dp[nbr] == -1)
            dfs(graph, dp, nbr);

        ans = max(ans, dp[nbr] + 1);
    }

    return dp[curr] = ans;
}

int solve(int N, int M)
{
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < M; i++)
    {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
    }

    vector<int> dp(N + 1, -1);
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dp[i] == -1)
            dfs(graph, dp, i);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    cout << solve(N, M);
    return 0;
}