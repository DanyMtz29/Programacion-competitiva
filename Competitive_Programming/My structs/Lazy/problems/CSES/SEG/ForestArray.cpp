#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Q;
    cin >> n >> Q;

    vector<vector<long long>> a(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            char c;
            cin >> c;
            a[i][j] = c == '*';
        }

    vector<vector<long long>> ps(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        long long fila = 0;
        for (int j = 1; j <= n; ++j)
        {
            fila += a[i][j];
            ps[i][j] = ps[i - 1][j] + fila;
        }
    }
    while (Q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long ans = ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
    return 0;
}