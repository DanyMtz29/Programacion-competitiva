#include <bits/stdc++.h>
// #define int long long int
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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int i = 0;
        vi ans;
        while (n)
        {
            if (n % 10 != 0)
                ans.push_back((n % 10) * pwr(10, i));
            n /= 10;
            i++;
        }
        cout << ans.size() << "\n";
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}