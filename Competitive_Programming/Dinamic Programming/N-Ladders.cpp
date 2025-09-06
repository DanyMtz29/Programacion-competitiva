#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

// O( n^k )
int countWays(int n, int k)
{
    // Base case
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    // Recursive case
    int ans = 0;
    for (int jump = 0; jump <= k; jump++)
    {
        ans += countWays(n - jump, k);
    }
    return ans;
}

// O(n*k)
int countWaysTD(int n, int k, int *dp)
{
    // Base case
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    // Check if state is already computed
    if (dp[n] != 0)
    {
        return dp[n];
    }

    // Recursive case
    int ans = 0;
    for (int jump = 1; jump <= k; jump++)
    {
        ans += countWaysTD(n - jump, k, dp);
    }
    return dp[n] = ans;
}

// O( n*k )
int countWaysBU(int n, int k)
{
    // Iterative approach
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int jump = 0; jump <= k; jump++)
        {
            if (i - jump >= 0)
            {
                dp[i] += dp[i - jump];
            }
        }
    }
    return dp[n];
}

// O( n+k )
int countWaysOp(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }

    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }
    return dp[n];
}

int32_t main()
{
    int n, k;
    cin >> n >> k;
    int dp[n + 1] = {0};
    cout << "countWaysOp: " << countWaysOp(n, k) << endl;
    cout << "countWaysDp: " << countWaysTD(n, k, dp) << endl;
    cout << "countWaysBU: " << countWaysBU(n, k) << endl;

    return 0;
}