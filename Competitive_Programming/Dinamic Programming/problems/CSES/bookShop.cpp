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

    int n, x;
    cin >> n >> x;
    vi books(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> books[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vi dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= books[i]; j--)
            dp[j] = max(dp[j], pages[i] + dp[j - books[i]]);
    }

    cout << dp[x] << "\n";

    return 0;
}