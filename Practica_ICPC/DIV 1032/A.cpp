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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n, pos;
        cin >> n >> pos;
        int mn = 101, mx = 0;
        for (int i = 0; i < n; i++)
        {
            int e;
            cin >> e;
            mn = min(mn, e);
            mx = max(mx, e);
        }
        int ans = 0;
        if (pos >= mx)
            ans = pos - mn;
        else if (pos <= mn)
            ans = mx - pos;
        else
        {
            if (pos - mn > mx - pos)
                ans = (mx - pos) * 2 + pos - mn;
            else
                ans = (pos - mn) * 2 + mx - pos;
        }
        cout << ans << "\n";
    }
    return 0;
}