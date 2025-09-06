// Problem: https://codeforces.com/problemset/problem/300/C
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

const int MOD = 1000000007;
const int N = 1000005;
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

int nPr(int n, int k1, int k2)
{
    return mulm(mulm(fact[n], inv(fact[k1])), inv(fact[k2]));
}

bool check(int a, int b, int num)
{
    while (num > 0)
    {
        int rest = num % 10;
        if (rest != a && rest != b)
            return false;
        num /= 10;
    }
    return true;
}

int addm(int a, int b)
{
    return (a + b) % MOD;
}

int32_t main()
{
    factorials();
    int a, b, n;
    cin >> a >> b >> n;

    int total = 0;
    int sum = b * n;

    if (check(a, b, sum))
        total++;

    int totalBs = n;
    int totalAs = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum - b + a;
        totalAs++;
        totalBs--;
        if (check(a, b, sum))
        {
            total = addm(total, nPr(n, totalAs, totalBs));
        }
    }

    cout << total << endl;

    return 0;
}