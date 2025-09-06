//https://atcoder.jp/contests/dp/tasks/dp_h
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

int addM(int a, int b)
{
    return (a + b) % MOD;
}

int solve(vector<vector<int>> &m, int R, int C)
{
    vector<vector<int>> dp(R, vector<int>(C, 0));
    dp[0][0] = 1;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (m[i][j] == 1)
                continue;

            if (i > 0 && m[i - 1][j] == 0)
                dp[i][j] = addM(dp[i][j], dp[i - 1][j]);
            if (j > 0 && m[i][j - 1] == 0)
                dp[i][j] = addM(dp[i][j], dp[i][j - 1]);
        }
    }
    return dp[R - 1][C - 1];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int H, W, val;
    cin >> H >> W;
    vector<vector<int>> m(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            char c;
            cin >> c;
            m[i][j] = c == '#';
        }
    }

    cout << solve(m, H, W) << endl;

    return 0;
}