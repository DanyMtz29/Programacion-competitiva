#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vb arr(N);
    forN(N, arr);

    vvb dp(N + 1, vb(N + 1, 0.0));
    dp[0][0] = 1.0;
    for (int i = 1; i <= N; i++)
    {
        double cara = arr[i - 1];
        double cruz = 1 - cara;
        for (int j = 0; j < i; j++)
        {
            dp[i][j] += dp[i - 1][j] * cruz;
            dp[i][j + 1] += dp[i - 1][j] * cara;
        }
    }

    double ans = 0.0;
    for (int i = (N / 2) + 1; i <= N; i++)
        ans += dp[N][i];

    cout << setprecision(10) << fixed;
    cout << ans << endl;

    return 0;
}