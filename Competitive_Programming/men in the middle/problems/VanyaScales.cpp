/*
    Problem: https://codeforces.com/problemset/problem/552/C
    La idea de resolverlo fue usar teoria de numeros
    Se sabe si se puede alcanzar ese numero por sus potencias en base al resto.
    Por ejemplo, si tenemos el 3, se puede llegar al 51 haciendo modulos.
    51%3 = 0 (es igual a 0, por lo tanto hacemos m/=w)
    17%3 = 2, (es igual a 3-1, por lo tanto hacemos m=(m+1)/w)
    6%3 = 0, ( es igual a 0, por lo tanto hacemos m/=w )
    2%3 = 2, (es igual a 3-1, por lo tanto hacemos m = (m+1)/w)
    1%3 = 1, (es igual a 1, por lo tanto hacemos m = (m-1)/w)
    m = 0, hay acaba el algoritmo, significa que si se puede llegar por medio de potencias.

    Si m fuera diferente de m-1, 1 o 0, significa que no se puede, seria imposible.

    Solo hay un caso especial, el del 2, ese puede llegar a cualquier numero.
    Ya que todo numero natural, tiene su representacion en potencias de 2
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
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int m, w;
        cin >> w >> m;
        if (w == 2)
        {
            cout << "YES" << "\n";
            return 0;
        }
        int r;
        while (m)
        {
            r = m % w;
            if (r == w - 1)
                m = (m + 1) / w;
            else if (r == 1)
                m = (m - 1) / w;
            else if (r == 0)
                m /= w;
            else
                break;
        }
        cout << (m == 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}