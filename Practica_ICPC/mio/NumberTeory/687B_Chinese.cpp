#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

int GCD( int a, int b ){
    if( b==0 )
        return a;
    else
        return GCD( b, a%b );
}

bool check( int k, vector<int>& c ){
    int gcd = 0;
    for( int num: c ){
        if( num == k) return true;
        gcd = GCD( k,num );
        int temp = -1;
        if( gcd != 1 && gcd != temp){
            temp = gcd;
            k/=gcd;
            gcd = GCD( k, num );
        }
        if ( k == 1) return true;
    }
    return false;
}

int32_t main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin>>n>>k;
    vec c( n );
    for( int i = 0; i < n; i++ ){
        cin>>c[i];
    }

    if( check( k, c ) ){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}