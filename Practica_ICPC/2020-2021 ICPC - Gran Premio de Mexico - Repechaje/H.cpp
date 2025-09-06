#include <bits/stdc++.h>
#define int long long
using namespace std;

int const MOD = 1e9 + 7;
int const N = 200005;
int fact[N];
int factInv[N];

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

void factorialsInverse()
{
    factInv[N] = pwrm(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--)
    {
        factInv[i] = mulm(factInv[i + 1], (i + 1));
    }
}

int nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return mulm(mulm(fact[n], inv(fact[r])), inv(fact[n - r]));
}

int nCrRep(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return mulm(mulm(fact[n + r - 1], inv(fact[r])), inv(fact[n - 1]));
}

int32_t main()
{
    factorials();
    int T;
    cin >> T;
    while (T--)
    {
        int A;
        cin >> A;
        cout << nCrRep(A, A) << endl;
    }

    return 0;
}