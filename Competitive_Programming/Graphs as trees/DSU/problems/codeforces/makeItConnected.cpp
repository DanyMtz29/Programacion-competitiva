//https://codeforces.com/problemset/problem/1095/F
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

int find(int x)
{
    if (parent[x] == -1)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y)
        parent[y] = x;
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
        int n, m;
        cin >> n >> m;
        vi arr(n);
        forN(n, arr);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = -1;

        vvi edges(m + n - 1, vi(3));
        int i = 0;
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vi ed = {w, u - 1, v - 1};
            edges[i++] = ed;
        }

        int it = min_element(arr.begin(), arr.end()) - arr.begin();
        for (int j = 0; j < n; j++)
        {
            if (j == it)
                continue;
            vi ed = {arr[it] + arr[j], it, j};
            edges[i++] = ed;
        }
        sort(edges.begin(), edges.end());
        int ans = 0;
        for (auto &vec : edges)
        {
            int w = vec[0];
            int u = vec[1];
            int v = vec[2];
            if (find(u) != find(v))
            {
                unite(u, v);
                ans += w;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}