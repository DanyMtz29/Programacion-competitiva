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
const int MOD = 998244353;
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n;
        cin >> n;

        vi appears(1e5 + 1, 0);
        vi pos(1e5 + 1);
        vi way(n);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int e;
            cin >> e;
            if (appears[e] > 0)
            {
                ans = ((ans + way[pos[e]]) % MOD);
                way[i] = ans;
                ans = (ans + appears[e]) % MOD;
            }
            else
                way[i] = ans;

            pos[e] = i;
            appears[e]++;
        }

        // cout << "Formas" << "\n";
        // copy(way.begin(), way.end(), ostream_iterator<int>(cout, "|"));
        // cout << "" << "\n";
        cout << ((ans + 1) % MOD) << endl;
    }
    return 0;
}

/*
    La idea de resolverlo es calcular el total de subsets de una manera lineal conforme nos vamos topando con numeros repetidos, ya que la
    condicion dice que un subset valido debe de tener la misma elevacion tanto al inicio como al final, es decir "x----x", donde los guiones
    representan cualquier numero, sin embargo, hay que considerar casos con subsets anteriores.

    El anterior codigo se basa en la siguiente idea.
    Siempre se van a considerar subsets con numeros repetidos. Por ejemplo, si aparece 2 veces el 1, hay en total 1 subset apartir del
    segundo 1:
        1 1
    Si aparece 3 veces el 1, hay en total dos subsets apartir del tercer 1:
        1 - 1
        - 1 1
    si aparece 4 veces el 1, hay en total 3 subsets apartir del cuarto 1:
        1 - - 1
        - 1 - 1
        - - 1 1
    Sin embargo, como se va viendo, se tienen que considerar los subsets anteriores calculados dependiendo de las apariciones de los
    numeros anteriores, por ejemplo, con cuatro 1's, sabes que es valido este subset: "[1 1] [1 1]" pero no se considera en la logica
    anterior, para ello, se agrega un arreglo donde se guardara el total de subsets calculados hasta ese momento para sumarlos al
    total de subsets de numeros repetidos. Por ejemplo, comenzando de nuevo en el caso de los 1's
    cuando hay un 1:
        total Subsets: 0
        arreglo      [ 0 - - - ]
        posiciones   [ 0 1 2 3 ]

    cuando hay dos 1's:
        total Subsets: 1
        arreglo      [ 0 0 - - ] <-antes de la posicion 1, no hay un subset, ya que solo teniamos un 1. Por eso se pone 0
        posiciones   [ 0 1 2 3 ]

    cuando hay tres 1's:
        total Subsets: 3
        arreglo      [ 0 0 1 - ] <-antes de la posicion 2, hay un subset, el subset de las posiciones [0,1] que es "1 1"
        posiciones   [ 0 1 2 3 ]

    cuando hay cuatro 1's:
        total Subsets: 7
        arreglo      [ 0 0 1 4 ] <- Hay 4 subsets antes de la posicion 3
        posiciones   [ 0 1 2 3 ]

        antes de la posicion 4, hay 4 subsets:
                                1 1 - -
                                - 1 1 -
                                1 - 1 -
                                1 1 - -
        En total de subsets hay 7, 3 anteriores + el total de substets antes del ultimo 1, es decir, antes de la posicion 2, hay que ver
        cuantos subsets habia antes, para considerar todas las combinaciones de todos los numeros anteriores con la ultima posiciones
        de mi 1 anterior con el actual. En este caso es 1, ya que los subsets antes de la posicion de mi ultimo 1 es 2, y en mi arreglo
        en esa posicion indica que hay un subset solamente, cual?, el de la posicion [0,1], que me sirve para hacer "[1 1] [1 1] "".

        Entonces, entendiendo eso, en el arreglo se guardan los subsets anteriores que traemos + los subsets de la ultima aparicion de mi
        numero con el que haré par (misma elevacion) para ver cuantos subsets antes de esa ultima aparicion hay y considerarlos tambien.
        En este caso se tiene:
                        Subsets antes de la posicion 3
                                1 1 - -
                                - 1 1 -
                                1 - 1 -
                        subsets antes de mi ultimo 1, posicion 2
                                1 1 [1 1]
                        subsets que hare con el total de numeros 1's que han aparecido (3 excluyendo el actual)
                                1 - - 1
                                - 1 - 1
                                - - 1 1
                        Que da un total de 7
        Al finalizar se debe de sumar 1, ya que siempre es valido el de todos solos:
                                [1][1][1][1]



EJEMPLO
         |---------------------- |
         |1 1 1 2 2 1  2   1  2  |
         |---------------------- |
arreglo: |0 0 1 3 6 8  17 27  48 |
subsets: |0 1 3 3 7 11 19 31 51 |
         |--------------------- |

RECORRIDO EN CICLO DESDE i = 0 HASTA i < n
    i = 0;
    1

    i = 1;
    1 1

    i = 2;
    1 1 -
    - 1 1
    1 - 1

    i = 3;
    1 1 - -
    - 1 1 -
    1 - 1 -

    i=4
    1 1 - - -
    - 1 1 - -
    1 - 1 - -
    1 1 - 2 2
    - 1 1 2 2
    1 - 1 2 2
    - - - 2 2

    i=5;
    1 1 - - - -
    - 1 1 - - -
    1 - 1 - - -
    1 1 - 2 2 -
    - 1 1 2 2 -
    1 - 1 2 2 -
    - - - 2 2 -
    1 1 1 - - 1
    1 - - - - 1
    - 1 - - - 1
    - - 1 - - 1

    i=6;
    1 1 - - - - -
    - 1 1 - - - -
    1 - 1 - - - -
    1 1 - 2 2 - -
    - 1 1 2 2 - -
    1 - 1 2 2 - -
    - - - 2 2 - -
    1 1 1 - - 1 -
    1 - - - - 1 -
    - 1 - - - 1 -
    - - 1 - - 1 -
    1 1 - - 2 - 2
    - 1 1 - 2 - 2
    1 - 1 - 2 - 2
    1 1 - 2 - - 2
    - 1 1 2 - - 2
    1 - 1 2 - - 2
    - - - 2 - - 2
    - - - - 2 - 2

    i=7;
    1 1 - - - - - -
    - 1 1 - - - - -
    1 - 1 - - - - -
    1 1 - 2 2 - - -
    - 1 1 2 2 - - -
    1 - 1 2 2 - - -
    - - - 2 2 - - -
    1 1 1 - - 1 - -
    1 - - - - 1 - -
    - 1 - - - 1 - -
    - - 1 - - 1 - -
    1 1 - - 2 - 2 -
    - 1 1 - 2 - 2 -
    1 - 1 - 2 - 2 -
    1 1 - 2 - - 2 -
    - 1 1 2 - - 2 -
    1 - 1 2 - - 2 -
    - - - 2 - - 2 -
    - - - - 2 - 2 -
    1 1 - - - 1 - 1
    - 1 1 - - 1 - 1
    1 - 1 - - 1 - 1
    1 1 - 2 2 1 - 1
    - 1 1 2 2 1 - 1
    1 - 1 2 2 1 - 1
    - - - 2 2 1 - 1
    1 1 1 - - 1 - 1
    1 - - - - - - 1
    - 1 - - - - - 1
    - - 1 - - - - 1
    - - - - - 1 - 1

*/