#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    cin >> N;
    int pares = 0;
    int impares = 0;
    int unos = 0;
    int ceros = 0;
    int contador = 0;
    for (int i = 0; i < N; i++)
    {
        int element;
        cin >> element;
        if (element == 1)
        {
            contador++;
            contador += ceros;
            contador += unos / 2;
            unos++;
            if (unos % 2 == 0)
            {
                contador += pares;
                pares += ceros;
            }
            else
            {
                contador += impares;
                impares += ceros;
            }

            ceros = 0;
        }
        else
        {
            contador += (unos + 1) / 2;
            ceros++;
            if (unos % 2 == 0)
                contador += pares;
            else
                contador += impares;
        }
    }
    cout << contador << endl;

    return 0;
}