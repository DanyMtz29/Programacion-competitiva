//https://atcoder.jp/contests/abc214/tasks/abc214_d
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

vector<int> parent;
vector<int> ranks;

int find(int x)
{
    if (parent[x] == -1)
        return x;
    return parent[x] = find(parent[x]);
}

int getRank(int x)
{
    if (parent[x] == -1)
        return ranks[x];
    return getRank(parent[x]);
}

int unir(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y)
    {
        if (ranks[x] < ranks[y])
        {
            parent[x] = y;
            ranks[y] += ranks[x];
        }
        else
        {
            parent[y] = x;
            ranks[x] += ranks[y];
        }
    }
    return max(ranks[x], ranks[y]);
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
        parent.resize(n + 1);
        ranks.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = -1;
            ranks[i] = 1;
        }
        vector<tuple<int, int, int>> edges(n);
        int u, v, w;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v >> w;
            edges[i] = {w, u, v};
        }

        sort(edges.begin(), edges.end());

        int ans = 0;
        for (auto &t : edges)
        {
            tie(w, u, v) = t;
            ans += (getRank(u) * getRank(v) * w);
            unir(u, v);
        }
        cout << ans << "\n";
    }
    return 0;
}