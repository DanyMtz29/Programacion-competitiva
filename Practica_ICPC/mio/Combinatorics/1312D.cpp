// Problem: https://codeforces.com/problemset/problem/1312/D
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int const MOD = 998244353;
int const N = 200005;
int fact[N];

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

int nCr(int n, int r)
{
    return mulm(mulm(fact[n], inv(fact[r])), inv(fact[n - r]));
}

int32_t main()
{
    factorials();

    int n, m;
    cin >> n >> m;
    if (n <= 2)
    {
        cout << "0" << endl;
        return 0;
    }

    int res = nCr(m, n - 1);
    res %= MOD;
    res = mulm(res, n - 2);
    res %= MOD;
    res = mulm(res, pwrm(2, n - 3));
    res %= MOD;
    cout << res << endl;
    return 0;
}