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

void binarySearch(vi &a, int x)
{
    int i = 0, j = a.size() - 1;
    while (i <= j)
    {
        int mid = (i + j) >> 1;
        if (a[mid] == x)
            return;
        else if (a[mid] > x)
            j = mid - 1;
        else
            i = mid + 1;
    }
    a[i] = x;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n;
        cin >> n;
        vi a;
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (a.empty() || a.back() < x)
                a.pb(x);
            else
            {
                mx = max(mx, (int)a.size());
                binarySearch(a, x);
            }
        }
        cout << max(mx, (int)a.size()) << "\n";
    }
    return 0;
}