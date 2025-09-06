/*
    Problem: https://www.spoj.com/problems/SUMFOUR/
    La idea de resolver este problema fue por medio del tema meet-in-the-middle
    Se utilizaron dos arreglos, lefts y rights. Lefts tenia la suma de los arreglo A y B
    y rights tenia la suma de los arreglos C y D

    Se pensaron dos ideas que no funcionaron por que n era muy grande:
    1. Ordenar el arreglo derecho, despues iterar por cada elemento en left y hacer una busqueda
    binaria por rango para encontrar el total de elementos que coincidan con el complemento del elemento en left
    2. Usar un mapa ( rights ) y hacer lo mismo, por cada elemento en left, se buscaba las coincidencias en el mapa para
    ver cuandos elementos complementaban al elemento en left

    Ambas ideas daban TLE. Por lo tanto, se penso en la idea de trabajar con los dos, ordenarlos y usar tecnica de 2
    punteros.

    En la cual, empezabas del menor de left y del mayor de right. Asi, si sumabas ambos elementos de
    ambos arreglos, veias si daban 0 ambos o si era mayor a 0, se decrementaba del elemento right, ya que empezaba
    del ultimo de ese arreglo, o si la suma era menor a 0, se incrementaba el iterador en el arreglo left, ya que
    de ahi se empezaba desde el elemento 0, es decir el mas menor, y asi hasta encontrar todas las sumas de ambos
    arreglos que den 0. Una vez encontrabas ambas sumas, simplemente se recorren ambos arreglos para encontrar todas
    las coincidencias de mismos elementos y multiplicarlos para añadirlos a la respuesta final.
*/

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
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define pb push_back
const int MOD = 1e9 + 7;
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--){
        int n;
        cin >> n;
        vi A(n), B(n), C(n), D(n);
        for (int i = 0; i < n; i++){
            cin >> A[i];
            cin >> B[i];
            cin >> C[i];
            cin >> D[i];
        }
        vi lefts(n * n);
        vi rights(n * n);
        int k = 0;

        // Llenado de lefts con A+B
        for (auto a : A)
            for (auto b : B)
                lefts[k++] = a + b;

        k = 0;
        // Llenado de Rights con C+D
        for (auto c : C)
            for (auto d : D)
                rights[k++] = c + d;

        // ordenar ambos elementos
        sort(all(lefts));
        sort(all(rights));

        // Tecnica de 2 punteros
        int j = rights.size() - 1, i = 0;
        int ans = 0;

        while (i < lefts.size() && j >= 0){
            int sum = lefts[i] + rights[j];
            if (sum > 0) // Si la suma es positiva, decrementamos en rights
                j--;
            else if (sum < 0) // Si la suma es negativa, incrementamos en lefts
                i++;
            else{ // Si encontramos una suma 0, buscamos todos los elementos que coincidan con ese mismo elemento de cada arreglo
                // Buscamos el total del mismo numero en lefts
                int cntLeft = 1;
                i++;
                while (i < lefts.size() && lefts[i] == lefts[i - 1]){
                    cntLeft++;
                    i++;
                }
                // Buscamos el total del mismo numero en rights
                int cntRight = 1;
                j--;
                while (j >= 0 && rights[j] == rights[j + 1]){
                    cntRight++;
                    j--;
                }
                // Multiplicamos el total de coincidencias de ambos arreglos y lo sumamos a la respuesta final
                ans += (cntLeft * cntRight);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}