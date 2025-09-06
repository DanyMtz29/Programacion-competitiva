#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

// Top down
int min_jumps(vec &arr, vec &dp, int n, int index)
{
    if (index == n - 1)
        return 0;
    if (index >= n)
        return INT_MAX;
    if (dp[index] != 0)
        return dp[index];

    // Assume
    int steps = INT_MAX;
    int max_jump = arr[index];
    for (int jump = 1; jump <= max_jump; jump++)
    {
        int subProblem = min_jumps(arr, dp, n, jump + index);
        if (subProblem != INT_MAX)
            steps = min(steps, subProblem + 1);
    }
    return dp[index] = steps;
}

// Bottom up
int min_jumpsBU(vec &arr, int n)
{
    vec dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int max_jump = arr[i];
        for (int jump = 1; jump <= max_jump && (i + jump) < n; jump++)
        {
            dp[i + jump] = min(dp[i + jump], dp[i] + 1);
        }
    }
    return dp[n - 1];
}

int32_t main()
{
    // vec arr = {3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    // vec arr = {2, 3, 1, 1, 4};
    vec arr = {2, 3, 0, 1, 4};
    int n = arr.size();
    // Create a array for dp
    vec dp(n + 1, 0);

    cout << "min jumpsTD: " << min_jumps(arr, dp, n, 0) << endl;
    cout << "min jumpsBU: " << min_jumpsBU(arr, n) << endl;
    return 0;
}