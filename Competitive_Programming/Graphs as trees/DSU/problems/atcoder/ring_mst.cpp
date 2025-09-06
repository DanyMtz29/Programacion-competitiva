//https://atcoder.jp/contests/abc210/tasks/abc210_e
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
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vvi costs(m, vi(2));
        for (int i = 0; i < m; i++)
        {
            int u, c;
            cin >> u >> c;
            costs[i] = {c, u};
        }
        vi component(m + 1);
        component[0] = n;
        sort(costs.begin(), costs.end());
        for (int i = 1; i <= m; i++)
            component[i] = __gcd(costs[i - 1][1], component[i - 1]);

        if (component[m] != 1)
        {
            cout << "-1" << "\n";
            return 0;
        }

        int ans = 0;
        for (int i = 1; i <= m; i++)
            ans += (component[i - 1] - component[i]) * costs[i - 1][0];
        cout << ans << "\n";
    }
    return 0;
}