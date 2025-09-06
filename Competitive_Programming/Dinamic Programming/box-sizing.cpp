#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int solve_box(vector<vector<int>> &arr)
{
    int sz = arr.size();
    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; });

    vector<int> dp(sz, 1);

    int mx = arr[0][2];
    dp[0] = mx;
    for (int i = 0; i < sz; i++)
    {
        dp[i] = arr[i][2];
        for (int j = 0; j <= i; j++)
        {
            if (arr[j][0] < arr[i][0] && arr[j][1] < arr[i][1] && arr[j][2] < arr[i][2])
            {
                dp[i] = max(dp[i], arr[i][2] + dp[j]);
            }
        }
        mx = max(dp[i], mx);
    }
    return mx;
}

int32_t main()
{
    vector<vector<int>> arr = {{2, 2, 1}, {2, 1, 2}, {3, 2, 3}, {2, 3, 4}, {4, 4, 5}, {2, 2, 8}};
    cout << solve_box(arr) << endl;
    return 0;
}