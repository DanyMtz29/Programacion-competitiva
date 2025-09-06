/*
    Problem: https://codeforces.com/contest/2121/problem/E
    La idea de resolver fue por medio de la resta. Dependiendo de la resta es cuantos
    numeros se pueden subir desde el mas bajo, que es left. A partir de ahi, se va tomando el modulo
    del numero, luego se compara para ver si son diferentes, una vez se sabe que son diferentes
    se ve si se añade uno o dos dependiendo de la potencia de diez donde se encuentre, y si es
    posible añadirlo dependiendo de cuantos numeros le hemos bajado a la resta
*/

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
#define F first
#define S second
const int MOD = 1e9 + 7;
using namespace std;

int getDigits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int pwr(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int getNumber(int l, int r)
{
    int sub = r - l; // 900990999 900991010, 11
                     //  900991001
    int left = l;
    int index = 0;
    int ret = 0;
    while (r > 0)
    {
        int m = l % 10;
        int ml = left % 10;
        int mr = r % 10;
        if (m == ml || m == mr)
        {
            if (sub > 0 && m + 1 != ml && ((m + 1) % 10) != mr)
            {
                sub -= 1;
                l += 1;
            }
            else if (sub > 1)
            {
                sub -= 2;
                l += 2;
            }
        }

        ret += ((l % 10) * pwr(10, index));
        l /= 10;
        left /= 10;
        r /= 10;
        index++;
        sub /= 10;
    }
    return ret;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        int sub = r - l;
        if (l == r)
        {
            int digits = getDigits(l);
            cout << digits * 2 << "\n";
        }
        else
        {
            int number = getNumber(l, r);
            int ans = 0;
            while (number > 0)
            {
                int m = number % 10;
                int ml = l % 10;
                int mr = r % 10;
                if (ml % 10 == m)
                    ans++;
                if (mr % 10 == m)
                    ans++;
                r /= 10;
                l /= 10;
                number /= 10;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
