//Problem: https://codeforces.com/problemset/problem/131/C
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

void pascalTriangle( vector<vector<int>> & pascal ){
    int t = 30;
    for( int i = 0; i <= t ; i++ ){
        for( int j = 0; j <= min( i,t ); j++ ){
            //Base case
            if( j == 0 || j == i ){
                pascal[i][j] = 1;
            }else{
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }


}

int32_t main(){
    
    vector< vector< int > > pascal( 31, vector<int>(31) );
    pascalTriangle(pascal);

    int N, M, T; cin>>N>>M>>T;
    int res = 0;
    int n = N;

    while( N>=4 ){
        if( T-N > 0 && T-N <= M ){
            int boys = pascal[n][N];
            int girls = pascal[M][T-N];
            int bg = boys*girls;
            res += bg;
        }
        N--;
    }
    cout<<res<<endl;
    return 0;
}