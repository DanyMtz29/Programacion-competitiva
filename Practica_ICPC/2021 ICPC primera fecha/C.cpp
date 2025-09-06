#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 1e6;
vector<int> arr(N + 1, 0);

struct segmentTree
{
    vector<int> st;
    int n; // Size

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
            st[currentNode] = val;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid)
            update(start, mid, 2 * currentNode + 1, index, val);
        else
            update(mid + 1, ending, 2 * currentNode + 2, index, val);
        st[currentNode] = st[2 * currentNode + 1] + st[2 * currentNode + 2];
    }
    void update(int index, int val)
    {
        update(0, n - 1, 0, index, val);
    }
};

segmentTree st;

void preSieve()
{
    st.init(N);
    for (int i = 2; i <= N; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = 1;
            st.update(i, 1);
            for (int j = i * i; j <= N; j += i)
            {
                arr[j] = 1;
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    preSieve();
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;

        cout << st.query(l, r) << endl;
    }
    return 0;
}