/*
    Problem: https://codeforces.com/contest/2123/problem/G
    La idea de resolverlo fue hacer uso de modulos y el gcd.
    Primero se obtuvo el total de divisores de m, porque con cada k
    obtenias un divisor de m, aplicando gcd(k,m), luego con ese verificabas si era posible
    reordenarlo dependiendo los elementos del arreglo que tenias.
    Entonces, una vez obtenidos los divisores, por cada divisor, recorrias todas las diferencias
    del arreglo ( a[i]-a[i-1] ) y obtenias el modulo k y lo sumabas a un mapa que contenia el contador
    de k. PAra verificaer en las queries si en el mapa, el contador del divisor gcd(k,m) era < m, ya
    que si era menor era posible reordenarlo, caso contrario no.

    En los updates solo era necesario actualicar las diferencias. Del contador del divisor se
    quitaban el modulo total de las diferencias ya calculadas y se añade el modulo total
    de las diferencias con el nuevo elemento que se va a colocar. APlica tanto para el indice-1
    y el indice+1 siempre y cuando sea menor que n, si es 1 no importa, ya que el arreglo
    se inicializa desde la pos 1, y la pos 0 contiene un 0, no causaria error.
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

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int getM(int a, int b)
{
    return (a % b + b) % b;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vi arr(n + 1);
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        umii mp;

        // Obtener los divisores de m
        for (int i = 1; i * i <= m; i++)
            if (m % i == 0)
            {
                mp[i] = 0;
                mp[m / i] = 0;
            }

        // Por cada divisor, obtener el modulo total de todas las diferencias del arreglo
        for (auto &p : mp)
        {
            int div = p.F;
            for (int i = 1; i <= n; i++)
            {
                int diff = arr[i] - arr[i - 1];
                int modDiff = getM(diff, div);
                // Sumamos el modulo de la diferencia a la posicion de ese divisor
                mp[div] += modDiff;
            }
        }

        // Queries
        while (q--)
        {
            int a, b, c;
            cin >> a >> b;
            if (a == 1)
            { // Actualizar
                cin >> c;
                // Actualizamos todos los modulos totales, ya que se afectan todos los divisores
                for (auto &p : mp)
                {
                    // Calculando nuevas diferencias y quitando las anteriores
                    int div = p.F;
                    mp[div] += getM(c - arr[b - 1], div) - getM(arr[b] - arr[b - 1], div);
                    if (b != n)
                        mp[div] += getM(arr[b + 1] - c, div) - getM(arr[b + 1] - arr[b], div);
                }
                // Actualizamos el nuevo elemento en el arreglo
                arr[b] = c;
            }
            else // Si el modulo total es menor que m, significa que si es posible reordenarlo
                cout << (mp[GCD(b, m)] < m ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}