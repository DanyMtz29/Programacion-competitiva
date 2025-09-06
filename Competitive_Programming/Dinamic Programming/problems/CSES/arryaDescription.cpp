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

int m;
vvi dp;

int addm(int a, int b)
{
    return (a + b) % MOD;
}

int solve(int index, int n, int prev, vi &a)
{
    if (index == n)
        return 1;

    if (dp[prev][index] != -1)
        return dp[prev][index];

    int ans = 0;
    if (a[index] != 0)
    {
        if (abs(a[index] - prev) <= 1)
            ans = addm(ans, solve(index + 1, n, a[index], a));
        else
            return 0;
    }
    else
    {
        if (prev == 1)
            ans = addm(ans, addm(solve(index + 1, n, 1, a), (m >= 2 ? solve(index + 1, n, 2, a) : 0)));
        else
            ans = addm(solve(index + 1, n, prev - 1, a), addm(solve(index + 1, n, prev, a), (m >= prev + 1 ? solve(index + 1, n, prev + 1, a) : 0)));
        // return solve(index + 1, n, prev - 1, a) + solve(index + 1, n, prev, a) + (m >= prev + 1 ? solve(index + 1, n, prev + 1, a) : 0);
    }
    return dp[prev][index] = ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n >> m;
    vi a(n);
    forN(n, a);

    int ans = 0;
    dp.resize(m + 1, vi(n + 1, -1));
    if (a[0] != 0)
        ans = addm(ans, solve(1, n, a[0], a));
    else
        for (int i = 1; i <= m; i++)
            ans = addm(ans, solve(1, n, i, a));

    cout << ans << endl;
    return 0;
}