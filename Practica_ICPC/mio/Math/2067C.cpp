//Problem: https://codeforces.com/problemset/problem/2067/C
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

vec reorder(int n){
    vec arr(10, 9);
    int i = 9;
    while(n>0){
        int res = n%10;
        if( res != 0 ){
            arr[i--] = res;
        }else{
            if( i==9 ) arr[i--] = res;
        }
        n/=10;
    }
    return arr;
}

int count( int index, int decimal, int n){

    if(n == 7) return 0;

    int cont = 9;

    if( index==9 ){ //First number
        if( n > 7) cont =  n-7;
        else cont = n+3;
    }else if( index==8 ){//Second number
        if( n > 7 ){
            cont = 17-n;
            if( cont > decimal ) cont++;
        }else{
            cont = 7-n;
            if( cont > decimal ) cont++;
        }

        //special case
        if( n==8 ){
            cont = min( cont, decimal+1 );
        }
    }else{//n Number
        if( n > 7 ){
            cont = 17-n;
        }else{
            cont = 7-n;
        }
    }
    return cont;
}

int solve(vec& arr){

    int i = 7; // Index of array

    int mn = 7;
    for( int i = 9; i >= 0 ; i-- ){
        int cont = 0;
        if( i == 9)
            cont = count( i, 9, arr[i]);
        else
            cont = count( i, arr[i+1], arr[i]);

        if(cont == 0) return 0;
        
        mn = min( mn, cont );
    }
    return mn;
}

int32_t main(){
    
    ios::sync_with_stdio( false );
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin>>T;
    while( T-- ){
        int n;
        cin>>n;

        vec arr = reorder(n);

        int total = solve(arr);

        cout<<total<<endl;
    }

    return 0;
}