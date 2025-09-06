//https://atcoder.jp/contests/dp/tasks/dp_a
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
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        if (i + 1 < N)
            dp[i + 1] = min(dp[i + 1], abs(arr[i] - arr[i + 1]) + dp[i]);
        if (i + 2 < N)
            dp[i + 2] = min(dp[i + 2], abs(arr[i] - arr[i + 2]) + dp[i]);
    }

    cout << dp[N - 1] << endl;

    return 0;
}