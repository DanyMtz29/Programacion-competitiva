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
        forN(n, arr);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int l = 0;
            int sum = 0;
            int target = arr[i];
            int count = 0;
            for (int r = 0; r < n; r++)
            {
                sum += arr[r];
                while (l <= r && sum > target)
                    sum -= arr[l++];
                if (sum == target)
                {
                    if (r - l + 1 > 1)
                        count++;
                    sum -= arr[l++];
                }
                if (count)
                {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
// 3,1,4,1,5,9,2,6,5
//   4 5 6 14 11 8
// 4 8 6
