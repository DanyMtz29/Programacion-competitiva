//Aun no resuelto
//https://codeforces.com/problemset/problem/242/E?mobile=false
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    vector<int> bits;
};

struct segmenttree
{
    int n;
    vector<Node> st;
    vector<int> lazy;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n);
        lazy.resize(4 * n, 0);
    }

    void check(Node &n, int val, int l, int r)
    {
        int sum = 0;
        int tam = r - l + 1;
        for (int i = 0; i < 30; i++)
            if ((val >> i) & 1)
            {
                int ones = tam - n.bits[i];
                sum += (ones - n.bits[i]) * pow(2, i);
                n.bits[i] = ones;
            }

        n.val += sum;
    }

    void build(int start, int ending, int node, vector<int> &v)
    {
        if (start == ending)
        {
            Node n;
            n.val = v[start];
            n.bits.resize(30, 0);

            for (int i = 0; i < 30; i++)
                n.bits[i] = ((n.val >> i) & 1);

            st[node] = n;
            return;
        }

        int mid = (start + ending) / 2;
        build(start, mid, 2 * node + 1, v);
        build(mid + 1, ending, 2 * node + 2, v);

        Node n;
        n.bits.resize(30, 0);

        for (int i = 0; i < 30; i++)
            n.bits[i] = st[node * 2 + 1].bits[i] + st[node * 2 + 2].bits[i];

        n.val = st[node * 2 + 1].val + st[node * 2 + 2].val;
        st[node] = n;
    }

    int query(int start, int ending, int l, int r, int node)
    {
        if (start > r || ending < l)
            return 0;

        if (lazy[node] != 0)
        {
            check(st[node], lazy[node], start, ending);
            if (start != ending)
            {
                lazy[2 * node + 1] ^= lazy[node];
                lazy[2 * node + 2] ^= lazy[node];
            }
            lazy[node] = 0;
        }
        if (start >= l && ending <= r)
        {
            return st[node].val;
        }
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return q1 + q2;
    }

    void update(int start, int ending, int node, int l, int r, int value)
    {
        if (start > r || ending < l)
        {
            return;
        }
        if (lazy[node] != 0)
        {
            check(st[node], lazy[node], start, ending);
            if (start != ending)
            {
                lazy[2 * node + 1] ^= lazy[node];
                lazy[2 * node + 2] ^= lazy[node];
            }
            lazy[node] = 0;
        }

        if (start >= l && ending <= r)
        {
            check(st[node], value, start, ending);
            if (start != ending)
            {
                lazy[2 * node + 1] ^= value;
                lazy[2 * node + 2] ^= value;
            }
            return;
        }

        int mid = (start + ending) / 2;

        update(start, mid, 2 * node + 1, l, r, value);
        update(mid + 1, ending, 2 * node + 2, l, r, value);

        for (int i = 0; i < 30; i++)
            st[node].bits[i] = st[node * 2 + 1].bits[i] + st[node * 2 + 2].bits[i];

        // check(st[node], value, l, r);
        st[node].val = st[node * 2 + 1].val + st[node * 2 + 2].val;

        if (start == 0 && ending == 1)
        {
            cout << "Val iz: " << st[2 * node + 1].val << endl;
            cout << "Valo der: " << st[2 * node + 2].val << endl;
            cout << "Valor mio: " << st[node].val << endl;
        }

        return;
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
    }
    void show()
    {
        cout << "\n"
             << endl;
        for (int i = 0; i < n; i++)
            cout << "lazy: " << lazy[i] << ", val: " << st[i].val << endl;
        cout << "" << endl;
    }
};

int main()
{
    segmenttree st;
    int n = 5;
    vector<int> arr = {4, 10, 3, 13, 7};
    st.init(n);
    st.build(arr);

    // cout << "2-4: " << st.query(1, 3) << endl;
    // st.show();
    st.update(0, 2, 3);
    cout << "1-3: " << st.query(0, 2) << endl;
    cout << "1-2: " << st.query(0, 1) << endl;
    cout << "2-3: " << st.query(1, 2) << endl;
    cout << "3-3: " << st.query(2, 2) << endl;
    cout << "2-2: " << st.query(1, 1) << endl;
    cout << "1-1: " << st.query(0, 0) << endl;

    st.update(1, 1, 5);
    cout << "1-3: " << st.query(0, 2) << endl;
    cout << "1-2: " << st.query(0, 1) << endl;
    cout << "2-3: " << st.query(1, 2) << endl;
    cout << "3-3: " << st.query(2, 2) << endl;
    cout << "2-2: " << st.query(1, 1) << endl;
    cout << "1-1: " << st.query(0, 0) << endl;

    // st.show();
    // cout << "2-4: " << st.query(1, 3) << endl;
    // cout << "3-3: " << st.query(2, 2) << endl;
    // st.show();
    // cout << "1-5: " << st.query(0, 4) << endl;
    // st.update(1, 4, 5);
    st.show();
    // cout << "1-5: " << st.query(0, 4) << endl;
    //  st.update(0, 1, 10);
    //  cout << "2-3: " << st.query(1, 2) << endl;
    return 0;
}