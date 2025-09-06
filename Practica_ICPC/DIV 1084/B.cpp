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
const int MOD = 1e9 + 7;
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n, j, k;
        cin >> n >> j >> k;
        j--;
        k = n - k;
        vi arr(n);
        forN(n, arr);
        int search = arr[j];
        sort(all(arr));

        int lb = upper_bound(all(arr), search) - arr.begin();
        k -= ((lb - 2) + 1);
        if (k <= 0)
        {
            cout << "YES" << "\n";
            continue;
        }
        k++;
        int i;
        for (i = n - 1; i > lb - 1 && k > 0; i--)
        {
            k--;
            if (k == 0)
                break;
        }
        if (i == lb - 1)
            cout << "NO" << "\n";
        else
            cout << "YES" << '\n';
    }
    return 0;
}
// k = 3
// 1 2 3 4 5 6
// 0 1 2 3 4 5