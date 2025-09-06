//https://codeforces.com/problemset/problem/295/B
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

int getDist(const vvi &g, const vector<bool> &vis)
{
    int ans = 0;
    int n = (int)g.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j])
                continue;
            ans += g[i][j];
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vvi g(n + 1, vi(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];

    vi x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<bool> vis(n + 1, false);
    vi ans(n, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        int k = x[idx];
        vis[k] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }

        ans[idx] = getDist(g, vis);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << (i + 1 < n ? ' ' : '\n');

    return 0;
}
