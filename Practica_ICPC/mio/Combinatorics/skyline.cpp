//Problem : https://www.spoj.com/problems/SKYLINE/
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

const int MOD = 1000000;

int countBSTTopDown( int n, int dp[] ){
    if( n==0 or n==1 ){
        return 1;
    }

    if( dp[ n ] != 0 ){
        return dp[n];
    }

    int ans = 0;
    for( int i = 1; i <= n; i++ ){
        int x = countBSTTopDown( i-1, dp );
        int y = countBSTTopDown( n-i, dp );
        ans += ( (x*y)%MOD )%MOD;
    }
    return dp[ n ] = ans%MOD;
}

int32_t main(){
    
    int n;
    cin>>n;
    int dp[1001] = {0};
    while( n != 0 ){
        cout<<( countBSTTopDown( n, dp ) )<<endl;
        cin>>n;
    }

    return 0;
}