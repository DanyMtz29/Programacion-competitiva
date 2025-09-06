#include <bits/stdc++.h>
#define int long long
using namespace std;

// int const MOD = 1e9 + 7;
const int MOD = 998244353;
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

// nCr = n! / ( r! * (n-r)! )
int nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return mulm(mulm(fact[n], inv(fact[r])), inv(fact[n - r]));
}

// nCrRep = (n+r-1)! / ( r! * (n-1)! )
int nCrRep(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return mulm(mulm(fact[n + r - 1], inv(fact[r])), inv(fact[n - 1]));
}

// nPr = n!/ ( n-r )!
int nPr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return mulm(fact[n], inv(fact[n - r]));
}

// np{k} = n!/ ( k1!*k2!*k3!...km! )
int nPrRep(int n, vector<int> &k)
{
    int den = 1;
    for (int i = 0; i < k.size(); i++)
    {
        den = mulm(den, fact[k[i]]);
    }
    // cout << "Den: " << den << endl;
    if (den > fact[n])
        return 0;
    return mulm(fact[n], inv(den));
}

int32_t main()
{
    cout << "Combinatoria con modulo" << endl;
    factorials();
    int n = 3, r = 2;
    cout << n << "C" << r << ": " << nCr(n, r) % MOD << endl;
    n = 4;
    cout << n << "C" << r << "Rep: " << nCrRep(n, r) % MOD << endl;
    cout << n << "P" << r << ": " << nPr(n, r) << endl;
    n = 4;
    vector<int> k = {1, 3};
    cout << "P" << n << ",kRep: " << nPrRep(n, k) << endl;

    while (cin >> n)
    {
        cin >> r;
        cout << n << "C" << r << ": " << nCr(n, r) << endl;
        // cout << n << "C" << r << "Rep: " << nCrRep(n, r) << endl;
        // cout << n << "P" << r << ": " << nPr(n, r) << endl;
    }

    return 0;
}