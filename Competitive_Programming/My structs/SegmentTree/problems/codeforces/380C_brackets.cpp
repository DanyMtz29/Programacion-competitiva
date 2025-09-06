//https://codeforces.com/problemset/problem/380/C
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

struct Aux
{
    int hechos;
    int lefts;
    int rights;
};

struct segmentTree
{
    // segment tree vector
    vector<Aux> st;
    int n; // Size

    void init(int n)
    {
        this->n = n;
        st.resize(4 * n, {});
    }

    void build(int start, int ending, int currentNode, string &s)
    { // private
        // Caso de Nodo hoja
        if (start == ending)
        {
            Aux a;
            a.hechos = 0;
            a.lefts = s[start] == '(';
            a.rights = s[start] == ')';
            st[currentNode] = a;
            return;
        }

        int mid = (start + ending) / 2; // Dividir el segment
        // SubArbol izquierdo
        build(start, mid, 2 * currentNode + 1, s);

        // SubArbol derecho
        build(mid + 1, ending, 2 * currentNode + 2, s);

        // Actualiza el currentNode con la suma maxima
        // st[currentNode] = st[2 * currentNode + 1] + st[2 * currentNode + 2];
        Aux a;
        int NEW = min(st[currentNode * 2 + 1].lefts, st[currentNode * 2 + 2].rights);

        a.hechos = st[currentNode * 2 + 1].hechos + st[currentNode * 2 + 2].hechos + NEW;
        a.lefts = st[currentNode * 2 + 1].lefts + st[currentNode * 2 + 2].lefts - NEW;
        a.rights = st[currentNode * 2 + 1].rights + st[currentNode * 2 + 2].rights - NEW;

        st[currentNode] = a;
    }
    void build(string &s)
    { // public
        build(0, this->n - 1, 0, s);
    }

    Aux query(int start, int ending, int l, int r, int currentNode)
    {
        // no hay superposicion de segmentos
        if (start > r || ending < l)
            return {0, 0};

        // superposicion completa
        if (start >= l && ending <= r)
        {
            return st[currentNode];
        }

        // caso parcial
        int mid = (start + ending) / 2;

        auto q1 = query(start, mid, l, r, 2 * currentNode + 1);
        auto q2 = query(mid + 1, ending, l, r, 2 * currentNode + 2);

        int NEW = min(q1.lefts, q2.rights);
        q1.hechos += q2.hechos + NEW;
        q1.lefts += (q2.lefts - NEW);
        q1.rights += (q2.rights - NEW);
        return q1;
    }

    Aux query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    segmentTree st;
    st.init(s.size());
    st.build(s);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        auto q = st.query(l - 1, r - 1);
        cout << q.hechos * 2 << endl;
    }

    return 0;
}