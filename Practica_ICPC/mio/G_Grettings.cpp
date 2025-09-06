#include <bits/stdc++.h>
using namespace std;

struct segmentTree {
    vector<int> st;
    int n;

    void init(int n) {
        this->n = n;
        st.resize(4 * n, 0);
    }

    int query(int start, int ending, int l, int r, int currentNode) {
        if (start > r || ending < l) return 0;
        if (start >= l && ending <= r) return st[currentNode];

        int mid = (start + ending) / 2;
        int q1 = query(start, mid, l, r, 2 * currentNode + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * currentNode + 2);
        return q1 + q2;
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(0, n - 1, l, r, 0);
    }

    void update(int start, int ending, int currentNode, int index, int val) {
        if (start == ending) {
            st[currentNode] += val;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            update(start, mid, 2 * currentNode + 1, index, val);
        } else {
            update(mid + 1, ending, 2 * currentNode + 2, index, val);
        }

        st[currentNode] = st[2 * currentNode + 1] + st[2 * currentNode + 2];
    }

    void update(int index, int val) {
        update(0, n - 1, 0, index, val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> arr(N);
        vector<int> valores;

        // Leer entrada y almacenar b_i
        for (int i = 0; i < N; i++) {
            int inicio, fin;
            cin >> inicio >> fin;
            arr[i] = {inicio, fin};
            valores.push_back(fin);
        }

        // Compresión de coordenadas
        sort(valores.begin(), valores.end());
        valores.erase(unique(valores.begin(), valores.end()), valores.end());

        unordered_map<int, int> compresion;
        for (int i = 0; i < valores.size(); i++) {
            compresion[valores[i]] = i + 1; // Mapear b_i a índice 1-based
        }

        // Reemplazar b_i con su índice comprimido
        for (auto& p : arr) {
            p.second = compresion[p.second];
        }

        // Ordenar por `a_i`
        sort(arr.begin(), arr.end());

        //Segment Tree
        segmentTree seg;
        seg.init(valores.size() + 1); // +1 para evitar problemas de índices

        long long total_saludos = 0;

        // Contar inversiones con Segment Tree
        for (auto& p : arr) {
            int bi_comprimido = p.second; // Índice comprimido de b_i

            // 🔹 CORRECCIÓN: Asegurar que consultamos hasta `valores.size()`
            if (bi_comprimido < valores.size()) {
                total_saludos += seg.query(bi_comprimido + 1, valores.size());
            }

            // 🔹 CORRECCIÓN: Insertar correctamente en el Segment Tree
            seg.update(bi_comprimido, 1);
        }

        // Imprimir resultado
        cout << total_saludos << "\n";
    }

    return 0;
}
