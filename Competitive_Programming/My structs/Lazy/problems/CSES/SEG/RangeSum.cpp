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
    vector<int> st;

    Segment(int _n) : st(_n * 4, 0) {}

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
        st[node] = st[node << 1] + st[node << 1 | 1];
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return 0;
        if (start >= l && end <= r)
            return st[node];

        int mid = (start + end) >> 1;
        return query(node << 1, start, mid, l, r) + query(node << 1 | 1, mid + 1, end, l, r);
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
        int l, r;
        cin >> l >> r;
        cout << st.query(1, 0, n - 1, l - 1, r - 1) << endl;
    }
    return 0;
}