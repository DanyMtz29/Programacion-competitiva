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
const int MOD = 1e9 + 7;
using namespace std;

int LCM(int a, int b)
{
    return (a * b) / __gcd(a, b);
}

int divisible(int n, vector<int> &v)
{
    int ans = 0;
    int m = v.size();
    for (int i = 1; i < (1 << m); i++)
    {
        int lcm = 1;
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1)
            {
                if (lcm > n) //////////////////////////////
                    continue;
                else
                {
                    if (lcm * v[j] > n)
                        lcm = LCM(lcm, v[j]);
                    else
                        lcm *= v[j];
                }
            }

        if (__builtin_popcount(i) % 2 == 0)
            ans -= (n / lcm);
        else
            ans += (n / lcm);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vi arr(n);
        forN(n, arr);
        eraseU(arr);

        cout << divisible(m, arr) << "\n";
    }
    return 0;
}