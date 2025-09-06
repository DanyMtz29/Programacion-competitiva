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
        int n;
        cin >> n;
        vi arr(n);
        umii mp;
        for (int i = 0; i < n; i++)
        {
            int e;
            cin >> e;
            arr[i] = e;
            mp[e]++;
        }

        int prev = -1;
        int minNumber = -1;
        int i;
        sort(all(arr));
        for (i = 0; i < n; i++)
        {
            if (arr[i] - 1 > prev)
            {
                minNumber = prev + 1;
                break;
            }
            else
            {
                if (arr[i] == prev)
                    continue;
                else
                    prev = arr[i];
            }
        }

        if (i == n)
            minNumber = arr[n - 1] + 1;

        vi totalAppears(minNumber + 1);
        vi restAppears(minNumber + 1);
        for (int i = 0; i <= minNumber; i++)
        {
            totalAppears[i] = mp[i];
            restAppears[i] = (n - i);
        }
        sort(all(totalAppears));
        sort(all(restAppears));
        vi ans(n + 1);
        for (int i = 0; i <= n; i++)
        {
            int l = upper_bound(all(totalAppears), i) - totalAppears.begin();
            int r = upper_bound(all(restAppears), i) - restAppears.begin();
            // cout << "\ni: " << i << "\n";
            // cout << "L: " << l << "\n";
            // cout << "R: " << r << "\n";
            l--;
            r--;
            ans[i] = (max(l, 0ll) - max(r, 0ll)) + 1;
        }
        copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
        cout << "\n";
    }
    return 0;
}