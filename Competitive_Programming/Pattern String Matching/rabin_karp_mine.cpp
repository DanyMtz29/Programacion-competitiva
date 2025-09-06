#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int,int>
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define ppi pair<pair<int,int>,int>
#define pb push_back
#define F first
#define S second

using namespace std;

// --- Configuración de doble hashing ---
const int MOD1 = 1000000007;  // primer módulo (primo grande)
const int P1   = 31;          // primera base
const int MOD2 = 1000000009;  // segundo módulo (primo distinto)
const int P2   = 37;          // segunda base, distinta de P1

// Calcula dos hashes en paralelo y los empaqueta en un único int64:
int poly_hash(const string &s) {
    int h1 = 0, p1 = 1;
    int h2 = 0, p2 = 1;
    for (int i = 0; i < (int)s.size(); i++) {
        int x = s[i] - 'a' + 1;
        // actualización primer hash
        h1 = (h1 + x * p1) % MOD1;
        p1 = (p1 * P1) % MOD1;
        // actualización segundo hash
        h2 = (h2 + x * p2) % MOD2;
        p2 = (p2 * P2) % MOD2;
    }
    // Empaqueta h1 en bits altos y h2 en bits bajos
    return ((int64_t)h1 << 32) | (unsigned int)h2;
}

// Potencia modular (base^exp % mod)
int powr(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Inversa modular de x bajo módulo mod (mod primo)
int inv(int x, int mod) {
    return powr(x, mod - 2, mod);
}

// Rabin–Karp contando ocurrencias de pattern en text (doble hashing)
int rabin_karp(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    if (m > n) return 0;

    // Hash del patrón
    int64_t pat_hash = poly_hash(pattern);
    // Hash inicial del texto (primer ventana)
    int64_t text_hash = poly_hash(text.substr(0, m));

    int ans = 0;
    if (text_hash == pat_hash) ans++;

    // Precalcula inversas y potencias altas para rolling
    int inv_p1 = inv(P1, MOD1);
    int inv_p2 = inv(P2, MOD2);
    int high1  = powr(P1, m - 1, MOD1);
    int high2  = powr(P2, m - 1, MOD2);

    for (int i = 1; i + m <= n; i++) {
        // Desempaqueta los hashes previos
        unsigned int low2 = (unsigned int)(text_hash & 0xFFFFFFFF);
        int h1 = text_hash >> 32;
        int h2 = low2;

        int out = text[i - 1] - 'a' + 1;
        int in  = text[i + m - 1] - 'a' + 1;
        
        // Rolling primer hash
        h1 = (h1 - out + MOD1) % MOD1;
        h1 = (h1 * inv_p1) % MOD1;
        h1 = (h1 + in * 1LL * high1 % MOD1) % MOD1;
        
        // Rolling segundo hash
        h2 = (h2 - out + MOD2) % MOD2;
        h2 = (h2 * inv_p2) % MOD2;
        h2 = (h2 + in * 1LL * high2 % MOD2) % MOD2;

        // Reempaqueta
        text_hash = ((int64_t)h1 << 32) | (unsigned int)h2;

        if (text_hash == pat_hash) ans++;
    }
    return ans;
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
    
    }
    return 0;
}