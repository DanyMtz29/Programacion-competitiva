//https://codeforces.com/problemset/problem/145/E
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
const int MOD = 1e9 + 7;
using namespace std;

struct Node
{
    int s4;
    int s7;
    int sub;
    int decSub;
};

struct Segment
{
    vector<Node> st;
    vector<bool> lazy;
    int n;
    void init(int _n)
    {
        this->n = _n;
        this->st.resize(4 * n, {});
        this->lazy.resize(4 * n, false);
    }

    void push(int node, int start, int end)
    {
        if (lazy[node])
        {
            int temp = st[node].s4;
            st[node].s4 = st[node].s7;
            st[node].s7 = temp;
            temp = st[node].sub;
            st[node].sub = st[node].decSub;
            st[node].decSub = temp;
            if (start != end)
            {
                lazy[node << 1] = !lazy[node << 1];
                lazy[node << 1 | 1] = !lazy[node << 1 | 1];
            }
            lazy[node] = 0;
        }
    }

    void build(int node, int start, int end, vi &arr)
    {
        if (start == end)
        {
            Node n;
            n.s4 = arr[start] == 4;
            n.s7 = arr[start] == 7;
            n.sub = 1;
            n.decSub = 1;
            st[node] = n;
            return;
        }
        int m = (start + end) >> 1;
        build(node << 1, start, m, arr);
        build(node << 1 | 1, m + 1, end, arr);
        Node n;
        n.s4 = st[node << 1].s4 + st[node << 1 | 1].s4;
        n.s7 = st[node << 1].s7 + st[node << 1 | 1].s7;
        n.sub = max(st[node << 1].s4 + st[node << 1 | 1].sub, st[node << 1].sub + st[node << 1 | 1].s7);
        n.decSub = max(st[node << 1].s7 + st[node << 1 | 1].decSub, st[node << 1].decSub + st[node << 1 | 1].s4);
        st[node] = n;
    }
    Node qry(int node, int start, int end, int l, int r)
    {
        push(node, start, end);
        if (start > r || end < l)
            return {0, 0, 0};
        if (start >= l && end <= r)
            return st[node];

        int m = (start + end) >> 1;
        auto q1 = qry(node << 1, start, m, l, r);
        auto q2 = qry(node << 1 | 1, m + 1, end, l, r);

        Node n;
        n.s4 = q1.s4 + q2.s4;
        n.s7 = q1.s7 + q2.s7;
        n.sub = max(q1.s4 + q2.sub, q1.sub + q2.s7);
        return n;
    }
    void upd(int node, int start, int end, int l, int r)
    {
        push(node, start, end);
        if (start > r || end < l)
            return;
        if (start >= l && end <= r)
        {
            lazy[node] = !lazy[node];
            push(node, start, end);
            return;
        }
        int m = (start + end) >> 1;
        upd(node << 1, start, m, l, r);
        upd(node << 1 | 1, m + 1, end, l, r);

        st[node].s4 = st[node << 1].s4 + st[node << 1 | 1].s4;
        st[node].s7 = st[node << 1].s7 + st[node << 1 | 1].s7;
        st[node].sub = max(st[node << 1].s4 + st[node << 1 | 1].sub, st[node << 1].sub + st[node << 1 | 1].s7);
        st[node].decSub = max(st[node << 1].s7 + st[node << 1 | 1].decSub, st[node << 1].decSub + st[node << 1 | 1].s4);
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
    string nums;
    cin >> nums;
    for (int i = 0; i < n; i++)
        arr[i] = nums[i] - '0';

    Segment st;
    st.init(n);
    st.build(1, 0, n - 1, arr);

    cin.ignore();
    while (q--)
    {
        string s;
        getline(cin, s);
        if (s[0] == 'c')
            cout << st.qry(1, 0, n - 1, 0, n - 1).sub << endl;
        else
        {
            stringstream ss(s);

            string cmd;
            int l, r;
            ss >> cmd >> l >> r;
            st.upd(1, 0, n - 1, l - 1, r - 1);
        }
    }

    return 0;
}