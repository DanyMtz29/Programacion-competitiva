//https://codeforces.com/problemset/problem/1324/E
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int solve(int n, vec &arr, int h, int l, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(h + 1));

    for (int i = 1; i < h; i++)
    {
        dp[0][i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int hr = 0; hr < h; hr++)
        {
            dp[i + 1][hr] = -1;
        }
        for (int hr = 0; hr < h; hr++)
        {
            if (dp[i][hr] == -1)
            {
                continue;
            }
            int h1 = (hr + arr[i + 1] - 1 + h) % h;
            int h2 = (hr + arr[i + 1]) % h;

            dp[i + 1][h1] = max(dp[i + 1][h1], dp[i][hr] + (l <= h1 && h1 <= r));
            dp[i + 1][h2] = max(dp[i + 1][h2], dp[i][hr] + (l <= h2 && h2 <= r));
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        if (dp[n][i] != -1)
        {
            ans = max(ans, dp[n][i]);
        }
    }
    return ans;
}

int32_t main()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vec arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << "Solve: " << solve(n, arr, h, l, r) << endl;

    return 0;
}