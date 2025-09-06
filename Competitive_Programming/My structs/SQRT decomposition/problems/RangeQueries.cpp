/*
    No agarra porque N = 2e5, lo cual hace 2e5 * raiz(2e5), rompe el tiempo limite en 1 seg
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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        int m = sqrt(n) + 1;
        int a[n], blocks[m];

        memset(blocks, 0, sizeof(blocks));

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            blocks[i / m] += a[i];
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int ans = 0;
            for (int i = l; i <= r;)
            {
                if (i % m == 0 && i + m - 1 <= r)
                {
                    ans += blocks[i / m];
                    i += m;
                }
                else
                {
                    ans += a[i];
                    i++;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}