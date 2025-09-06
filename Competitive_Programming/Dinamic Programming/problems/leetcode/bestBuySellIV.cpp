//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int solve(int k, vec &prices)
{
    int n = prices.size();

    if (n == 0)
        return 0;

    vec dp(n, 0);
    for (int i = 0; i < k; i++)
    {
        int minimo = -prices[0];
        int maximo = 0;
        for (int j = 1; j < n; j++)
        {
            minimo = max(minimo, dp[j] - prices[j]);
            maximo = max(maximo, minimo + prices[j]);
            dp[j] = maximo;
        }
        cout << "Vector" << endl;
        copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, "|"));
        cout << endl;
    }

    return dp[n - 1];
}

int32_t main()
{
    vec arr = {3, 2, 6, 5, 8, 0, 3};
    cout << "Total: " << solve(2, arr) << endl;
    return 0;
}