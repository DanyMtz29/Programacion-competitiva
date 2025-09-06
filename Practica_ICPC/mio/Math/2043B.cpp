//Problem: https://codeforces.com/problemset/problem/2043/B
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

int32_t main(){

    int T; cin>>T;
    while( T-- ){

        int n, d; cin>>n>>d;

        cout<<"1 ";
        if( d%3==0 || n >= 3){
            cout<<"3 ";
        }
        if( d==5){
            cout<<"5 ";
        }
        if( d==7 || n>=3 ){
            cout<<"7 ";
        }
        if( d==9  || ( d%3==0 && n>=3 )){
            cout<<"9 ";
        }else{
            if( n>=6 ){
                cout<<"9 ";
            }
        }
        cout<<endl;
    }

    return 0;
}