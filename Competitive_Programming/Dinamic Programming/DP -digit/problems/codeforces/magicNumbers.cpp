#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 2001;

string k;
int d, apaar = 1e9 + 7, digit;
int memo[N][2][2001][2];

int dp(int i, bool last, int mod, bool odd)
{
    if (i == k.size())
    {
        return mod == 0;
    }

    int &ans = memo[i][last][mod][odd];
    if (ans != -1)
        return ans;

    ans = 0;

    int till = last ? (k[i] - '0') : 9;

    if (odd)
    {
        for (int digits = 0; digits <= till; digits++)
        {
            if (digits == digit)
                continue;

            ans += dp(i + 1, last && (digits == till), (mod * 10 + digits) % d, !odd);
            ans %= apaar;
        }
    }
    else
    {
        if (digit <= till)
        {
            ans += dp(i + 1, last && (digit == till), (mod * 10 + digit) % d, !odd);
            ans %= apaar;
        }
    }

    return ans;
}

bool ajuste()
{
    int sz = k.size();
    int m = 0;
    bool flag = false;
    for (int i = 0; i < sz; i++)
    {
        if (flag)
        {
            if (k[i] - '0' != digit)
                return 0;
            flag = !flag;
        }
        else
        {
            if (k[i] - '0' == digit)
                return 0;
            flag = !flag;
        }
        m = (m * 10 + k[i] - '0') % d;
    }
    return (m == 0);
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> d >> digit;

    string l, r;
    cin >> l >> r;
    k = l;
    memset(memo, -1, sizeof(memo));

    int resL = (dp(0, 1, 0, 1)) % apaar;
    // cout << "RESLL " << resL << endl;

    k = r;
    memset(memo, -1, sizeof(memo));

    int resR = (dp(0, 1, 0, 1)) % apaar;

    // cout << "resR: " << resR << endl;

    k = l;
    cout << ((resR - resL + ajuste() % apaar) + apaar) % apaar << endl;

    return 0;
}