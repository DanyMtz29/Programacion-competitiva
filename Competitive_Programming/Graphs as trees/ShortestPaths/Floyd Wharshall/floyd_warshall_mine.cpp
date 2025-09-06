#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int, int>
#define INFS 1e9
#define INFI -1e9
const int MOD = 1e9 + 7;
using namespace std;

void floyd(vvi &m, int V){
    // Recorrer cada ciudad como intermedia
    for (int k = 1; k < V; k++){
        // Recorrer las aristas que conectan cada vertice, con k intermedio
        for (int i = 1; i <= V; i++){
            // Si hay una distancia menor entre ciudades, se guarda en la matriz de adyacencia.
            for (int j = 1; j < V; j++)
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--){
    }
    return 0;
}