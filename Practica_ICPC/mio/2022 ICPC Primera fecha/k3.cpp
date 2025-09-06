#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

const int N = 50001;

int query(int n, vec &dp, vec &arr)
{
    if (dp[n] != INT_MAX)
    {
        return dp[n];
    }

    int sz = arr.size();
    for (int i = 0; i < sz; i++)
    {
        if (n % arr[i] == 0)
        {
            return dp[n] = 0;
        }
        else if (arr[i] < n)
        {
            int aux = arr[i];
            while (aux < n)
            {
                dp[n] = min({dp[n], query(n - arr[i], dp, arr)});
                aux += aux;
            }
        }
        else
        {
            return dp[n] = min(dp[n], arr[i] - n);
        }
    }
    return dp[n];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k, p;
    cin >> k >> p;
    vec arr(p);
    for (int i = 0; i < p; i++)
    {
        cin >> arr[i];
    }
    vec dp(N, INT_MAX);
    dp[0] = 0;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < k; i++)
    {
        int val;
        cin >> val;
        cout << query(val, dp, arr) << endl;
    }

    return 0;
}