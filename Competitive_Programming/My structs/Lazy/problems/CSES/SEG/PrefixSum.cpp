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

struct Node
{
    int sum;
    int maxSum;
};

struct Segment
{
    vector<Node> st;
    Segment(int _n) : st(4 * _n) {}

    void build(int node, int start, int end, vi &A)
    {
        if (start == end)
        {
            Node n;
            n.maxSum = max(0ll, A[start]);
            n.sum = A[start];
            st[node] = n;
            return;
        }

        int mid = (start + end) >> 1;
        build(node << 1, start, mid, A);
        build(node << 1 | 1, mid + 1, end, A);

        Node n;
        n.sum = st[node << 1].sum + st[node << 1 | 1].sum;
        // n.maxSum = max({n.sum, st[node << 1].maxSum, st[node << 1 | 1].maxSum});
        n.maxSum = max(st[node << 1].maxSum, st[node << 1].sum + st[node << 1 | 1].maxSum);
        st[node] = n;
    }

    Node query(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return {0, 0};
        if (start >= l && end <= r)
            return st[node];
        int mid = (start + end) >> 1;
        auto n1 = query(node << 1, start, mid, l, r);
        auto n2 = query(node << 1 | 1, mid + 1, end, l, r);
        Node aux;
        aux.sum = n1.sum + n2.sum;

        aux.maxSum = max(n1.maxSum, n1.sum + n2.maxSum);

        return aux;
    }

    void update(int node, int start, int end, int index, int val)
    {
        if (start == end)
        {
            st[node].maxSum = max(0ll, val);
            st[node].sum = val;
            return;
        }

        int mid = (start + end) >> 1;
        if (index <= mid)
            update(node << 1, start, mid, index, val);
        else
            update(node << 1 | 1, mid + 1, end, index, val);

        st[node].sum = st[node << 1].sum + st[node << 1 | 1].sum;
        st[node].maxSum = max(st[node << 1].maxSum, st[node << 1].sum + st[node << 1 | 1].maxSum);
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vi arr(n);
    forN(n, arr);
    Segment st(n);
    st.build(1, 0, n - 1, arr);
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 2)
            cout << st.query(1, 0, n - 1, b - 1, c - 1).maxSum << "\n";
        else
            st.update(1, 0, n - 1, b - 1, c);
    }
    return 0;
}