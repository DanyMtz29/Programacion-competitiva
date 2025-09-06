#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int binarySearch(vector<vector<int>> &events, int index, int n, int endDay)
{
    int i = index;
    int j = n - 1;
    int pos = n;
    while (i <= j)
    {
        int middle = (i + j) / 2;
        if (events[middle][0] > endDay)
        {
            pos = middle;
            j = middle - 1;
        }
        else
        {
            i = middle + 1;
        }
    }

    return pos;
}

int dfs(vector<vector<int>> &events, vector<vector<int>> &dp, int index, int k, int n)
{
    if (index >= n || k == 0)
    {
        return 0;
    }

    if (dp[index][k] != -1)
    {
        return dp[index][k];
    }

    int pos = binarySearch(events, index, n, events[index][1]);
    int sinSeleccionar = dfs(events, dp, index + 1, k, n);
    int Seleccionando = events[index][2] + dfs(events, dp, pos, k - 1, n);
    dp[index][k] = max(sinSeleccionar, Seleccionando);
    return dp[index][k];
}

int solve(vector<vector<int>> &events, int k)
{
    sort(events.begin(), events.end());
    int n = events.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return dfs(events, dp, 0, k, n);
}

int32_t main()
{
    vector<vector<int>> events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    int k = 3;
    cout << "Solve: " << solve(events, k) << endl;
    return 0;
}