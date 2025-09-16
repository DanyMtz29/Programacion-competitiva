#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1e9+7;

int inv(int a){
    int res = 1;
    int b = MOD-2;
    while(b){
        if( b&1 ) res*=a, res%=MOD;
        a*=a,a%=MOD;
        b>>=1;
    }
    return res;
}

int solve(int n){
    int a = 26;
    int b = 26;
    for( int i = 2 ; i<= n ; i++ ){
        if(i > 2 && i % 2 == 0){
            b*=26,b%=MOD;
            a*=26,a%=MOD;
        }
        a+=1,a%=MOD;
    }
    return a * inv(b) % MOD;
}

int32_t main(){
    cout<<solve(2)<<"\n";
    cout<<solve(4)<<"\n";

    return 0;
}
/*
    The probablity of the 1 operation:
    --26/26
    2 ops:
    --27/26
    3 ops:
    --28/26
    4 ops:
    --729/676
*/