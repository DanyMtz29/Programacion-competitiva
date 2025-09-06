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

int check(int n)
{
    int ans = 0;
    while (n)
    {
        ans = max(ans, n % 10);
        n /= 10;
    }
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n)
    {
        ans++;
        n -= check(n);
    }
    cout << ans << endl;
    return 0;
}