//https://leetcode.com/problems/cherry-pickup-ii/description/
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int dfs(int row, int col1, int col2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (col1 < 0 || col2 < 0 || col1 >= m || col2 >= m)
    {
        return -1e8;
    }

    if (row == n - 1)
    {
        if (col1 == col2) // same position
            return grid[row][col2];
        else
            return grid[row][col1] + grid[row][col2];
    }

    if (dp[row][col1][col2] != -1)
        return dp[row][col1][col2];

    int maxRow = INT_MIN;
    for (int incCol1 = -1; incCol1 <= 1; incCol1++)
    {
        for (int incCol2 = -1; incCol2 <= 1; incCol2++)
        {
            int val = 0;
            if (col1 == col2)
                val = grid[row][col1];
            else
                val = grid[row][col1] + grid[row][col2];
            val += dfs(row + 1, col1 + incCol1, col2 + incCol2, n, m, grid, dp);
            maxRow = max(maxRow, val);
        }
    }
    return dp[row][col1][col2] = maxRow;
}

int32_t main()
{
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};

    int n = grid.size(), m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    cout << dfs(0, 0, m - 1, n, m, grid, dp) << endl;
    /*
        for (int i = 0; i < n; i++)
        {
            cout << "Renglon " << (i + 1) << endl;
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    cout << dp[i][j][k] << "|";
                }
                cout << endl;
            }
        }
    */

    return 0;
}