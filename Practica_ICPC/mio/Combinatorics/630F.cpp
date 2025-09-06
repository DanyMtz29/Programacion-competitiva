//Problem: https://codeforces.com/problemset/problem/630/F
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

void pascalTriangle( vector<vector<int>>& pascal, int n, int r ){
    for( int i = 0; i <= n; i++ ){
        for( int j = 0; j <= min(i,r); j++ ){
            //Case base
            if( j == 0 || j == i ){
                pascal[i][j] = 1;
            }else{
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }
}

int32_t main(){
    int N; cin>>N;
    vector<vector<int>> pascal( N+1, vector<int>( 8 ) );
    pascalTriangle( pascal, N, 7 );
    int comb5 = pascal[N][5];
    int comb6 = pascal[N][6];
    int comb7 = pascal[N][7];
    cout<<( comb5+comb6+comb7 )<<endl;
    return 0;
}