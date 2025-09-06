#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int solve2(const string &s,vector<vector<vector<int>>> &dp,int i, int j, int k){
    // 1) Si ya queremos subsecuencia de longitud <= 0, costo 0 (no hay que cambiar nada).
    if (k <= 0)
        return 0;

    // 2) Si i > j pero todavía nos piden k>0, imposible formar subsecuencia
    if (i > j)
        return INT_MAX;

    // 3) Si el subrango [i..j] es más pequeño que k, imposible
    if ((j - i + 1) < k)
        return INT_MAX;

    // 4) Memo: si ya está calculado, devuélvelo
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    // 5) Opción A: saltar el carácter s[i]
    int jumpI = solve2(s, dp, i + 1, j, k);

    // 6) Opción B: saltar el carácter s[j]
    int jumpJ = solve2(s, dp, i, j - 1, k);

    // 7) Opción C: usar ambos extremos s[i] y s[j], solo si k >= 2
    int useIJ = INT_MAX;
    if (k >= 2){
        int inside = solve2(s, dp, i + 1, j - 1, k - 2);
        if (inside != INT_MAX){
            // Solo si el interior no es imposible, sumamos el costo de igualar s[i] y s[j].
            int cost = (s[i] != s[j]);
            useIJ = inside + cost;
        }
    }

    // 8) Tomar la mejor de las 3
    int ans = min({jumpI, jumpJ, useIJ});
    dp[i][j][k] = ans;
    return ans;
}

int solve(string &s, vector<vector<vector<int>>> &dp, int i, int j, int k){
    if (k == 0)
        return 0;

    if (k == 1){
        if (i <= j)
            return 0;
        else
            return INT_MAX;
    }

    if (j - i + 1 < k)
        return INT_MAX;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int jumpI = solve(s, dp, i + 1, j, k);
    int jumpJ = solve(s, dp, i, j + 1, k);
    int useIJ = solve(s, dp, i + 1, j - 1, k - 2);
    if (useIJ != INT_MAX)
        useIJ += s[i] != s[j];

    return dp[i][j][k] = min({jumpI, jumpJ, useIJ});
}

int32_t main(){
    string s = "abcdacefgj";
    int n = 10;
    int k = 4;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
    // cout << solve(s, dp, 0, n - 1, k) << endl;
    cout << solve2(s, dp, 0, n - 1, k) << endl;
    return 0;
}