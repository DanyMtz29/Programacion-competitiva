/*
    Problem: https://codeforces.com/contest/2121/problem/D
    Se resolvio literalmente usando simulacion.
    Se colocaron arriba todos los impares y abajo todos los pares
    Si habia impares abajo se buscaba el par arriba para poder
    cambiarlo. Despues se ordenaban cada uno y ya
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

void sort(vi &a, vector<pi> &ans, int n, int arr)
{
    // Ordenamiento de a
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                ans.pb({arr, j + 1});
                swap(a[j], a[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
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
        int n;
        cin >> n;
        vi a(n), b(n);
        forN(n, a);
        forN(n, b);
        int i = 0, j = 0;
        vector<pi> ans;
        while (i < n && j < n)
        {
            while (a[i] % 2 == 1 && i < n) // Buscando un impar en el arreglo a
                i++;
            while (b[j] % 2 == 0 && j < n) // Buscando un par en el arreglo b
                j++;
            if (i == n || j == n)
                break;
            // Acomodo en las misma posicion y cambio
            int ii = i;
            int jj = j;
            while (i > j)
            {
                ans.pb({2, j + 1});
                swap(b[j], b[j + 1]);
                j++;
            }
            while (j > i)
            {
                ans.pb({1, i + 1});
                swap(a[i], a[i + 1]);
                i++;
            }
            ans.pb({3, i + 1});
            swap(a[i], b[j]);
            i = ii;
            j = jj;
        }
        sort(a, ans, n, 1);
        sort(b, ans, n, 2);
        cout << ans.size() << "\n";
        for (auto const &p : ans)
            cout << p.F << " " << p.S << "\n";
    }
    return 0;
}
