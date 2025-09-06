#include <bits/stdc++.h>
using namespace std;

// Segment Tree para eliminar el k-ésimo elemento vivo en una lista
struct Segment
{
    int n;
    vector<int> st;

    Segment(int _n) : n(_n)
    {
        st.assign(4 * n, 0);
    }

    // Construye el árbol con 1 en cada posición [0..n-1]
    void build(int p, int L, int R)
    {
        if (L == R)
        {
            st[p] = 1;
        }
        else
        {
            int m = (L + R) >> 1;
            build(p << 1, L, m);
            build(p << 1 | 1, m + 1, R);
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
    }

    // Encuentra la posición (0-indexed) del k-ésimo "1"
    int find_kth(int p, int L, int R, int k)
    {
        if (L == R)
            return L;
        int left_count = st[p << 1];
        int m = (L + R) >> 1;
        if (k <= left_count)
            return find_kth(p << 1, L, m, k);
        else
            return find_kth(p << 1 | 1, m + 1, R, k - left_count);
    }

    // Actualiza la posición idx (0-indexed) a val (0 o 1)
    void update(int p, int L, int R, int idx, int val)
    {
        if (L == R)
        {
            st[p] = val;
        }
        else
        {
            int m = (L + R) >> 1;
            if (idx <= m)
                update(p << 1, L, m, idx, val);
            else
                update(p << 1 | 1, m + 1, R, idx, val);
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    Segment st(n);
    st.build(1, 0, n - 1);

    // Procesar cada eliminación
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int pos = st.find_kth(1, 0, n - 1, k);
        cout << A[pos] << (i + 1 < n ? ' ' : '\n');
        st.update(1, 0, n - 1, pos, 0);
    }

    return 0;
}
