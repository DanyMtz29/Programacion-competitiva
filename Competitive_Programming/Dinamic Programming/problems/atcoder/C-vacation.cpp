//https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> dp(N + 1, vector<int>(3));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c;
    }
    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
    return 0;
}