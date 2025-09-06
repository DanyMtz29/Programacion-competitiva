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

struct Fenwick
{
    vi ft;
    int n;

    void init(int _n)
    {
        this->n = _n + 1;
        this->ft.resize(n, 0);
    }

    void add(int i, int val)
    {
        for (; i < n; i += (i & (-i)))
            ft[i] += val;
    }

    int get(int i)
    {
        int ans = 0;
        for (; i; i -= (i & (-i)))
            ans += ft[i];
        return ans;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    vi arr(n);

    forN(n, arr);

    Fenwick ft;
    ft.init(n);

    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b;
        if (a == 2)
            cout << ft.get(b) + arr[b - 1] << "\n";
        else
        {
            cin >> c >> d;
            ft.add(c + 1, -d);
            ft.add(b, d);
        }
    }
    return 0;
}