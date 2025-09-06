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
using namespace std;

struct Segment
{
    vi st;
    Segment(int _n) : st(4 * _n, 0) {}
    void build(int node, int start, int end, vi &arr)
    {
        if (start == end)
        {
            st[node] = arr[start];
            return;
        }
        int m = (start + end) >> 1;
        build(node << 1, start, m, arr);
        build(node << 1 | 1, m + 1, end, arr);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return INFS;
        if (start >= l && end <= r)
            return st[node];
        int m = (start + end) >> 1;
        return min(query(node << 1, start, m, l, r), query(node << 1 | 1, m + 1, end, l, r));
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            st[node] = val;
            return;
        }

        int m = (start + end) >> 1;
        if (idx <= m)
            update(node << 1, start, m, idx, val);
        else
            update(node << 1 | 1, m + 1, end, idx, val);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vi negs(n), posit(n);
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        negs[i] = element - (i + 1);
        posit[i] = element + (i + 1);
    }

    Segment stPos(n), stNeg(n);
    stPos.build(1, 0, n - 1, posit);
    stNeg.build(1, 0, n - 1, negs);

    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b, c;
            cin >> b >> c;

            stPos.update(1, 0, n - 1, b - 1, c + b);
            stNeg.update(1, 0, n - 1, b - 1, c - b);
        }
        else
        {
            int b;
            cin >> b;
            int q1 = stNeg.query(1, 0, n - 1, 0, b - 1) + 2;
            int q2 = stPos.query(1, 0, n - 1, b - 1, n - 1) - 2;
            cout << min(q1, q2) << "\n";
        }
    }

    return 0;
}