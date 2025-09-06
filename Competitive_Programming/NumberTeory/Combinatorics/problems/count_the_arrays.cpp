// Problem: https://codeforces.com/problemset/problem/1312/D
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int const MOD = 1000000007;
int const N = 300000;
int fact[N];
int factInv[N];

int subWithMOD(int a, int b){
    return ((a - b) % MOD + MOD) % MOD;
}

int mulm(int a, int b){
    return (a * b) % MOD;
}

int pwrm(int a, int b){
    int res = 1;
    while (b){
        if (b & 1)
            res = mulm(res, a);
        a = mulm(a, a);
        b /= 2;
    }
    return res;
}

int inv(int x){
    return pwrm(x, MOD - 2);
}

void factorials(){
    fact[0] = 1;
    for (int i = 1; i <= N; i++){
        fact[i] = mulm(fact[i - 1], i);
    }
}

void factorialsInverse(){
    factInv[N] = pwrm(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--){
        factInv[i] = mulm(factInv[i + 1], (i + 1));
    }
}

int nCr(int n, int r){
    if (r > n || r < 0)
        return 0;

    return mulm(mulm(fact[n], factInv[r]), factInv[n - r]);
}

int32_t main(){
    factorials();
    factorialsInverse();

    int T;
    cin >> T;
    while (T--){
        int A, B, C, k, c;
        cin >> A >> B >> C >> k >> c;
        if ((k - c > A + B) || k - c < 2){
            cout << "0" << endl;
        }else{
            int escogerC = nCr(C, c);
            int escogerAB = nCr(A + B, k - c);
            int escogerA = nCr(A, k - c);
            int escogerB = nCr(B, k - c);

            int ans = escogerAB;
            ans = subWithMOD(ans, escogerA);
            ans = subWithMOD(ans, escogerB);
            ans = mulm(ans, escogerC);

            cout << ans << endl;
        }
    }

    return 0;
}