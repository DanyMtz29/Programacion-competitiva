//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/special-path-b3ac37d0/
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

vector<int> par;
vector<int> rk;

int findDSU(int x)
{
    if (par[x] == -1)
        return x;
    return par[x] = findDSU(par[x]);
}

void unionDSU(int a, int b, int w)
{
    int x = findDSU(a);
    int y = findDSU(b);
    if (x != y)
    {
        par[y] = x;
        rk[x] = max(rk[x], w);
    }
}

int specialPath(int n, vector<int> a, vector<vector<int>> edges, int start, int end)
{

    vector<tuple<int, int, int>> edgesW(edges.size());
    int u, v, w;
    for (int i = 0; i < edges.size(); i++)
    {
        u = edges[i][0];
        v = edges[i][1];

        w = abs(a[u - 1] - a[v - 1]);
        edgesW[i] = {w, u, v};
    }

    par.resize(n + 1);
    rk.resize(n + 1);

    for (int i = 0; i <= n; i++)
    {
        par[i] = -1;
        rk[i] = 0;
    }

    sort(edgesW.begin(), edgesW.end());

    cout << endl;

    for (auto &t : edgesW)
    {
        tie(w, u, v) = t;
        unionDSU(u, v, w);

        if (findDSU(start) == findDSU(end))
            return rk[findDSU(start)];
    }
    return 0;
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
        int n, e;
        cin >> n >> e;
        vvi edges(e, vi(2, 0));
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            edges[i] = {a, b};
        }

        vi arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int start, end;
        cin >> start >> end;
        cout << specialPath(n, arr, edges, start, end) << endl;
    }
    return 0;
}