//Problem: https://codeforces.com/problemset/problem/2034/A
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

int GCD( int a, int b ){
    if( b==0 ){
        return a;
    }else{
        return GCD( b, a%b );
    }
}

int  LCD( int a, int b ){
    return a*b / GCD( a,b );
}

int32_t main(){
    
    int T; cin>>T;

    while( T-- ){
        int l, r; cin>>l>>r;

        cout<< LCD( l,r ) << endl;
    }

    return 0;
}