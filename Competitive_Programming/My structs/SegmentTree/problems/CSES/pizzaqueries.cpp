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
#define INFS 1e18
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define pb push_back
#define F first
#define S second
const int MOD = 1e9 + 7;
using namespace std;

struct Segment
{
    //{A,B}
    vector<pi> st;
    int n;
    void init(int _n)
    {
        this->n = _n;
        this->st.resize(4 * n, {INFS, INFS});
    }

    void build(int node, int start, int end, vi &a)
    {
        if (start == end)
        {
            st[node] = {a[start] + start, a[start] - start};
            return;
        }

        int mid = (start + end) >> 1;
        build(node << 1, start, mid, a);
        build(node << 1 | 1, mid + 1, end, a);
        int A = min(st[node << 1].F, st[node << 1 | 1].F);
        int B = min(st[node << 1].S, st[node << 1 | 1].S);
        st[node] = {A, B};
    }

    pi query(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return {INFS, INFS};
        if (start >= l && end <= r)
            return st[node];
        int mid = (start + end) >> 1;
        auto qryLeft = query(node << 1, start, mid, l, r);
        auto qryRight = query(node << 1 | 1, mid + 1, end, l, r);
        int A = min(qryLeft.F, qryRight.F);
        int B = min(qryLeft.S, qryRight.S);
        return {A, B};
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            st[node] = {val + idx, val - idx};
            return;
        }

        int mid = (start + end) >> 1;
        if (idx <= mid)
            update(node << 1, start, mid, idx, val);
        else
            update(node << 1 | 1, mid + 1, end, idx, val);
        int A = min(st[node << 1].F, st[node << 1 | 1].F);
        int B = min(st[node << 1].S, st[node << 1 | 1].S);
        st[node] = {A, B};
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        vi a(n);
        forN(n, a);
        Segment st;
        st.init(n);
        st.build(1, 0, n - 1, a);

        while (q--)
        {
            int opt;
            cin >> opt;
            if (opt == 1)
            {
                int idx, val;
                cin >> idx >> val;
                st.update(1, 0, n - 1, idx - 1, val);
            }
            else
            {
                int k;
                cin >> k;
                k--;
                int A = st.query(1, 0, n - 1, k, n - 1).F - k;
                int B = st.query(1, 0, n - 1, 0, k).S + k;
                cout << min(A, B) << "\n";
            }
        }
    }
    return 0;
}