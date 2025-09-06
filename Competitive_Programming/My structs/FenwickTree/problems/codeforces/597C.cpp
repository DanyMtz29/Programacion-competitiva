//https://codeforces.com/problemset/problem/597/C
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

struct Fen
{
    int n;
    vi ft;
    void init(int sz)
    {
        this->n = sz + 1;
        this->ft.resize(n, 0);
    }

    void init1(int sz)
    {
        this->n = sz + 1;
        this->ft.resize(n, 1);
    }

    void add(int i, int val)
    {
        for (/*i++*/; i < n; i += (i & (-i)))
            ft[i] += val;
    }
    int get(int i)
    {
        int ans = 0;
        for (/*i++*/; i; i -= (i & (-i)))
            ans += ft[i];
        return ans;
    }

    int qry(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vi arr(n);
    forN(n, arr);

    vector<int> dp(n + 1, 1);

    vector<Fen> fenwicks(k + 2);

    int ans = 0;
    for (int i = 2; i <= k + 1; i++)
    {
        fenwicks[i].init(n);

        for (int j = 0; j < n; j++) // Array: 1 2 3 5 4
        {
            int aux = dp[j];
            dp[j] = fenwicks[i].qry(1, arr[j] - 1);
            fenwicks[i].add(arr[j], aux);
        }
    }
    for (int i = 0; i < n; i++)
        ans += dp[i];

    cout << ans << endl;

    return 0;
}

/**
 5 2
 1 2 3 5 4
 */