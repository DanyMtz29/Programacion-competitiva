#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define INF INT_MIN
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

struct Node
{
    int minimo;
    int maximo;
    Node(int x, int y) : minimo(x), maximo(y) {}
};

struct SegmentTree
{
    int n;
    vector<int> lazy;
    vector<Node> st;
    SegmentTree(int _n) : n(_n), st(4 * n, {INT_MIN, INT_MAX}), lazy(4 * n, 0) {}

    void build(int node, int start, int end, const vector<int> &a)
    {
        if (start == end)
        {
            Node n(a[start], a[start]);
            st[node] = n;
            return;
        }
        int m = (start + end) >> 1;
        build(node << 1, start, m, a);
        build(node << 1 | 1, m + 1, end, a);
        Node n(min(st[node << 1].minimo, st[node << 1 | 1].minimo), max(st[node << 1].maximo, st[node << 1 | 1].maximo));
        st[node] = n;
    }

    void reset(int node, int start, int end, int l, int r, int M)
    {
        push(node, start, end);
        if (end < l || start > r)
            return;

        if (start >= l && end <= r)
        {

            if (st[node].maximo < M)
                return;

            if (st[node].maximo == st[node].minimo && st[node].maximo == M)
            {
                st[node].maximo = st[node].minimo = 0;
                if (start != end)
                {
                    lazy[node << 1] -= M;
                    lazy[node << 1 | 1] -= M;
                }
                return;
            }
            else
            {
                int m = (start + end) >> 1;
                push(node << 1, start, m);
                push(node << 1 | 1, m + 1, end);
                if (st[node << 1].maximo == M)
                {
                    reset(node << 1, start, m, l, r, M);
                }
                if (st[node << 1 | 1].maximo == M)
                {
                    reset(node << 1 | 1, m + 1, end, l, r, M);
                }
                st[node].minimo = min(st[node << 1].minimo, st[node << 1 | 1].minimo);
                st[node].maximo = max(st[node << 1].maximo, st[node << 1 | 1].maximo);
            }
        }
        else
        {
            int m = (start + end) >> 1;
            reset(node << 1, start, m, l, r, M);
            reset(node << 1 | 1, m + 1, end, l, r, M);
            st[node].minimo = min(st[node << 1].minimo, st[node << 1 | 1].minimo);
            st[node].maximo = max(st[node << 1].maximo, st[node << 1 | 1].maximo);
        }
    }

    void push(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            st[node].maximo += lazy[node];
            st[node].minimo += lazy[node];
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
        if (end < l || start > r)
            return;
        if (start >= l && end <= r)
        {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int m = (start + end) >> 1;
        update(node << 1, start, m, l, r, val);
        update(node << 1 | 1, m + 1, end, l, r, val);
        st[node].minimo = min(st[node << 1].minimo, st[node << 1 | 1].minimo);
        st[node].maximo = max(st[node << 1].maximo, st[node << 1 | 1].maximo);
    }

    int query(int node, int start, int end, int l, int r)
    {
        push(node, start, end);
        if (end < l || start > r)
            return INT_MIN;
        if (start >= l && end <= r)
            return st[node].maximo;

        int m = (start + end) >> 1;
        return max(
            query(node << 1, start, m, l, r),
            query(node << 1 | 1, m + 1, end, l, r));
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vi arr(n);
    forN(n, arr);
    SegmentTree st(n);
    st.build(1, 0, n - 1, arr);

    int M;
    while (q--)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'Q')
            cout << st.query(1, 0, n - 1, a - 1, b - 1) << "\n";
        else if (c == 'R')
        {
            M = st.query(1, 0, n - 1, 0, n - 1);
            st.reset(1, 0, n - 1, a - 1, b - 1, M);
        }
        else
            st.update(1, 0, n - 1, a - 1, b - 1, 1);
        }

    return 0;
}