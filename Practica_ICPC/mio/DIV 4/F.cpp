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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        string s = "";
        if (b == 0)
        {
            if (c > 0)
                for (int i = 1; i <= c + 1; i++)
                    s += '1';
            else if (a > 0)
                for (int i = 1; i <= a + 1; i++)
                    s += '0';
        }
        else
        {
            for (int i = 1; i <= a; i++)
                s += '0';

            if (b % 2 != 0)
            {
                for (int i = 1; i <= (b + 1) / 2; i++)
                {
                    s += '0';
                    s += '1';
                }
                for (int i = 1; i <= c; i++)
                    s += '1';
            }
            else
            {
                b -= 1;
                for (int i = 1; i <= (b + 1) / 2; i++)
                {
                    s += '0';
                    s += '1';
                }
                for (int i = 1; i <= c; i++)
                    s += '1';
                s += '0';
            }
        }
        cout << s << "\n";
    }
    return 0;
}