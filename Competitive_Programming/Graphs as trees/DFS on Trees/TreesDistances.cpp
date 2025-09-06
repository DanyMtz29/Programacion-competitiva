#include <bits/stdc++.h>
#define int long long int
using namespace std;

int distMax;
int rootMax;

void dfs(int curr, int parent, unordered_map<int, vector<int>> &mp, int path, vector<int> &dist)
{
    dist[curr - 1] = max(dist[curr - 1], path);
    if (path > distMax)
    {
        distMax = path;
        rootMax = curr;
    }
    for (int nbr : mp[curr])
    {
        if (nbr == parent)
            continue;

        dfs(nbr, curr, mp, path + 1, dist);
    }
}

void solve(int n, unordered_map<int, vector<int>> mp)
{

    vector<int> ans(n, 0);
    dfs(1, 0, mp, 0, ans);
    dfs(rootMax, 0, mp, 0, ans);
    dfs(rootMax, 0, mp, 0, ans);

    for (int i = 0; i < n - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[n - 1] << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n - 1; i++)
    {
        int src, dest;
        cin >> src >> dest;
        mp[src].push_back(dest);
        mp[dest].push_back(src);
    }

    solve(n, mp);
    return 0;
}