//https://leetcode.com/problems/count-all-possible-routes/description/
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

const int MOD = 1e9 + 7;

int dfs(vector<int> &locations, vector<vector<int>> &dp, int index, int end, int fuel)
{
    int n = locations.size();
    if (dp[index][fuel] != -1)
    {
        return dp[index][fuel];
    }

    int total = index == end;

    for (int i = 0; i < n; i++)
    {
        if (i == index)
            continue;

        int res = abs(locations[index] - locations[i]);
        if (fuel - res >= 0)
        {
            total = ((total + dfs(locations, dp, i, end, fuel - res) % MOD) + MOD) % MOD;
        }
    }
    return dp[index][fuel] = total;
}

int solve(vector<int> &locations, int start, int end, int fuel)
{
    int n = locations.size();
    vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
    return dfs(locations, dp, start, end, fuel);
}

int32_t main()
{
    vec arr = {1, 2, 3};
    int start = 0;
    int end = 2;
    int fuel = 40;
    cout << solve(arr, start, end, fuel) << endl;
    return 0;
}