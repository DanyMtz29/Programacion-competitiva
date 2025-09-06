//https://codeforces.com/problemset/problem/2086/D
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

const int N = 5e5 + 1;
int fact[N];

const int MOD = 998244353;

int mulm(int a, int b)
{
    return (a * b) % MOD;
}

int pwrm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = mulm(res, a);
        a = mulm(a, a);
        b /= 2;
    }
    return res;
}

int inv(int x)
{
    return pwrm(x, MOD - 2);
}

void factorials()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = mulm(fact[i - 1], i);
    }
}

int nPPk(int comb, int even, int odd, vi &arr)
{
    int den = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        den = mulm(den, fact[arr[i]]);
    }
    return mulm(comb, mulm(fact[even], mulm(fact[odd], inv(den))));
}

int32_t main()
{

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T;
    cin >> T;
    factorials();
    while (T--)
    {
        int l = 26;
        vi arr(l);
        int n = 0;
        int mx = INT_MIN;
        for (int i = 0; i < l; i++)
        {
            cin >> arr[i];
            n += arr[i];
            mx = max(mx, arr[i]);
        }
        int even = (n + 1) / 2;
        int odd = n / 2;
        vvi dp(l + 1, vi(even + 1, 0));
        dp[0][0] = 1;

        if (mx > even)
        {
            cout << "0" << endl;
            continue;
        }

        for (int i = 1; i <= l; i++)
        {
            if (arr[i - 1] == 0)
            {
                dp[i] = dp[i - 1];
                continue;
            }
            for (int j = 0; j <= even; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - arr[i - 1] >= 0)
                    dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }

        if (dp[l][even] == 0)
        {
            cout << "0" << endl;
            continue;
        }
        cout << nPPk(dp[l][even], even, odd, arr) << endl;
    }
    return 0;
}