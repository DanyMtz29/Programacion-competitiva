#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

const int MOD = 998244353;
const int N = 2 * 1e5;
int fact[N];

int mulWithMOD(int a, int b){
    return (a * b) % MOD;
}

void calculateFactorials(){
    fact[0] = 1;
    for (int i = 1; i < N; i++){
        fact[i] = mulWithMOD(fact[i - 1], i);
    }
}

int32_t main(){
    int n;
    calculateFactorials();
    cout << "Ingresa el numero del factorial de quieres" << endl;
    while (cin >> n){
        cout << "Factorial de " << n << ": " << fact[n] << endl;
    }
    return 0;
}