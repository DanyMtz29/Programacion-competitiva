//https://codeforces.com/problemset/problem/356/A
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

/*
    > Struct crate by Daniel Juarez
    > modified on 02/03/2025
*/

struct segmentTree
{
    // segment tree vector
    vector<int> st;
    int n; // Size

    void init(int n)
    {
        this->n = n;         // tamanio del vector que manejaremos
        st.resize(4 * n, 0); // tamanio total del segment tree
    }

    void build(int start, int ending, int currentNode, vi &arr)
    { // private
        // Caso de Nodo hoja
        if (start == ending)
        {
            st[currentNode] = arr[start];
            return;
        }

        int mid = (start + ending) / 2; // Dividir el segment
        // SubArbol izquierdo
        build(start, mid, 2 * currentNode + 1, arr);

        // SubArbol derecho
        build(mid + 1, ending, 2 * currentNode + 2, arr);

        // Actualiza el currentNode con la suma maxima
        st[currentNode] = min(st[2 * currentNode + 1], st[2 * currentNode + 2]);
    }
    void build(vi &arr)
    { // public
        build(0, this->n - 1, 0, arr);
    }

    int query(int start, int ending, int l, int r, int currentNode)
    {
        // no hay superposicion de segmentos
        if (start > r || ending < l)
            return INT_MAX;

        // superposicion completa
        if (start >= l && ending <= r)
            return st[currentNode];

        // caso parcial
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * currentNode + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * currentNode + 2);
        return min(q1, q2);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int start, int ending, int currentNode, int index, int val)
    {
        // caso base
        if (start == ending)
        {
            st[currentNode] = INT_MAX;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid)
        { // el nodo se encuentra en el arbol izquierdo
            update(start, mid, 2 * currentNode + 1, index, val);
        }
        else
        { // el index a actualizar se encuentra en el arbol derecho
            update(mid + 1, ending, 2 * currentNode + 2, index, val);
        }

        // actualizar las sumas donde participa ese indice actualizado
        st[currentNode] = min(st[2 * currentNode + 1], st[2 * currentNode + 2]);
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

    int m, f;
    cin >> m >> f;
    segmentTree st;
    st.init(m);
    vi arr(m);
    for (int i = 0; i < m; i++)
    {
        arr[i] = i + 1;
    }
    vi ans(m + 1);
    st.build(arr);
    for (int i = 0; i < f; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--, x--;
        while (true)
        {
            int query = st.query(l, x - 1);
            if (query == INT_MAX)
                break;
            ans[query] = x + 1;
            st.update(query - 1, INT_MAX);
        }
        while (true)
        {
            int query = st.query(x + 1, r);
            if (query == INT_MAX)
                break;
            ans[query] = x + 1;

            st.update(query - 1, INT_MAX);
        }
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";

    cout << "\n";
    return 0;
}