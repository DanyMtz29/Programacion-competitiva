#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

void fillDP(vector<int> &nums, vector<vector<int>> &dp, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j + i < n; j++)
        {
            dp[j][j + i] = min({abs(nums[j] - nums[j + i]), dp[j + 1][j + i], dp[j][j + i - 1]});
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

    fillDP(arr, dp, n);

    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        cout << dp[l - 1][r - 1] << endl;
    }

    return 0;
}