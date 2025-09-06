//https://codeforces.com/contest/474/problem/F
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define sl(c) st[c * 2 + 1]
#define sr(c) st[c * 2 + 2]
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

struct Node
{
    bool win;
    int val;
    int rep;
};
struct segmentTree
{
    // segment tree vector
    vector<Node> st;
    int n; // Size

    void init(int n)
    {
        this->n = n;          // tamanio del vector que manejaremos
        st.resize(4 * n, {}); // tamanio total del segment tree
    }

    Node make(Node &n1, Node &n2)
    {
        Node node;
        int g = gcd(n1.val, n2.val);
        if (n1.win && n2.win)
        {
            if (g == n1.val && n1.val == n2.val)
            {
                node.win = 1;
                node.rep = n1.rep + n2.rep;
                node.val = n1.val;
            }
            else
            {
                if (g == n2.val)
                {
                    node.val = n2.val;
                    node.win = 1;
                    node.rep = n2.rep;
                }
                else if (g == n1.val)
                {
                    node.val = n1.val;
                    node.win = 1;
                    node.rep = n1.rep;
                }
                else
                {
                    node.val = g;
                    node.win = 0;
                    node.rep = 0;
                }
            }
        }
        else if (n1.win)
        {
            if (g == n1.val)
            {
                node.val = n1.val;
                node.rep = n1.rep;
                node.win = 1;
            }
            else
            {
                node.val = g;
                node.rep = 0;
                node.win = 0;
            }
        }
        else if (n2.win)
        {
            if (g == n2.val)
            {
                node.val = n2.val;
                node.rep = n2.rep;
                node.win = 1;
            }
            else
            {
                node.val = g;
                node.rep = 0;
                node.win = 0;
            }
        }
        else
        {
            node.val = g;
            node.rep = 0;
            node.win = 0;
        }
        return node;
    }

    void build(int start, int ending, int currentNode, vector<int> &vec)
    { // private
        // Caso de Nodo hoja
        if (start == ending)
        {
            Node node;
            node.win = 1;
            node.val = vec[start];
            node.rep = 1;
            st[currentNode] = node;
            return;
        }

        int mid = (start + ending) / 2; // Dividir el segment
        // SubArbol izquierdo
        build(start, mid, 2 * currentNode + 1, vec);

        // SubArbol derecho
        build(mid + 1, ending, 2 * currentNode + 2, vec);

        // Actualiza el currentNode con la suma maxima
        Node node = make(sl(currentNode), sr(currentNode));

        st[currentNode] = node;
    }
    void build(vector<int> &vec)
    { // public
        build(0, this->n - 1, 0, vec);
    }

    Node query(int start, int ending, int l, int r, int currentNode)
    {
        // no hay superposicion de segmentos
        if (start > r || ending < l)
        {
            Node a;
            a.rep = 0;
            a.win = 0;
            a.val = 0;
            return a;
        }

        // superposicion completa
        if (start >= l && ending <= r)
            return st[currentNode];

        // caso parcial
        int mid = (start + ending) / 2;

        auto q1 = query(start, mid, l, r, 2 * currentNode + 1);
        auto q2 = query(mid + 1, ending, l, r, 2 * currentNode + 2);
        return make(q1, q2);
    }

    Node query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vi arr(n);
    forN(n, arr);
    segmentTree st;
    st.init(n);
    st.build(arr);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << ((r - l) - st.query(l - 1, r - 1).rep) + 1 << endl;
    }

    return 0;
}
