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

int dp(string &a, string &b, int i, int j, vvi &memo)
{
    if (i == a.length() && j == b.length())
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    if (i == a.length())
        return 1 + dp(a, b, i, j + 1, memo);
    if (j == b.length())
        return 1 + dp(a, b, i + 1, j, memo);

    int ans = INT_MAX;
    if (a[i] == b[j])
        ans = min(ans, dp(a, b, i + 1, j + 1, memo));
    else
    {
        ans = min(ans, 1 + dp(a, b, i + 1, j, memo));     // Eliminar
        ans = min(ans, 1 + dp(a, b, i, j + 1, memo));     // Aniadir
        ans = min(ans, 1 + dp(a, b, i + 1, j + 1, memo)); // Intercambiar
    }
    return memo[i][j] = ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        string a, b;
        cin >> a >> b;
        vvi memo(a.length() + 1, vi(b.length() + 1, -1));
        cout << dp(a, b, 0, 0, memo) << "\n";
    }
    return 0;
}