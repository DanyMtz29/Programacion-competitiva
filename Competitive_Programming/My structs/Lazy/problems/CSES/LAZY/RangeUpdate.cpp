#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

struct Segment
{
    vector<int> st, lazy;

    Segment(int _n) : st(_n * 4, 0), lazy(4 * _n, 0) {}

    void build(int node, int start, int end, vector<int> &a)
    {
        if (start == end)
        {
            st[node] = a[start];
            return;
        }

        int mid = (start + end) >> 1;
        build(node << 1, start, mid, a);
        build(node << 1 | 1, mid + 1, end, a);
    }

    int query(int node, int start, int end, int index)
    {
        push(node, start, end);
        if (start == end)
            return st[node];

        int mid = (start + end) >> 1;
        if (index <= mid)
            return query(node << 1, start, mid, index);
        else
            return query(node << 1 | 1, mid + 1, end, index);
    }

    void push(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            st[node] += lazy[node];
            if (start != end)
            {
                lazy[node << 1] += lazy[node];
                lazy[node << 1 | 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val)
    {
        push(node, start, end);
        if (start > r || end < l)
            return;
        if (start >= l && end <= r)
        {
            lazy[node] += val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) >> 1;
        update(node << 1, start, mid, l, r, val);
        update(node << 1 | 1, mid + 1, end, l, r, val);
    }
};

int32_t main()
{
    int n, q;
    cin >> n >> q;
    vi arr(n);
    forN(n, arr);
    Segment st(n);
    st.build(1, 0, n - 1, arr);

    while (q--)
    {
        int v;
        cin >> v;
        if (v == 2)
        {
            int index;
            cin >> index;
            cout << st.query(1, 0, n - 1, index - 1) << endl;
        }
        else
        {
            int a, b, u;
            cin >> a >> b >> u;
            st.update(1, 0, n - 1, a - 1, b - 1, u);
        }
    }
    return 0;
}