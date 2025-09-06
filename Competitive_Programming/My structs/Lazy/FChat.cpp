#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree
{
    int n;
    vector<ll> stMin, stMax;
    vector<ll> lazyAdd;
    vector<ll> lazySet;
    vector<bool> hasSet;

    SegmentTree(int _n)
        : n(_n),
          stMin(4 * n, 0),
          stMax(4 * n, 0),
          lazyAdd(4 * n, 0),
          lazySet(4 * n, 0),
          hasSet(4 * n, false)
    {
    }
    void build(int p, int l, int r, const vector<ll> &a)
    {
        if (l == r)
        {
            stMin[p] = stMax[p] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        stMin[p] = min(stMin[p << 1], stMin[p << 1 | 1]);
        stMax[p] = max(stMax[p << 1], stMax[p << 1 | 1]);
    }
    void push(int p, int l, int r)
    {
        if (hasSet[p])
        {
            stMin[p] = stMax[p] = lazySet[p];
            if (l < r)
            {
                int lc = p << 1, rc = p << 1 | 1;
                hasSet[lc] = hasSet[rc] = true;
                lazySet[lc] = lazySet[rc] = lazySet[p];
                lazyAdd[lc] = lazyAdd[rc] = 0;
            }
            hasSet[p] = false;
        }
        if (lazyAdd[p] != 0)
        {
            stMin[p] += lazyAdd[p];
            stMax[p] += lazyAdd[p];
            if (l < r)
            {
                int lc = p << 1, rc = p << 1 | 1;
                lazyAdd[lc] += lazyAdd[p];
                lazyAdd[rc] += lazyAdd[p];
            }
            lazyAdd[p] = 0;
        }
    }

    void rangeAdd(int p, int l, int r, int i, int j, ll v)
    {
        push(p, l, r);
        if (r < i || l > j)
            return;
        if (l >= i && r <= j)
        {
            lazyAdd[p] += v;
            push(p, l, r);
            return;
        }
        int m = (l + r) >> 1;
        rangeAdd(p << 1, l, m, i, j, v);
        rangeAdd(p << 1 | 1, m + 1, r, i, j, v);
        stMin[p] = min(stMin[p << 1], stMin[p << 1 | 1]);
        stMax[p] = max(stMax[p << 1], stMax[p << 1 | 1]);
    }

    // Consulta máximo en [i,j]
    ll queryMax(int p, int l, int r, int i, int j)
    {
        push(p, l, r);
        if (r < i || l > j)
            return LLONG_MIN;
        if (l >= i && r <= j)
            return stMax[p];
        int m = (l + r) >> 1;
        return max(
            queryMax(p << 1, l, m, i, j),
            queryMax(p << 1 | 1, m + 1, r, i, j));
    }

    void resetMax(int p, int l, int r, int i, int j, ll M)
    {
        push(p, l, r);
        if (r < i || l > j || stMax[p] < M)
            return;
        if (l >= i && r <= j && stMin[p] == M && stMax[p] == M)
        {
            // Asign zero
            hasSet[p] = true;
            lazySet[p] = 0;
            lazyAdd[p] = 0;
            push(p, l, r);
            return;
        }
        int m = (l + r) >> 1;
        resetMax(p << 1, l, m, i, j, M);
        resetMax(p << 1 | 1, m + 1, r, i, j, M);
        stMin[p] = min(stMin[p << 1], stMin[p << 1 | 1]);
        stMax[p] = max(stMax[p << 1], stMax[p << 1 | 1]);
    }

    // public
    void build(const vector<ll> &a)
    {
        build(1, 1, n, a);
    }
    void add(int i, int j, ll v = 1) { rangeAdd(1, 1, n, i, j, v); }
    ll maxQuery(int i, int j) { return queryMax(1, 1, n, i, j); }
    void resetMaxRange(int i, int j)
    {
        ll M = maxQuery(1, n);
        resetMax(1, 1, n, i, j, M);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<ll> B(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    SegmentTree st(N);
    st.build(B);

    while (K--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == 'Q')
        {
            cout << st.maxQuery(l, r) << '\n';
        }
        else if (c == 'A')
        {
            st.add(l, r, 1);
        }
        else if (c == 'R')
        {
            st.resetMaxRange(l, r);
        }
    }

    return 0;
}
