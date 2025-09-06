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
const int MOD = 998244353;
using namespace std;

int mulm(int a, int b)
{
    return (a * b) % MOD;
}

double pwrM(int a, int b)
{
    double res = 1;
    while (b)
    {
        if (b & 1)
            res = mulm(res, a);
        a = mulm(a, a);
        b >>= 1;
    }
    return res;
}

int32_t main()
{
    int a = 2;
    cout << pwrM(1, MOD - 2) << endl;
    return 0;
}