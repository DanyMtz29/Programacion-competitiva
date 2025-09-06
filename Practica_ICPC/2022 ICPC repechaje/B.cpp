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

int dp(vvi &matrix, int iTarget, int jTarget, int i, int j, vvi &vis, int par)
{
    // cout << "llega con i: " << i << ", j: " << j << endl;
    if (i < 0 || i == matrix.size() || j < 0 || j == matrix[0].size())
        return INT_MAX;
    if (vis[i][j] == -2)
        return INT_MAX;
    if (vis[i][j] != -1)
        return vis[i][j] + par != matrix[i][j];
    if (i == iTarget && j == jTarget)
        return par != matrix[i][j];
    vis[i][j] = -2;
    int ans = par != matrix[i][j];
    int q1 = dp(matrix, iTarget, jTarget, i + 1, j, vis, matrix[i][j]);
    int q2 = dp(matrix, iTarget, jTarget, i - 1, j, vis, matrix[i][j]);
    int q3 = dp(matrix, iTarget, jTarget, i, j + 1, vis, matrix[i][j]);
    int q4 = dp(matrix, iTarget, jTarget, i, j - 1, vis, matrix[i][j]);
    int q = min({q1, q2, q3, q4});
    vis[i][j] = q;
    // ans += q;
    // return vis[i][j] = ans;
    return q + ans;
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
        int n, m, s1, s2, e1, e2;
        cin >> n >> m >> s1 >> e1 >> s2 >> e2;
        vvi matrix(n, vi(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];

        vvi vis(n, vi(m, -1));
        cout << dp(matrix, s2 - 1, e2 - 1, s1 - 1, e1 - 1, vis, matrix[s1 - 1][e1 - 1]) << "\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << vis[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}