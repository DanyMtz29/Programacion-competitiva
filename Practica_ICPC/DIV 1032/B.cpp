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
    cin >> T;
    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;
        vi arr(26, 0), arr2(26, 0);
        bool flag = false;
        for (int i = 0; i < n - 1; i++)
        {
            arr[s[i] - 'a']++;
            if (arr[s[i] - 'a'] > 1)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            for (int i = n - 1; i > 0; i--)
            {
                arr2[s[i] - 'a']++;
                if (arr2[s[i] - 'a'] > 1)
                {
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}