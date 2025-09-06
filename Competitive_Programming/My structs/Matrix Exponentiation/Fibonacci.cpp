#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int sz = 2;
const int mod = 1e9 + 7;

struct Mat
{
    int m[sz][sz];

    Mat() { memset(m, 0, sizeof(m)); }

    void identity()
    {
        for (int i = 0; i < sz; i++)
            m[i][i] = 1;
    }

    Mat operator*(Mat a)
    {
        Mat res;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++)
                {
                    res.m[i][j] += (((m[i][k] * a.m[k][j]) % mod) + mod) % mod;
                    res.m[i][j] %= mod;
                }
        return res;
    }
};

lli fib(lli n)
{
    if (n <= 2)
        return 1;

    Mat res;
    res.identity();

    Mat T;
    T.m[0][0] = T.m[1][0] = T.m[0][1] = 1;

    n -= 2;

    while (n)
    {
        if (n & 1)
            res = res * T;
        T = T * T;
        n >>= 1;
    }
    return (res.m[0][0] + res.m[0][1]) % mod;
}

int main()
{
    lli n;
    while (cin >> n)
    {
        cout << "fib(" << n << "): " << fib(n) << endl;
    }

    return 0;
}