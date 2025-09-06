//https://codeforces.com/problemset/problem/992/B
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int32_t main()
{
    int l, r, x, y;

    cin >> l >> r >> x >> y;

    int root = sqrt(y);
    //cout << "Root: " << root << endl;
    int count = 0;
    for (int i = max(1ll, l); i <= min(root, r); i++)
    // for (int i = l; i <= r; i++)
    {
        if (y % i == 0)
        {
            int GCD = gcd(i, y / i);
            //cout << "gcd(" << i << "," << y / i << "): " << GCD << endl;
            if (GCD == x)
            {
                if (i != y / i)
                    count += 2;
                else
                    count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}