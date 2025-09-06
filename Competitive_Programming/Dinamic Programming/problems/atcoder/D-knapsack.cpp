//https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;
        arr[i] = make_pair(w, v);
    }

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (dp[i - 1][j] == -1)
                continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j + arr[i - 1].first <= W)
            {
                dp[i][j + arr[i - 1].first] = max(dp[i - 1][j] + arr[i - 1].second, dp[i - 1][j + arr[i - 1].first]);
            }
        }
    }

    int ans = 0;
    for (int i = W; i >= 0; i--)
    {
        if (dp[N][i] != -1)
        {
            ans = max(ans, dp[N][i]);
        }
    }
    cout << ans << endl;

    return 0;
}