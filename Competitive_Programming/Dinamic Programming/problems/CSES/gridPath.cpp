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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vvi dp(n, vi(n, 0));
    if (grid[0][0] == '*')
    {
        cout << "0" << "\n";
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
                continue;
            if (i - 1 >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j - 1 >= 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}