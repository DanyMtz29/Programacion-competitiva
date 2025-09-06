#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, version, index;
    bool original; // Indica si la arista es original o invertida
};

struct State {
    int node, changes, versionIndex;
    bool operator>(const State& other) const {
        return changes > other.changes; // Min-heap basado en cambios mínimos
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<Edge>> graph(n + 1);
    vector<tuple<int, int, int>> edges;
    
    // Leer los programas de ruta
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t, i, true});
        graph[v].push_back({u, t, i, false}); // Arista invertida opcional
        edges.push_back({u, v, t});
    }
    
    // Ordenar los programas de ruta por versión `ti`
    sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<2>(a) < get<2>(b);
    });

    // Dijkstra Modificado con Min-Heap
    priority_queue<State, vector<State>, greater<State>> pq;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, INT_MAX));

    pq.push({1, 0, 0});
    dist[1][0] = 0;

    while (!pq.empty()) {
        auto [node, changes, versionIdx] = pq.top();
        pq.pop();

        if (node == n) {
            cout << changes << "\n";
            return;
        }

        for (auto& edge : graph[node]) {
            int nextNode = edge.to;
            int newVersionIdx = upper_bound(edges.begin(), edges.end(), make_tuple(0, 0, edge.version), 
                            [](const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) {
                                return get<2>(lhs) < get<2>(rhs);
                            }) - edges.begin();

            if (newVersionIdx > versionIdx && dist[nextNode][newVersionIdx] > changes + !edge.original) {
                dist[nextNode][newVersionIdx] = changes + !edge.original;
                pq.push({nextNode, changes + !edge.original, newVersionIdx});
            }
        }
    }

    cout << "-1\n"; // Si no se encuentra un camino válido
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
