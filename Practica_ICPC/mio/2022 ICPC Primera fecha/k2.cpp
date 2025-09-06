#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

const int N = 50001;

vector<int> solve(int k, int p, vec &bags)
{
    // vector<int> bags(p);

    const int MAX_N = 50000;
    const int MAX_R = 100;
    int limit = MAX_N + MAX_R; // 50    ,100

    vector<bool> posible(limit + 1, false);
    posible[0] = true;

    for (int r : bags)
    {
        for (int x = 0; x + r <= limit; x++)
        {
            if (posible[x])
            {
                posible[x + r] = true;
            }
        }
    }

    vector<int> siguiente(limit + 1, -1);
    int last = -1;
    for (int x = limit; x >= 0; x--)
    {
        if (posible[x])
            last = x;
        siguiente[x] = last;
    }

    return siguiente;
}

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
    vector<int> siguiente = solve(k, p, arr);
    vec dp(N, INT_MAX);
    dp[0] = 0;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < k; i++)
    {
        int val;
        cin >> val;
        cout << "Query mia: " << query(val, dp, arr) << endl;
        cout << "Query chat: " << siguiente[val] - val << endl;
    }

    return 0;
}