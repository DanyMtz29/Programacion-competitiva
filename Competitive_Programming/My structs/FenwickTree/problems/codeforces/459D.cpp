//https://codeforces.com/problemset/problem/459/D
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
    int sz;
    vi ft;

    void init(int n)
    {
        this->sz = n + 1;
        this->ft.resize(sz, 0);
    }

    void upt(int i, int val)
    {
        for (/*i++*/; i < sz; i += (i & (-i)))
            ft[i] += val;
    }
    int get(int i)
    {
        // i++;
        int ans = 0;
        while (i)
        {
            ans += ft[i];
            i -= (i & (-i));
        }
        return ans;
    }

    int qry(int l, int r)
    {
        return get(r) - get(l - 1);
    }

    void show()
    {
        cout << "FENWICK TREE" << endl;
        for (int i = 1; i < sz; i++)
            cout << this->get(i) << " ";
        cout << "\n";
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi arr(n);
    umii mp;
    vi lefts(n);
    vi rights(n);
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        mp[e]++;
        arr[i] = e;
        lefts[i] = mp[e];
    }

    mp.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        mp[arr[i]]++;
        rights[i] = mp[arr[i]];
    }

    Fenwick ft;
    ft.init(n);

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += ft.get(lefts[i] - 1);
        ft.upt(rights[i], 1);
    }
    cout << ans << "\n";

    return 0;
}