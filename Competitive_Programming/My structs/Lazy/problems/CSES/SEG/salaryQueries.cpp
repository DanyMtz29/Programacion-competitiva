#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define umii unordered_map<int, int>
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

struct Segment
{
    vi st;
    Segment(int _n) : st(4 * _n) {}

    void update(int node, int start, int end, int index, int val)
    {
        if (start == end)
        {
            st[node] += val;
            return;
        }

        int mid = (start + end) >> 1;
        if (index <= mid)
            update(node << 1, start, mid, index, val);
        else
            update(node << 1 | 1, mid + 1, end, index, val);
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
    void show()
    {
        cout << "SEGMENT" << endl;
        for (int i = 0; i < 15; i++)
            cout << st[i] << " ";
        cout << "" << endl;
    }
};

struct Op
{
    char c;
    int a, b;
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vi arr(n);
    vi alls;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        alls.push_back(arr[i]);
    }

    vector<Op> ops(q);
    for (int i = 0; i < q; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        Op o;
        o.c = c, o.a = a, o.b = b;
        ops[i] = o;
        if (c == '?')
        {
            alls.push_back(a);
            alls.push_back(b);
        }
        else
            alls.push_back(b);
    }

    sort(alls.begin(), alls.end());
    eraseU(alls);

    umii mp;
    int sz = alls.size();
    for (int i = 0; i < sz; i++)
        mp[alls[i]] = i;

    Segment st(sz);
    // Contruir el segment tree
    for (int i = 0; i < n; i++)
        st.update(1, 0, sz - 1, mp[arr[i]], 1);

    for (auto ope : ops)
    {
        if (ope.c == '!')
        {
            st.update(1, 0, sz - 1, mp[ope.b], 1);
            int index = mp[arr[ope.a - 1]];
            st.update(1, 0, sz - 1, index, -1);
            arr[ope.a - 1] = ope.b;
        }
        else
        {
            int l = mp[ope.a];
            int r = mp[ope.b];
            cout << st.query(1, 0, sz - 1, l, r) << endl;
        }
    }
    return 0;
}