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

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            st[node] = 1;
            return;
        }

        int mid = (start + end) >> 1;
        build(node << 1, start, mid);
        build(node << 1 | 1, mid + 1, end);
        st[node] = st[node << 1] + st[node << 1 | 1];
    }

    int query(int node, int start, int end, int index)
    {
        if (start == end)
            return start;

        int mid = (start + end) >> 1;
        if (index <= st[node << 1])
            return query(node << 1, start, mid, index);
        else
            return query(node << 1 | 1, mid + 1, end, index - st[node << 1]);
    }

    void update(int node, int start, int end, int index, int v)
    {
        if (start == end)
        {
            st[node] = v;
            return;
        }

        int mid = (start + end) >> 1;
        if (index <= mid)
            update(node << 1, start, mid, index, v);
        else
            update(node << 1 | 1, mid + 1, end, index, v);
        st[node] = st[node << 1] + st[node << 1 | 1];
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi arr(n);
    forN(n, arr);
    Segment st(n);
    st.build(1, 0, n - 1);

    int i = 0;
    while (i++ < n)
    {
        int index;
        cin >> index;
        int ps = st.query(1, 0, n - 1, index);
        cout << arr[ps] << (i < n ? ' ' : '\n');
        st.update(1, 0, n - 1, ps, 0);
    }
    return 0;
}