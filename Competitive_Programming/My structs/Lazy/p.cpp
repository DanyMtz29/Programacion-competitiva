#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegmentTree
{
    int n;
    vector<ll> st, lazy;
    SegmentTree(int _n) : n(_n), st(4 * n, 0), lazy(4 * n, 0) {}

    void build(int p, int l, int r, const vector<ll> &a)
    {
        if (l == r)
        {
            st[p] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }

    void push(int p, int l, int r)
    {
        if (lazy[p] != 0)
        {
            st[p] += lazy[p];
            if (l < r)
            {
                lazy[p << 1] += lazy[p];
                lazy[p << 1 | 1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }

    void update(int p, int l, int r, int i, int j, ll v)
    {
        push(p, l, r);
        if (r < i || l > j)
            return;
        if (l >= i && r <= j)
        {
            lazy[p] += v;
            push(p, l, r);
            return;
        }
        int m = (l + r) >> 1;
        update(p << 1, l, m, i, j, v);
        update(p << 1 | 1, m + 1, r, i, j, v);
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }

    ll query(int p, int l, int r, int i, int j)
    {
        push(p, l, r);
        if (r < i || l > j)
            return LLONG_MAX;
        if (l >= i && r <= j)
            return st[p];
        int m = (l + r) >> 1;
        return min(
            query(p << 1, l, m, i, j),
            query(p << 1 | 1, m + 1, r, i, j));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree st(n);
    st.build(1, 0, n - 1, a);

    int m;
    cin >> m;
    string line;
    getline(cin, line);

    while (m--)
    {
        getline(cin, line);
        istringstream iss(line);
        vector<ll> op;
        ll x;
        while (iss >> x)
            op.push_back(x);

        if (op.size() == 3)
        {
            int l = op[0];
            int r = op[1];
            ll v = op[2];
            if (l <= r)
            {
                st.update(1, 0, n - 1, l, r, v);
            }
            else
            {
                st.update(1, 0, n - 1, 0, r, v);
                st.update(1, 0, n - 1, l, n - 1, v);
            }
        }
        else
        {
            int l = op[0];
            int r = op[1];
            ll ans;
            if (l <= r)
            {
                ans = st.query(1, 0, n - 1, l, r);
            }
            else
            {
                ans = min(
                    st.query(1, 0, n - 1, 0, r),
                    st.query(1, 0, n - 1, l, n - 1));
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
