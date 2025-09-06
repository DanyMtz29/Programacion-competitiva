/*
    Problem: https://codeforces.com/problemset/problem/1006/F
    La idea de resolver este problema fue la siguiente:
    Se uso el tema meet-in-the-middle lo que significa dividir en dos mitades las posibles combinaciones de un arreglo y luego
    unirlas. La estrategia fue ir desde el punto de encuentro de la diagonal a los puntos de arriba y abajo, de manera que se
    calculaban primero los caminos de arriba, es decir desde 0,0 hasta el punto de encuentro (incluyendolo) y luego desde el
    punto de encuentro hasta el final (n-1,m-1).
    Una vez calculados los dos caminos, se buscaba por medio de busqueda binaria los posibles caminos que tuviera las rutas
    de abajo aplicandole el xor a las rutas de arriba, es decir, a todas las rutas de arriba se le aplicaba xor con k, luego
    el resultado se buscada en las rutas de abajo, se buscaba entre rangos para si existen muchas coincidencias, tomarlas en
    cuenta.

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

vi fillTop(int i, int j, int n, int m, vvi &mat)
{
    queue<pair<int, pi>> q;
    q.push({mat[i][j], {i, j}});

    vi res;
    while (!q.empty())
    {
        queue<pair<int, pi>> q2;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int sum = p.first;
            int ii = p.second.first;
            int jj = p.second.second;
            if (ii - 1 >= 0)
                q2.push({sum ^ mat[ii - 1][jj], {ii - 1, jj}});
            if (jj - 1 >= 0)
            {
                q2.push({sum ^ mat[ii][jj - 1], {ii, jj - 1}});
            }
            if (ii - 1 < 0 && jj - 1 < 0)
                res.pb(sum);
        }
        q2.swap(q);
    }
    return res;
}

vi fillDown(int i, int j, int n, int m, vvi &mat)
{
    queue<pair<int, pi>> q;
    q.push({0, {i, j}});

    vi res;
    while (!q.empty())
    {
        queue<pair<int, pi>> q2;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int sum = p.first;
            int ii = p.second.first;
            int jj = p.second.second;
            if (ii + 1 < n)
                q2.push({sum ^ mat[ii + 1][jj], {ii + 1, jj}});
            if (jj + 1 < m)
            {
                q2.push({sum ^ mat[ii][jj + 1], {ii, jj + 1}});
            }
            if (ii + 1 >= n && jj + 1 >= m)
                res.pb(sum);
        }
        q2.swap(q);
    }
    sort(all(res));
    return res;
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
        int n, m, k;
        cin >> n >> m >> k;

        vvi mat(n, vi(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        int row = 0, col = min((n + m) / 2, m - 1);
        int ans = 0;
        while (row < n && col >= 0)
        {
            vi topSums = fillTop(row, col, n, m, mat);
            vi downSums = fillDown(row, col, n, m, mat);
            for (auto x : topSums)
                ans += (upper_bound(all(downSums), k ^ x) - lower_bound(all(downSums), k ^ x));

            row++;
            col--;
        }
        cout << ans << "\n";
    }
    return 0;
}
