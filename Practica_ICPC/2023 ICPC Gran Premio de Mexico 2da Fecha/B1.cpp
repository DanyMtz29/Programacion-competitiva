#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
static const int MAXN = 1000000; // Límite según enunciado

// Arrays globales para factoriales e inversos factoriales
vector<long long> fact(MAXN+1), invFact(MAXN+1);

// Exponenciación rápida para inversos modulares
long long modExp(long long base, long long exp, long long m) {
    long long result = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return result;
}

// Precalcula factoriales e inversos factoriales hasta n = MAXN
void precomputeFactorials(int n) {
    fact[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = (fact[i-1]*i) % MOD;
    }
    // inverso del factorial de n
    invFact[n] = modExp(fact[n], MOD-2, MOD);  
    // invFact[i] = invFact[i+1] * (i+1) mod ...
    for(int i=n-1; i>=0; i--){
        invFact[i] = (invFact[i+1]*(i+1)) % MOD;
    }
}

// Multiplica en “prodFreqFacts” por factorial(f), asumiendo 0 <= f <= N
void addFreqFactor(long long &prodFreqFacts, int f) {
    if(f >= 0 && f <= MAXN) {
        prodFreqFacts = (prodFreqFacts * fact[f]) % MOD;
    }
}

// “Quita” de prodFreqFacts el factor factorial(f), multiplicando por
// el inverso de factorial(f)
void removeFreqFactor(long long &prodFreqFacts, int f) {
    if(f >= 0 && f <= MAXN) {
        prodFreqFacts = (prodFreqFacts * invFact[f]) % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Leer N, K
    int N, K;
    cin >> N >> K;

    // 2) Precomputar factoriales hasta N
    precomputeFactorials(N);

    // 3) Leer arreglo inicial y construir mapa de frecuencias
    vector<int> arr(N);
    unordered_map<int,int> freq;
    freq.reserve(N); // optimiza el rehash
    freq.max_load_factor(0.7f);

    for(int i=0; i<N; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    // 4) Calcular prodFreqFacts = producto de factorial(freq[v]) para cada valor v
    long long prodFreqFacts = 1;
    for(auto &kv : freq){
        addFreqFactor(prodFreqFacts, kv.second);
    }

    // 5) Calcular e imprimir probabilidad inicial = (prodFreqFacts * invFact(N)) % MOD
    long long invFactN = invFact[N];  // (N!)^{-1}
    auto printProb = [&](long long pf){
        long long prob = (pf * invFactN) % MOD;
        cout << prob << "\n";
    };
    printProb(prodFreqFacts);

    // 6) Atender cada consulta
    for(int i=0; i<K; i++){
        int A, B;
        cin >> A >> B;
        A--;   // para usar índice 0-based

        int oldVal = arr[A];
        int newVal = B;

        if(oldVal == newVal){
            // No cambia nada en frecuencias => la probabilidad sigue igual
            cout << ( (prodFreqFacts * invFactN) % MOD ) << "\n";
            continue;
        }

        // a) Quitar el factor factorial de la freq actual de oldVal
        int oldFreq = freq[oldVal];
        removeFreqFactor(prodFreqFacts, oldFreq);

        // Disminuir frecuencia de oldVal
        freq[oldVal] = oldFreq - 1;
        if(freq[oldVal] == 0) {
            freq.erase(oldVal);
        } else {
            // volver a multiplicar por factorial(freq[oldVal]) tras decremento
            addFreqFactor(prodFreqFacts, freq[oldVal]);
        }

        // b) Quitar el factor factorial de la freq actual de newVal (si existe)
        int newFreq = 0;
        if(freq.find(newVal) != freq.end()){
            newFreq = freq[newVal];
            removeFreqFactor(prodFreqFacts, newFreq);
        }
        // Incrementar la frecuencia
        freq[newVal] = newFreq + 1;
        // volver a multiplicar por factorial(freq[newVal]) tras incremento
        addFreqFactor(prodFreqFacts, newFreq + 1);

        // Actualizar arr[A]
        arr[A] = newVal;

        // c) Imprimir la nueva probabilidad
        printProb(prodFreqFacts);
    }

    return 0;
}
