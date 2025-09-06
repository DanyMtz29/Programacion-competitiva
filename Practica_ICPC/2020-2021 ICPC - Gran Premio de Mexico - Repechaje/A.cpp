#include <bits/stdc++.h>
#define int long long int
using namespace std;

int pwr(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

int32_t main()
{
    int N, M;
    cin >> N >> M;
    cout << (pwr(2, N) + pwr(2, M) - 2);
    return 0;
}