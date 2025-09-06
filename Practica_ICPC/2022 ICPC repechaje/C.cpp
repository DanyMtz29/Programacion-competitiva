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
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, Q;
        cin >> n >> Q;
        vi arr(n);
        forN(n, arr);
        sort(arr.begin(), arr.end());
        vi prefixSum(n + 1);
        prefixSum[0] = 0;
        for (int i = 1; i <= n; i++)
            prefixSum[i] += prefixSum[i - 1] + arr[i - 1];
        while (Q--)
        {
            int q;
            cin >> q;
            int index = upper_bound(arr.begin(), arr.end(), q) - arr.begin();
            // cout << index << "\n";
            if (index == 0)
            {
                cout << (q * n) << "\n";
            }
            else if (index == n)
            {
                cout << prefixSum[n] << "\n";
            }
            else
            {
                cout << prefixSum[index] + (q * (n - index)) << "\n";
            }
        }
    }
    return 0;
}