#include <bits/stdc++.h>
using namespace std;

using lli = long long;
using pii = pair<int, int>;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int max_gcd_path(vector<vector<int>>& grid, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    queue<pii> q;
    q.push({0, 0});
    dp[0][0] = grid[0][0];

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        int curr_gcd = dp[i][j];

        // Movimientos posibles: derecha y abajo
        vector<pii> moves = {{i, j + 1}, {i + 1, j}};

        for (auto [ni, nj] : moves) {
            if (ni < n && nj < m) {
                int new_gcd = gcd(curr_gcd, grid[ni][nj]);
                if (new_gcd > dp[ni][nj]) {  // Solo actualizamos si encontramos un mejor gcd
                    dp[ni][nj] = new_gcd;
                    q.push({ni, nj});
                }
            }
        }
    }

    return dp[n - 1][m - 1];  // Máximo GCD posible al final de la matriz
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        cout << max_gcd_path(grid, n, m) << "\n";
    }

    return 0;
}
