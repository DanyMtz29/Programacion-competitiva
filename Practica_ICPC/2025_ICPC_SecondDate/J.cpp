#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int, int>
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define pb push_back
using namespace std;

const int MOD = 998244353;
int const N = 1e6 + 5;
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
        factInv[i] = mulm(factInv[i + 1], (i + 1));
}

// nCr = n! / ( r! * (n-r)! )
int nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return mulm(mulm(fact[n], inv(fact[r])), inv(fact[n - r]));
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    factorials();
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int Q;
        cin >> Q;
        while (Q--)
        {
            int a, b;
            cin >> a >> b;
            cout << nCr(a + 1, b + 1) << "\n";
        }
    }
    return 0;
}