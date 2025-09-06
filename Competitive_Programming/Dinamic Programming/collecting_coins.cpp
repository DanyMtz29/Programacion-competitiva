#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int dfs(vector<vector<bool>> &visit, vector<vector<int>> &m, int i, int j)
{
    if (visit[i][j])
        return m[i][j];

    int a = 0;
    if (i + 1 < m.size())
    {
        a = dfs(visit, m, i + 1, j);
    }
    int b = 0;
    if (j + 1 < m[0].size())
    {
        b = dfs(visit, m, i, j + 1);
    }

    m[i][j] += max(a, b);

    visit[i][j] = true;
    return m[i][j];
}

int32_t main()
{
    vector<vector<int>> m = {{0, 3, 1, 1}, {2, 0, 0, 4}};
    vector<vector<bool>> visit2(m.size(), vector<bool>(m[0].size(), false));
    cout << dfs(visit2, m, 0, 0) << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << m[i][j] << "|";
        }
        cout << endl;
    }
    return 0;
}