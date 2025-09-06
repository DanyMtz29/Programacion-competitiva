#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int dfs(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp, int mask1, int mask2, int allmask, int n, int sum)
{
    if (mask1 == 0)
    {
        return sum;
    }

    if (dp[mask1][mask2] != -1)
        return dp[mask1][mask2];

    int total = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if ((mask1 & (1LL << i)) == 0)
            continue;

        // mask1 &= (~(1 << i));
        cout << "Usando nums1[" << i << "]: " << nums1[i] << endl;
        for (int j = 0; j < n; j++)
        {
            if ((mask2 & (1LL << j)) == 0)
                continue;

            cout << "Mask1: " << mask1 << ", mask2: " << mask2 << endl;
            cout << "Usando numsj[" << j << "]: " << nums2[j] << endl;
            // mask2 &= (~(1 << j));
            total = min(dfs(nums1, nums2, dp, mask1 & (~(1LL << i)), mask2 & (~(1LL << j)), allmask, n, nums1[i] ^ nums2[j]), total);
            // cout << "Mask1: " << mask1 << ", mask2: " << mask2 << endl;
            cout << "total: " << total << endl;

            cout << "" << endl;
        }
    }
    return dp[mask1][mask2] = total + sum;
}

int solve(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp((1LL << n), vector<int>((1 << n), -1));
    int allMask = (1LL << n);
    int ret = dfs(nums1, nums2, dp, allMask - 1, allMask - 1, allMask - 1, n, 0);
    // cout << "DPP" << endl;
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     cout << "" << endl;
    //     for (int j = 0; j < dp[i].size(); j++)
    //     {
    //         cout << "Mask1[" << i << "][" << j << "]: " << dp[i][j] << endl;
    //     }
    // }

    // cout << "Dp de 1 y 5: " << dp[3][0] << endl;

    return ret;
}

int32_t main()
{
    vector<int> nums1 = {1, 0, 3};
    vector<int> nums2 = {5, 3, 4};
    cout << solve(nums1, nums2) << endl;
    return 0;
}