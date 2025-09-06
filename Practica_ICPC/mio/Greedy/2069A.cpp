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
        int n;
        cin >> n;
        int ceros = 2;
        bool flag = true;
        for (int i = 0; i < n - 2; i++)
        {
            int e;
            cin >> e;
            if (e == 0)
                ceros++;
            else
            {
                if (ceros >= 2 || ceros == 0)
                    ceros = 0;
                else
                    flag = false;
            }
        }
        if (flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}