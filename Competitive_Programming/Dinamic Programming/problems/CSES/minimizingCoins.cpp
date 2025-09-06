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
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    forN(n, coins);
    sort(coins.begin(), coins.end());
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            else
                break;
        }
    }
    if (dp[x] == INT_MAX)
        cout << "-1" << "\n";
    else
        cout << dp[x] << "\n";
    return 0;
}