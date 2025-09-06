/*
    La idea de resolver este problema fue la siguiente:
    Hacer un dp de 2 valores, es decir, cuadratico de primero, ya que llega n hasta 1000.
    Se obtienen todos los valores de 2 sumas, de dos indices. Ejemplo:
        primero + segundo, primero + tercero, primero + cuarto, primero + n-1
        segundo + tercero, segundo + cuarto, segundo + n-1
        tercero + cuarto, tercero + n-1
        n-2 + n-1
    Una vez obtenidas todas las sumas, se hace una busqueda binaria por rangos, para comprobar todas
    las sumas que den un numero y si esos indices son validos, al mismo tiempo, haciendo cuadratico todo
    nuevamente ya que se tiene que buscar por otros dos numeros. Por ejemplo:
        primero + segundo y buscar en el dp el target - ( primero + segundo ).
    Si hay varias coincidencias de esa busqueda, tenemos que comprobar todas para ver cuales indices son validos.
    Si hay indices que se repiten, no se considera como respuesta y se busca otra. Al mismo tiempo se usa un set
    para mantener un mapa de valores que ya se buscaron con anterioridad y no volverlos a buscar.
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

bool cmp(const pair<int, pi> &p1, const pair<int, pi> &p2)
{
    return p1.first < p2.first;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, target;
        cin >> n >> target;
        vi nums(n);
        forN(n, nums);
        int nn = n * (n - 1) / 2;
        vector<pair<int, pi>> prevs(nn);
        int k = 0;
        // Llenando las posibles combinaciones de 2 numeros
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                prevs[k++] = {nums[i] + nums[j], {i, j}}; // {sum, {indexes}}

        // Ordenar las combinaciones para hacer busqueda binaria
        sort(all(prevs), cmp);

        // Guardar en un mapa para evitar recorridos innecesarios
        unordered_set<int> st;

        // Recorrer cuadratico nuevamente para ver si se encuentra una combinacion.
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Buscar target - ( suma de dos indices )
                pair<int, pi> curSum = {target - (nums[i] + nums[j]), {0, 0}}; // Ignorar el curSum.second, ya que en el cmp no lo utilizo

                // Si ya esta en el mapa, nos la saltamos
                if (st.find(curSum.first) != st.end())
                    continue;

                // Hacer busqueda binaria para obtener rango de busqueda
                auto check = lower_bound(all(prevs), curSum, cmp) - prevs.begin();
                auto checkS = upper_bound(all(prevs), curSum, cmp) - prevs.begin();

                // Checamos todos el rango de coincidencias para probar que indices son validos
                while (check >= 0 && check < nn && check < checkS)
                {
                    if (prevs[check].first == curSum.first) // Si la suma no es la que buscamos, no hacemos nadas
                    {
                        // Recordando que en prevs tengo esto { suma, {indices de esa suma} }
                        int ii = prevs[check].second.first;
                        int jj = prevs[check].second.second;
                        // Comparo que sean diferentes indices
                        if (i != ii && i != jj && j != ii && j != jj)
                        {
                            // Simplemente ordeno como se muestran los indices, para mas comodidad
                            vi res = {i, j, ii, jj};
                            sort(all(res));
                            for (auto r : res)
                                cout << r + 1 << " ";
                            cout << "\n";
                            return 0;
                        }
                    }
                    // Avanzamos a la siguiente coincidencia para comparar que los otros indices sean validos
                    check++;
                }
                // No se encontraron indices validos o no era la suma que buscaba, lo guardo en el mapa para evitar procesarlo otra vez
                st.insert(curSum.first);
            }
        }
        cout << "-1" << "\n";
    }
    return 0;
}