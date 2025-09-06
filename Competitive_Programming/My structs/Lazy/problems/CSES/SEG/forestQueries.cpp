#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(v, n)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define forM(v, n, m)               \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
    cin >> v[i][j]
using namespace std;

struct Segment
{
    vvi st;
    int n;
    Segment(int _n) : st(4 * _n, vi(4 * _n)), n(_n) {}

    void buildY(int nodeX, int startX, int endX, int nodeY, int startY, int endY, vvi &arr)
    {
        if (startY == endY)
        {
            if (startX == endX)
                st[nodeX][nodeY] = arr[startX][startY];
            else
                st[nodeX][nodeY] = st[nodeX << 1][nodeY] + st[nodeX << 1 | 1][nodeY];
            return;
        }

        int midY = (startY + endY) >> 1;
        buildY(nodeX, startX, endX, nodeY << 1, startY, midY, arr);
        buildY(nodeX, startX, endX, nodeY << 1 | 1, midY + 1, endY, arr);
        st[nodeX][nodeY] = st[nodeX][nodeY << 1] + st[nodeX][nodeY << 1 | 1];
    }

    void buildX(int node, int start, int end, vvi &arr)
    {
        if (start != end)
        {
            int mid = (start + end) >> 1;
            buildX(node << 1, start, mid, arr);
            buildX(node << 1 | 1, mid + 1, end, arr);
        }

        buildY(node, start, end, 1, 0, this->n - 1, arr);
    }

    int queryY(int nodeX, int nodeY, int start, int end, int ly, int ry)
    {
        if (start > ry || end < ly)
            return 0;
        if (start >= ly && end <= ry)
            return st[nodeX][nodeY];

        int mid = (start + end) >> 1;

        return queryY(nodeX, nodeY << 1, start, mid, ly, ry) + queryY(nodeX, nodeY << 1 | 1, mid + 1, end, ly, ry);
    }

    int queryX(int node, int start, int end, int lx, int rx, int ly, int ry)
    {
        if (start > rx || end < lx)
            return 0;
        if (start >= lx && end <= rx)
            return queryY(node, 1, 0, n - 1, ly, ry);
        int mid = (start + end) >> 1;
        return queryX(node << 1, start, mid, lx, rx, ly, ry) + queryX(node << 1 | 1, mid + 1, end, lx, rx, ly, ry);
    }

    void show()
    {
        for (int i = 1; i < 4 * n; i++)
        {
            for (int j = 1; j < 4 * n; j++)
                cout << st[i][j] << " ";
            cout << "" << endl;
        }
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    vvi arr(n, vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c == '*';
        }
    }
    Segment st(n);
    st.buildX(1, 0, n - 1, arr);
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << st.queryX(1, 0, n - 1, x1 - 1, x2 - 1, y1 - 1, y2 - 1) << endl;
    }

    return 0;
}