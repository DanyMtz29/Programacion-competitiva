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
        vi arr(n);
        if (n <= 3)
            cout << "-1" << "\n";
        else
        {
            vi pat = {2, 4, 1, 3};
            int pattern = n / 4;
            int i = 0;
            for (int p = 0; p <= pattern - 1; p++)
            {
                for (; i < 4 * (p + 1); i++)
                    arr[i] = pat[i % 4] + (p * 4);
            }
            if (n % 4 == 1)
            {
                for (; i < 4 * pattern; i++)
                    arr[i] = pat[i % 4] + (p * 4);
            }
        }
    }
    return 0;
}