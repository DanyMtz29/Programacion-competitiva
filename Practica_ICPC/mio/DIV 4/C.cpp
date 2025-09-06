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
        int a, b;
        cin >> a >> b;
        int d1 = 0, d2 = 0;
        int i = 0;
        do
        {
            b += d1;
            d2 = d1;
            d1 = floor((b / a));
            b -= d2;
        } while (d1 != d2);
        cout << b + d2 << "\n";
    }
    return 0;
}