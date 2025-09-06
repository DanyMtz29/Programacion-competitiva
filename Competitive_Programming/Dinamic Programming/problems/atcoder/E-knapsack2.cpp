//https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
#define int long long int

using namespace std;

const int MAXV = 1e5 + 1;

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

    vector<vector<int>> dp(N + 1, vector<int>(MAXV, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < MAXV; j++)
        {
            if (dp[i - 1][j] == -1)
                continue;

            int w = arr[i - 1].first;
            int v = arr[i - 1].second;
            dp[i][j] = (dp[i][j] != -1) ? min(dp[i - 1][j], dp[i][j]) : dp[i - 1][j];

            if (dp[i - 1][j] + w <= W)
            {
                dp[i][j + v] = (dp[i][j + v] != -1) ? min(dp[i][j + v], dp[i - 1][j] + w) : dp[i - 1][j] + w;
            }
        }
    }

    for (int i = MAXV - 1; i >= 0; i--)
    {
        if (dp[N][i] != -1)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}