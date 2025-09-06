//https://codeforces.com/problemset/problem/225/C
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int solve(vector<vector<vector<int>>> &dp, vector<int> &gatos, vector<int> &puntos, int m, int n, int x, int y)
{
    // Base case: primera columna
    // dp[i][len][color] -> coste mínimo pintando columnas [1..i],
    //                     con un bloque actual de longitud "len" y color "color"
    // color: 0 = blanco, 1 = negro
    dp[1][1][0] = puntos[0]; // Pintar la 1ra columna (índice 0) de blanco
    dp[1][1][1] = gatos[0];  // Pintar la 1ra columna de negro

    // Rellenamos el DP para columnas 2..m
    for (int i = 2; i <= m; i++)
    {
        // El costo para la columna "i-1" en cada color
        int costW = puntos[i - 1]; // costo de pintarla de blanco
        int costB = gatos[i - 1];  // costo de pintarla de negro

        for (int len = 1; len <= y; len++)
        {
            for (int color = 0; color < 2; color++)
            {
                int currentDP = dp[i - 1][len][color];
                if (currentDP == INT_MAX)
                    continue; // estado imposible

                // 1) Extender el bloque de color actual, si aún no pasamos y
                if (len < y)
                {
                    dp[i][len + 1][color] = min(
                        dp[i][len + 1][color],
                        currentDP + (color == 0 ? costW : costB));
                }

                // 2) Cambiar de color (iniciar un bloque nuevo) si len >= x
                //    Se permite cerrar el bloque sólo si cumple la longitud mínima x
                if (len >= x)
                {
                    int nuevoColor = 1 - color; // cambiar 0 -> 1 ó 1 -> 0
                    dp[i][1][nuevoColor] = min(
                        dp[i][1][nuevoColor],
                        currentDP + (nuevoColor == 0 ? costW : costB));
                }
            }
        }
    }

    // Tomamos el mínimo costo de dp[m][len][color]
    // con x <= len <= y y color en {0,1}
    int ans = INT_MAX;
    for (int len = x; len <= y; len++)
    {
        for (int color = 0; color < 2; color++)
        {
            ans = min(ans, dp[m][len][color]);
        }
    }

    return ans;
}

int32_t main()
{

    int m, n, x, y;
    cin >> n >> m >> x >> y;
    vector<int> gatos(m, 0);
    vector<int> puntos(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char element;
            cin >> element;
            if (element == '#')
            {
                gatos[j]++;
            }
            else
            {
                puntos[j]++;
            }
        }
    }

    cout << "Puntos" << endl;
    copy(puntos.begin(), puntos.end(), ostream_iterator<int>(cout, "|"));
    cout << "" << endl;
    cout << "gatos" << endl;
    copy(gatos.begin(), gatos.end(), ostream_iterator<int>(cout, "|"));
    cout << "" << endl;

    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(y + 1, vector<int>(2, INT_MAX)));

    cout << solve(dp, gatos, puntos, m, n, x, y) << endl;

    for (int k = 1; k <= m; k++)
    {
        cout << "DP Columna " << k << "." << endl;
        for (int i = 1; i <= y; i++)
        {
            cout << "Columna " << i << " con: ";
            cout << "puntos: " << dp[k][i][0] << " y gatos: " << dp[k][i][1] << endl;
        }
    }

    return 0;
}