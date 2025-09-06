#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

// Máximo posible (A, B, C <= 1e5) => A+B+C <= 3e5 en el peor caso
// Para tener un margen, definimos:
const int MAXN = 300000;

vector<long long> fact(MAXN + 1), invFact(MAXN + 1);

// Función para exponenciación binaria (cálculo de potencia modular).
long long modExp(long long base, long long exp, long long m)
{
    long long result = 1;
    base = base % m;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return result;
}

// Precomputamos factoriales e inversas de factorial [0..n] con complejidad O(n).
void buildFactorials(int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    // invFact[n] = (fact[n])^-1 mod M, usando Fermat (M es primo)
    invFact[n] = modExp(fact[n], MOD - 2, MOD);
    // inversas de factorial en "orden inverso"
    for (int i = n - 1; i >= 0; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Función para calcular combinaciones nCr en O(1) usando factoriales precalculados.
long long nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0; // Fuera de rango => 0
    return fact[n] * ((invFact[r] * invFact[n - r]) % MOD) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precalcular factoriales hasta el máximo necesario
    // En el peor caso (A, B, C = 1e5), A+B+C <= 3e5
    buildFactorials(MAXN);

    int T;
    cin >> T;
    while (T--)
    {
        long long A, B, C, K, c;
        cin >> A >> B >> C >> K >> c;

        // Chequeos de imposibilidad:
        // 1) c no puede exceder C
        // 2) (K-c) >= 2 para que haya al menos 1 en A y 1 en B
        // 3) (K-c) <= A + B (hay que tener suficientes en A y B)
        if (c > C || (K - c) < 2 || (K - c) > (A + B))
        {
            cout << 0 << "\n";
            continue;
        }

        // Calculamos las combinaciones involucradas
        // binom(C, c)
        long long chooseC = nCr(C, c);
        cout << "ChooseC: " << chooseC << endl;
        // binom(A+B, K-c)
        long long chooseAB = nCr(A + B, K - c);
        cout << "ChooseAB: " << chooseAB << endl;
        // binom(A, K-c)
        long long chooseA = nCr(A, K - c);
        cout << "ChooseA: " << chooseA << endl;
        // binom(B, K-c)
        long long chooseB = nCr(B, K - c);
        cout << "ChooseB: " << chooseB << endl;

        // Formula:
        //  = binom(C, c) * [ binom(A+B, K-c) - binom(A, K-c) - binom(B, K-c) ]
        long long ways = chooseAB;
        cout << "Ways = chooseAB: " << ways << endl;
        ways = (ways - chooseA + MOD) % MOD; // Ajustamos con +MOD para evitar negativo
        cout << "Ways - chooseA: " << ways << endl;
        ways = (ways - chooseB + MOD) % MOD; // idem
        cout << "Ways - chooseB: " << ways << endl;
        ways = (ways * chooseC) % MOD;
        cout << "Ways * chooseC: " << ways << endl;

        cout << ways << "\n";
    }

    return 0;
}
