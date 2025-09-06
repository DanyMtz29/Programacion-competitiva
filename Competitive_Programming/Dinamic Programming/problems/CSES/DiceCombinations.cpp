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

int addM(int a, int b)
{
    return (a + b) % MOD;
}
int resM(int a, int b)
{
    return (((a - b) % MOD) + MOD) % MOD;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> dp(max(n + 1, 8ll));

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    dp[7] = 63;
    if (n <= 7)
        cout << dp[n] << "\n";
    else
    {
        for (int i = 8; i <= n; i++)
        {
            dp[i] = addM(dp[i - 1], resM(dp[i - 1], dp[i - 7]));
            // dp[i] = (dp[i - 1] + (dp[i - 1] - dp[i - 7]) % MOD) % MOD;
        }
        cout << dp[n] << "\n";
    }

    return 0;
}
