#include <bits/stdc++.h>
using namespace std;

// Función Z-Algorithm que calcula, para cada posición i de arr,
// la longitud máxima de coincidencia (prefijo) comenzando en i.
vector<int> zAlgorithm(const vector<long long> &arr)
{
    int n = (int)arr.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && arr[z[i]] == arr[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<long long> A(M), B(N);
    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    // Caso especial: si M == 1, todos los subarreglos de longitud 1
    // se pueden "ajustar" sumando o restando el valor necesario.
    if (M == 1)
    {
        cout << N << "\n";
        return 0;
    }

    // Construimos los diffs de A y B.
    vector<long long> diffA(M - 1), diffB(N - 1);
    for (int i = 0; i + 1 < M; i++)
    {
        diffA[i] = A[i + 1] - A[i];
    }
    for (int i = 0; i + 1 < N; i++)
    {
        diffB[i] = B[i + 1] - B[i];
    }

    // Construimos el array para Z-algo: diffA + (-inf) + diffB
    // Usamos un valor separador único que no aparezca en diffA ni diffB.
    // Para seguridad, usamos algo como LLONG_MIN (o un valor que no colisione).
    vector<long long> concat;
    concat.reserve(diffA.size() + 1 + diffB.size());

    for (auto &x : diffA)
        concat.push_back(x);
    concat.push_back(LLONG_MIN);
    for (auto &x : diffB)
        concat.push_back(x);

    // Corremos Z-Algorithm en 'concat'.
    vector<int> z = zAlgorithm(concat);

    // Contamos cuántas veces aparece diffA en diffB
    // => buscamos z[i] == diffA.size().
    int matches = 0;
    int lenA = (int)diffA.size();
    for (int i = 0; i < (int)z.size(); i++)
    {
        if (z[i] == lenA)
            matches++;
    }

    cout << matches << "\n";
    return 0;
}
