//https://codeforces.com/problemset/problem/61/E
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define all(v) v.begin(), v.end()
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

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

    void build(int start, int ending, int currentNode, vector<int> &vec)
    { // private
        // Caso de Nodo hoja
        if (start == ending)
        {
            st[currentNode] = vec[start];
            return;
        }

        int mid = (start + ending) / 2; // Dividir el segment
        // SubArbol izquierdo
        build(start, mid, 2 * currentNode + 1, vec);

        // SubArbol derecho
        build(mid + 1, ending, 2 * currentNode + 2, vec);

        // Actualiza el currentNode con la suma maxima
        st[currentNode] = st[2 * currentNode + 1] + st[2 * currentNode + 2];
    }
    void build(vector<int> &vec)
    { // public
        build(0, this->n - 1, 0, vec);
    }

    int query(int start, int ending, int l, int r, int currentNode)
    {
        // no hay superposicion de segmentos
        if (start > r || ending < l)
            return 0;

        // superposicion completa
        if (start >= l && ending <= r)
            return st[currentNode];

        // caso parcial
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
        // caso base
        if (start == ending)
        {
            st[currentNode] = val;
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
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi original(n);
    forN(n, original);

    vi sorted(all(original));

    sort(all(sorted));
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[sorted[i]] = i;

    vi ans(n, 0);

    segmentTree st;
    st.init(n);

    for (int i = 0; i < n; i++)
    {
        ans[i] += st.query(mp[original[i]], n - 1);
        st.update(mp[original[i]], 1);
    }

    // 0 1 2 2 3 4

    vi arr(n, 1);
    st.build(arr);
    for (int i = 0; i < n; i++)
    {
        ans[i] *= st.query(0, mp[original[i]] - 1);
        st.update(mp[original[i]], 0);
    }
    // 0 4 0 4 3 0

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer += ans[i];
    }
    cout << answer << endl;

    return 0;
}