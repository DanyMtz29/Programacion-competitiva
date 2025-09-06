//Problem: https://codeforces.com/problemset/problem/2067/A

#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

bool solve(int x, int y){

    if(x == y){
        return false;
    }
    if( y>x ){
        if( y-1 > x ){
            return false;
        }else{
            return true;
        }
    }

    int y1 = y-1;
    int x1 = x-y1;
    if( x1 % 9 == 0 ){
        return true;
    }else{
        return false;
    }
}

int32_t main(){
    int T; 
    cin>>T;
    while( T-- ){
        int x, y;
        cin>>x>>y;

        if( solve( x, y ) ){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}