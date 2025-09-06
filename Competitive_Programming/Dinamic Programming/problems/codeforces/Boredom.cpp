//https://codeforces.com/problemset/problem/455/A
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

// 1 3 5 1 5 6 3

int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vec arr(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        arr[i] = element;
        mp[element]++;
    }

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    int sz = arr.size();

    vec dp(sz);

    int mx = INT_MIN;

    for (int i = 0; i < sz; i++)
    {
        dp[i] = (mp[arr[i]] * arr[i]);
        if (i > 0)
        {
            if (arr[i - 1] + 1 < arr[i])
            {
                dp[i] += dp[i - 1];
                mx = max(mx, dp[i]);
            }
            else
            {
                if (i > 1)
                    dp[i] += dp[i - 2];
            }
            dp[i] = max(dp[i], dp[i - 1]);
        }
        mx = max(dp[i], mx);
    }
    cout << "vector" << endl;
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, "|"));
    cout << endl;
    cout << "DP" << endl;
    copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, "|"));
    cout << "" << endl;

    cout << mx << endl;

    return 0;
}