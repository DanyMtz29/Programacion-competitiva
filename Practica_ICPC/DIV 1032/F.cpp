/*
    problem: https://codeforces.com/contest/2121/problem/F

    La idea de resolverlo fue mantener una tecnica de dos punteros con mapa.

    Lo primero fue hacer un prefixSum, de todo el arreglo, para que en el recorrido
    de punteros solo busquemos y no mantengamos suma.

    Una vez hecho el prefixSum, recorremos el arreglo de 1 hasta n. Mantenemos dos punteros,
    left y right, en el cual, siempre agregaremos las sumas de prfixSum al mapa siempre y cuando
    nos hayamos topado con un maximo, si no nos hemos topado con un maximo, no se puede
    agregar, ya que lo requerimos para que el subset sea valido.
    Si nos topamos con un elemento mayor que el maximo, se reinicia el mapa, ya que los subsets
    anteriores a ese elemento no son validos, y movemos el puntero left hacia uno adelante del
    elemento que es mayor al maximo, ya que no son validos los anteriores.

    Cuando nos topemos con un max, hacemos un recorrido de left hasta el max, donde se agregaran
    todas las sumas anteriores a ese max. Asi lo hacemos cada vez que nos topemos con un max.
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

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n, s, x;
        cin >> n >> s >> x;

        vi arr(n + 1), prefixSum(n + 1);

        // Se rellena el prefixSum
        for (int i = 1; i <= n; i++)
        {
            int e;
            cin >> e;
            arr[i] = e;
            prefixSum[i] = prefixSum[i - 1] + e;
        }

        // Tecnica de 2 punteros con hashing
        int ans = 0;
        map<int, int> mp;
        int left = 0;
        for (int right = 1; right <= n; right++)
        {
            if (arr[right] > x) // Si hay un elemento mayor, empezamos de nuevo a buscar subsets con un mapa nuevo
            {
                mp.clear();
                left = right + 1;
            }
            else if (arr[right] == x) // Metemos las sumas de los subsets anteriores, ya que hay un max entre ellos
            {
                while (left <= right)
                {
                    mp[prefixSum[left - 1]]++;
                    left++;
                }
            }
            // Mi suma actual - target, si encuentra subsets con el resultado se cuentan
            ans += mp[prefixSum[right] - s];
        }
        cout << ans << "\n";
    }
    return 0;
}