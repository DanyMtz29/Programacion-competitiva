//https://www.spoj.com/problems/BAISED/
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
        cin.get();
        vi arr(n);
        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);
            istringstream ss(s);
            int val;
            ss >> s >> val;
            arr[i] = val;
        }
        sort(all(arr));
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += abs(i - arr[i - 1]);
        cout << ans << "\n";
    }
    return 0;
}