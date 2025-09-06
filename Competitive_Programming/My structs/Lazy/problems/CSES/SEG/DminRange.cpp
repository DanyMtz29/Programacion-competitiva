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

struct Segment{
    vector<int> st;
    Segment(int _n) : st(_n * 4, 0) {}

    void build(int node, int start, int end, vector<int> &a){
        if (start == end){
            st[node] = a[start];
            return;
        }

        int mid = (start + end) >> 1;
        build(node << 1, start, mid, a);
        build(node << 1 | 1, mid + 1, end, a);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }

    int query(int node, int start, int end, int l, int r){
        if (start > r || end < l)
            return INT_MAX;
        if (start >= l && end <= r)
            return st[node];

        int mid = (start + end) >> 1;
        return min(query(node << 1, start, mid, l, r), query(node << 1 | 1, mid + 1, end, l, r));
    }

    void update(int node, int s, int e, int i, int v){
        if (s == e){
            st[node] = v;
            return;
        }
        int m = (s + e) >> 1;
        if (i <= m)
            update(node << 1, s, m, i, v);
        else
            update(node << 1 | 1, m + 1, e, i, v);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
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

    while (q--){
        int v, l, r;
        cin >> v >> l >> r;
        if (v == 2)
            cout << st.query(1, 0, n - 1, l - 1, r - 1) << endl;
        else
            st.update(1, 0, n - 1, l - 1, r);
    }
    return 0;
}