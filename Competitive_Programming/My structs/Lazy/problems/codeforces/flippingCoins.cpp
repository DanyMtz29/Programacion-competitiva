//No me acuerdo del link
#include <bits/stdc++.h>

using namespace std;

// summation
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

    int query(int start, int ending, int l, int r, int node)
    {
        // non overlapping case
        if (start > r || ending < l)
        {
            return 0;
        }

        // lazy propagation / clear the lazy update
        if (lazy[node] != 0)
        {
            // pending updates
            // update the segment tree node
            // st[node] += lazy[node] * (ending - start + 1);
            st[node] = (ending - start + 1) - st[node];
            if (start != ending)
            {
                // propagate the updated value
                lazy[2 * node + 1] = lazy[2 * node + 1] == 1 ? 0 : 1;
                lazy[2 * node + 2] = lazy[2 * node + 2] == 1 ? 0 : 1;
            }
            lazy[node] = 0;
        }

        // complete overlap
        if (start >= l && ending <= r)
        {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return q1 + q2;
    }

    void update(int start, int ending, int node, int l, int r)
    {
        // non overlapping case
        if (start > r || ending < l)
        {
            return;
        }

        // lazy propagation / clear the lazy update
        if (lazy[node] != 0)
        {
            // pending updates
            // update the segment tree node
            // st[node] += lazy[node] * (ending - start + 1);
            st[node] = (ending - start + 1) - st[node];
            if (start != ending)
            {
                // propagate the updated value
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // complete overlap
        if (start >= l && ending <= r)
        {
            // cout << "\nEntra" << endl;
            // cout << "Start: " << start << endl;
            // cout << "Ending: " << ending << endl;
            // st[node] += value * (ending - start + 1);
            st[node] = (ending - start + 1) - st[node];
            if (start != ending)
            {
                lazy[2 * node + 1] = 1;
                lazy[2 * node + 2] = 1;
            }
            return;
        }

        // partial case
        int mid = (start + ending) / 2;

        update(start, mid, 2 * node + 1, l, r);

        update(mid + 1, ending, 2 * node + 2, l, r);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];

        return;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int l, int r)
    {
        update(0, n - 1, 0, l, r);
    }
    void show()
    {
        cout << "\nSegmentTree" << endl;
        copy(st.begin(), st.end(), ostream_iterator<int>(cout, "|"));
        cout << "" << endl;
        cout << "Lazy" << endl;
        copy(lazy.begin(), lazy.end(), ostream_iterator<int>(cout, "|"));
        cout << "" << endl;
    }
};

int main()
{

    int n = 4;
    segmenttree st;
    st.init(n);

    cout << "0-3: " << st.query(0, 3) << endl;
    st.update(1, 2);
    st.show();
    cout << "0-1: " << st.query(0, 1) << endl;
    st.show();
    cout << "0-0: " << st.query(0, 0) << endl;
    st.update(0, 3);
    st.show();
    cout << "0-3: " << st.query(0, 3) << endl;
    cout << "1-3: " << st.query(1, 3) << endl;

    return 0;
}