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

struct Point
{
    int node;
    int x;
    int y;
    void init(int a, int b, int v)
    {
        this->node = v;
        this->x = a;
        this->y = b;
    }
};

bool cmp(Point &a, Point &b)
{
    return a.x < b.x;
}

int find(int x, vi &parent)
{
    if (parent[x] == -1)
        return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vi &par)
{
    int x = find(a, par);
    int y = find(b, par);
    if (x != y)
        par[y] = x;
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
        vector<Point> pointsX(n), pointsY(n);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            Point x, y;
            x.init(a, b, i);
            y.init(b, a, i);
            pointsX[i] = x;
            pointsY[i] = y;
        }

        sort(pointsX.begin(), pointsX.end(), cmp);
        sort(pointsY.begin(), pointsY.end(), cmp);

        vvi edges((n - 1) * 2, vi(3));
        int k = 0;
        for (int i = 0; i < n - 1; i++)
        {
            vi arr = {abs(pointsX[i].x - pointsX[i + 1].x), pointsX[i].node, pointsX[i + 1].node};
            edges[k++] = arr;
        }
        for (int i = 0; i < n - 1; i++)
        {
            vi arr = {abs(pointsY[i].x - pointsY[i + 1].x), pointsY[i].node, pointsY[i + 1].node};
            edges[k++] = arr;
        }
        vi par(n, -1);
        sort(edges.begin(), edges.end());
        int ans = 0;
        for (auto e : edges)
        {
            int u = e[1];
            int v = e[2];
            int w = e[0];
            if (find(u, par) != find(v, par))
            {
                unite(u, v, par);
                ans += w;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}