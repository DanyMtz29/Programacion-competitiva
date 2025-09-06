/*
    La idea de resolverlo fue la siguiente:
    Como el arreglo podia llegar hasta la 10^5, era imposible hacer 2^n subsets, por lo tanto, se
    busco una estrategia de obtener toda la suma negativa primero, de todos los negativos, ya que el
    subarreglo de todos los negativos es el mas pequeño, en base de ese sub arreglo, se sacan los demas.

    Se empieza obteniendo la suma de todos los negativos, una vez obtenida, se cambian todos los valores
    negativos a positivos. Una vez hecho eso, se empieza una busqueda como tipo dijsktra para encontrar
    todos los mas pequeños primero, se recorre hata n veces o hasta que la cola esta vacia.
    Empezando desde la posicion 0, luego avanzando con una priority_queue insertando dos opciones:
    manteniendo el numero actual ( sum + arr[index+1] ) o quitar el numero actual ( sum - arr[index] + arr[index+1] )

    AL ultimo, ya que finalizo el recorrido de todos los menores, se le suma la suma maxima negativa,
    ya que con todos los negativos, se obtiene el subarray mas pequeño, que es lo que se busca.
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
#define F first
#define S second
const int MOD = 1e9 + 7;
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--){
        int n, k;
        cin >> n >> k;

        vi arr(n);
        forN(n, arr);
        sort(all(arr));

        int negSum = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] >= 0)
                break;
            negSum += arr[i];
            arr[i] = abs(arr[i]);
        }

        sort(all(arr));

        //{sum,index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<int, vector<int>, greater<int>> res;

        res.push(0);
        pq.push({arr[0], 0});

        while (!pq.empty() && k > 1){
            int curSum = pq.top().F;
            int curIndex = pq.top().S;
            res.push(curSum);
            if (curIndex + 1 < n){
                pq.push({curSum + arr[curIndex + 1], curIndex + 1});                 // Insertar seleccionando ambos
                pq.push({curSum - arr[curIndex] + arr[curIndex + 1], curIndex + 1}); // Insertar seleccionando solo el de la derecha
            }
            pq.pop();
            k--;
        }
        while (!res.empty()){
            cout << res.top() + negSum;
            res.pop();
            if (!res.empty())
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}