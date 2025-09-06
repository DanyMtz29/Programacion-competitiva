#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

const int MOD = 1000000;

int countBST( int n ){
    if( n==0 or n==1){
        return 1;
    }

    int ans = 0;
    for( int i = 1; i <= n ; i++ ){
        int x = countBST( i-1 );
        int y = countBST( n-i );
        ans += ( x*y );
    }
    return ans;
}

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
        ans += ( x*y )%MOD;
    }
    return dp[ n ] = ans;
}

int countBSTBottomUp( int N ){
    vec dp( N+1, 0 );
    dp[0] = dp[1] = 1;
    for( int n = 2; n <= N ; n++ ){
        for( int j = 1; j <= n ; j++ ){
            dp[n] += ( dp[ j-1 ] * dp[ n-j ] )%MOD;
        }
    }
    return dp[N];
}

int32_t main(){
    
    int n = 1000;
    //cout<<"Without dp: "<< countBST( n ) <<endl;
    int dp[ 1001 ] = { 0 };
    cout<<"With dp1: "<< countBSTTopDown( n,dp ) << endl;
    cout<<"With dp2: "<< countBSTBottomUp( n ) << endl;
    

    return 0;
}