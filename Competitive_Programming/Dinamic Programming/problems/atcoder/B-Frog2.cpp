//https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j <= i + K && j < N; j++)
        {
            dp[j] = min(dp[j], abs(arr[i] - arr[j]) + dp[i]);
        }
    }
    cout << "" << endl;

    cout << dp[N - 1] << endl;

    return 0;
}
