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

    void build(int node, int start, int end, vector<int> &a){
        if (start == end){
            st[node] = a[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(node << 1, start, mid, a);
        build(node << 1 | 1, mid + 1, end, a);
        st[node] = max(st[node << 1], st[node << 1 | 1]);
    }

    int update(int node, int start, int end, int val){
        if (st[node] < val)
            return 0;
        if (start == end){
            st[node] -= val;
            return start + 1;
        }
        int mid = (start + end) >> 1;
        int ret = -1234;
        if (val <= st[node << 1])
            ret = update(node << 1, start, mid, val);
        else
            ret = update(node << 1 | 1, mid + 1, end, val);
        st[node] = max(st[node << 1], st[node << 1 | 1]);
        return ret;
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
    Segment st(n);
    st.build(1, 0, n - 1, arr);

    while (q--){
        int v;
        cin >> v;
        cout << st.update(1, 0, n - 1, v) << endl;
    }
    return 0;
}