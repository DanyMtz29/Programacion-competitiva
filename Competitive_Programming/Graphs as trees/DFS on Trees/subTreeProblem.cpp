#include <bits/stdc++.h>
#define int long long int
using namespace std;

int dfs(int n, int parent, unordered_map<int, vector<int>> &mp, vector<int> &ans)
{
    int count = 1;
    for (int nbr : mp[n])
        if (nbr != parent)
            count += dfs(nbr, n, mp, ans);

    return ans[n] = count;
}

vector<int> solve(int n, vector<vector<int>> &edges, vector<int> &queries)
{
    vector<int> path(n + 1, 0);
    unordered_map<int, vector<int>> mp;
    for (vector<int> &v : edges)
    {
        mp[v[0]].push_back(v[1]);
        mp[v[1]].push_back(v[0]);
    }
    dfs(1, 0, mp, path);

    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++)
        ans[i] = path[queries[i]];

    return ans;
}

int32_t main()
{
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    vector<int> queries = {1, 2, 3, 4, 5};
    vector<int> ans = solve(n, edges, queries);
    cout << "Respuesta" << endl;
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "|"));
    cout << endl;

    return 0;
}