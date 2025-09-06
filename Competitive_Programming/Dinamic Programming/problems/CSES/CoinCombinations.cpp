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

vector<int> coins;

int dp(int n, vi &memo)
{
    if (n == 0)
        return 1;

    int &ans = memo[n];
    if (ans != -1)
        return memo[n];

    ans = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        if (n - coins[i] < 0)
            break;
        ans = (ans + dp(n - coins[i], memo)) % MOD;
    }

    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, sum;
    cin >> n >> sum;
    coins.resize(n);
    forN(n, coins);
    sort(coins.begin(), coins.end());
    vi memo(sum + 1, -1);
    cout << dp(sum, memo) << "\n";
    return 0;
}