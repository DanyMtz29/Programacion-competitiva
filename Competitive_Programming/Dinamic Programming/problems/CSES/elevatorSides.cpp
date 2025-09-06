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
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define pb push_back
#define F first
#define S second
const int MOD = 1e9 + 7;
using namespace std;
int mx;

string getMask(int n, int N)
{
    string r = "";
    while (N > (n << 1))
    {
        r += "0";
        N /= 2;
    }
    while (n > 0)
    {
        r += (to_string(n % 2));
        n /= 2;
    }
    reverse(all(r));
    return r;
}

void solve(int mask, vector<int> &dp, int sum, int n, int sides, int *a, int w)
{
    cout << "\nSum: " << sum << "\n";
    cout << "Mask: " << getMask(mask, (1LL << n) - 1) << "\n";
    cout << "Sides: " << sides << "\n";
    if (mask == (1LL << n) - 1)
    {
        if (sum != 0)
        {
            cout << "Sides + 1: " << sides << "\n";
            cout << "MX: " << mx << "\n";
            mx = min(mx, sides + 1);
        }
        else
        {
            cout << "sides: " << sides << endl;
            cout << "MX: " << mx << "\n";
            mx = min(mx, sides);
        }
        return;
    }

    if (dp[mask] != -1)
        return;

    for (int i = 0; i < n; i++)
    {
        if (((1LL << i) & mask) > 0)
            continue;
        if (sum + a[i] == w)
            solve(mask | (1LL << i), dp, 0, n, sides + 1, a, w);
        else if (sum + a[i] < w)
            solve(mask | (1LL << i), dp, sum + a[i], n, sides, a, w);
        else
            solve(mask, dp, 0, n, sides + 1, a, w);
    }
    dp[mask] = 1;
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
        int n, w;
        cin >> n >> w;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vi dp((1LL << n) - 1, -1);
        int sum = 0;
        mx = INFS;
        solve(0, dp, sum, n, 0, a, w);
        cout << mx << "\n";
    }
    return 0;
}