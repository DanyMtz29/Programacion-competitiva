#include <bits/stdc++.h>
using namespace std;

// M debe ser potencia de 2 y >> n (aquí 4 194 304 > 4·10^6)
static const int M = 1 << 22;
static const int MASK = M - 1;

// Tabla abierta con clave=int (mask), valor=int (primera posición)
int ht_key[M];
int ht_val[M];

// Inicializa la tabla (clave=-1 indica celda libre)
void init_table()
{
    memset(ht_key, -1, sizeof ht_key);
}

// Inserta (k,v) sólo si k no estaba; guarda la primera ocurrencia
inline void ht_put_if_absent(int k, int v)
{
    // hash: Knuth multiplicative + máscara
    unsigned h = (unsigned)k * 2654435761u & MASK;
    while (true)
    {
        if (ht_key[h] == -1)
        {
            ht_key[h] = k;
            ht_val[h] = v;
            return;
        }
        if (ht_key[h] == k)
            return; // ya estaba
        h = (h + 1) & MASK;
    }
}

// Busca k; retorna true + salida en out si lo encuentra
inline bool ht_get(int k, int &out)
{
    unsigned h = (unsigned)k * 2654435761u & MASK;
    while (true)
    {
        int key = ht_key[h];
        if (key == -1)
            return false;
        if (key == k)
        {
            out = ht_val[h];
            return true;
        }
        h = (h + 1) & MASK;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    init_table();

    // marcamos máscara 0 vista en pos = -1
    ht_put_if_absent(0, -1);

    int mask = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        mask ^= 1 << (c - 'a');

        // Caso 1: misma máscara
        int pos;
        if (ht_get(mask, pos))
            maxLen = max(maxLen, i - pos);

        // Caso 2: una sola bit de diferencia
        for (int b = 0; b < 26; b++)
        {
            int m2 = mask ^ (1 << b);
            if (ht_get(m2, pos))
                maxLen = max(maxLen, i - pos);
        }

        // Guardamos primer índice de esta máscara
        ht_put_if_absent(mask, i);
    }

    cout << maxLen << "\n";
    return 0;
}
