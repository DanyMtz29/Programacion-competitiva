//https://codeforces.com/problemset/problem/459/D
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MAXN = 1e6 + 1;

struct segmentTree
{
    vector<int> st;
    int n;

    void init(int n)
    {
        this->n = n;
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int currentNode, vector<int> &vec)
    {
        if (start == ending)
        {
            st[currentNode] = vec[start];
            return;
        }

        int mid = (start + ending) / 2;
        build(start, mid, 2 * currentNode + 1, vec);

        build(mid + 1, ending, 2 * currentNode + 2, vec);

        st[currentNode] = st[2 * currentNode + 1] + st[2 * currentNode + 2];
    }
    void build(vector<int> &vec)
    {
        build(0, this->n - 1, 0, vec);
    }

    int query(int start, int ending, int l, int r, int currentNode)
    {
        if (start > r || ending < l)
            return 0;

        if (start >= l && ending <= r)
            return st[currentNode];

        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * currentNode + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * currentNode + 2);
        return q1 + q2;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int start, int ending, int currentNode, int index, int val)
    {
        if (start == ending)
        {
            st[currentNode] += val;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid)
        {
            update(start, mid, 2 * currentNode + 1, index, val);
        }
        else
        {
            update(mid + 1, ending, 2 * currentNode + 2, index, val);
        }
        st[currentNode] = st[2 * currentNode + 1] + st[2 * currentNode + 2];
    }
    void update(int index, int val)
    {
        update(0, n - 1, 0, index, val);
    }

    void show()
    {
        copy(st.begin(), st.end(), ostream_iterator<int>(cout, "|"));
        cout << endl;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> l(N);
    vector<int> r(N);
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        int element;
        cin >> element;
        arr[i] = element;
        mp[element]++;
        l[i] = mp[element];
    }
    mp.clear();
    for (int i = N - 1; i >= 0; i--)
    {
        mp[arr[i]]++;
        r[i] = mp[arr[i]];
    }

    segmentTree st;

    st.init(MAXN);

    for (int fr : r)
        st.update(fr, 1);

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        st.update(r[i], -1);
        int query = st.query(1, l[i] - 1);
        ans += query;
    }

    cout << ans << endl;

    return 0;
}