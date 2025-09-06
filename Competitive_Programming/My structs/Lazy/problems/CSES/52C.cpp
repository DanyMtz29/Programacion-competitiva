//https://codeforces.com/problemset/problem/52/C
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

struct segmenttree
{
    int n;
    vector<int> st, lazy;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v)
    {
        // leaf node base case
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
    }

    int query(int start, int ending, int l, int r, int node)
    {

        // lazy propagation / clear the lazy update
        if (lazy[node] != 0)
        {
            // pending updates
            // update the segment tree node
            // st[node] += lazy[node] * (ending - start + 1);
            st[node] += lazy[node];
            if (start != ending)
            {
                // propagate the updated value
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // non overlapping case
        if (start > r || ending < l)
            return LLONG_MAX;

        // complete overlap
        if (start >= l && ending <= r)
            return st[node];

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return min(q1, q2);
    }

    void update(int start, int ending, int node, int l, int r, int value)
    {
        // lazy propagation / clear the lazy update
        if (lazy[node] != 0)
        {
            // pending updates
            // update the segment tree node
            // st[node] += lazy[node] * (ending - start + 1);
            st[node] += lazy[node];
            if (start != ending)
            {
                // propagate the updated value
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // non overlapping case
        if (start > r || ending < l)
            return;

        // complete overlap
        if (start >= l && ending <= r)
        {
            // st[node] += value * (ending - start + 1);
            st[node] += value;
            if (start != ending)
            {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        // partial case
        int mid = (start + ending) / 2;

        update(start, mid, 2 * node + 1, l, r, value);

        update(mid + 1, ending, 2 * node + 2, l, r, value);

        st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);

        return;
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
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

    segmenttree st;
    st.init(n);
    st.build(arr);

    int Q;
    cin >> Q;
    Q++;
    while (Q--)
    {
        string s;
        getline(cin, s);
        istringstream ss(s);

        int x;
        vector<int> a;
        while (ss >> x)
            a.push_back(x);

        if (a.size() > 2)
        {
            if (a[0] > a[1])
            {
                st.update(0, a[1], a[2]);
                st.update(a[0], n - 1, a[2]);
            }
            else
                st.update(a[0], a[1], a[2]);
        }
        else if (a.size() == 2)
        {
            int mn = LLONG_MAX;
            if (a[0] > a[1])
            {
                int aa = st.query(0, a[1]);
                int bb = st.query(a[0], n - 1);
                mn = min(aa, bb);
            }
            else
                mn = st.query(a[0], a[1]);
            cout << mn << endl;
        }
    }

    return 0;
}