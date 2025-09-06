#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

const int MOD = 1e5;

int addWithMOD( int a, int b ){
    return (a + b) % MOD;
}

int subWithMOD( int a, int b ){
    return ( ( a-b) % MOD + MOD  ) % MOD;
}

int mulWithMOD( int a, int b ){
    return ( a*b ) % MOD; 
}

int pwrWithMOD( int a, int b ){
    int res = 1;
    while( b ){
        if( b ) res = mulWithMOD( res, a );
        a = mulWithMOD( a, a );
        b>>=1;
    }
    return res;
}

int inv( int x ){
    return pwrWithMOD( x, MOD-2 );
}

int divWithMod( int a, int b ){
    return mulWithMOD( a, inv( b ) );
}

int32_t main(){
    
    return 0;
}