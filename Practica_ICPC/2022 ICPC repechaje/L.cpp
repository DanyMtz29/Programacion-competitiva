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
#define umiv unordered_map<int, vi>
#define INFS 1e9
#define INFI -1e9
const int MOD = 1e9 + 7;
using namespace std;

pair<bool, int> dfs(vi *mp, int src, int target, int par)
{
    int ans = 0;

    bool flag = false;
    for (auto nbr : mp[src])
    {
        if (nbr == par)
            continue;
        if (nbr == target)
            return {true, 1};
        else
        {
            auto p = dfs(mp, nbr, target, src);
            if (p.first)
                flag = true;
            ans += 1 + p.second;
        }
    }
    // cout << "Source: " << src << ", ans: " << ans << "\n";
    if (flag)
        return {flag, ans};
    else
        return {flag, ans + 1};
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
        int n, target;
        cin >> n >> target;
        vector<int> mp[n + 1];
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        cout << dfs(mp, 1, target, -1).second << "\n";
    }
    return 0;
}