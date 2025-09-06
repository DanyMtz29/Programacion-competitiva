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

int dp(int n, vvi &memo, int index, int tam)
{
    if (n == 0)
        return 1;

    if (index == tam)
        return 0;

    int &ans = memo[index][n];
    if (ans != -1)
        return ans;

    ans = 0;
    if (n - coins[index] >= 0)
        ans = (ans + dp(n - coins[index], memo, index, tam)) % MOD;

    ans = (ans + dp(n, memo, index + 1, tam)) % MOD;

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
    vvi memo(n, vi(sum + 1, -1));
    cout << dp(sum, memo, 0, coins.size()) << "\n";
    return 0;
}