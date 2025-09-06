//https://leetcode.com/problems/perfect-squares/description/
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int countWays(int n)
{
    vec dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int sq = j * j;
            if (i - sq < 0)
                break;
            dp[i] = min(dp[i], dp[i - sq] + 1);
        }
    }
    return dp[n];
}

int32_t main()
{
    int n = 12;
    cout << countWays(n) << endl;
    return 0;
}