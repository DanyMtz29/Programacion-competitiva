//Problem: https://codeforces.com/problemset/problem/2044/E
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

int pwr( int a, int b ){
    int res = 1;
    while( b ){
        if( b&1 ) res*=a;
        a*=a;
        b/=2;
    }
    return res;
}

bool isValid( int num, int l2, int r2 ){
    return num >= l2 && num <= r2;
}

int binaryInf(int l1, int r1, int k, int l2, int r2){
    int ret = -1;

    while( l1<=r1 ){
        int mid = ( l1 + r1 )/2;

        if( isValid(mid*k, l2, r2) ){
            ret = mid;
            r1 = mid - 1;
        }else{
            if(mid*k <= l2)
                l1 = mid + 1;
            else
                r1 = mid - 1;
        }
    }
    return ret;
}

int binarySup(int l1, int r1, int k, int l2, int r2){
    int ret = -1;
    int r = r1;
    int l = l1;
    while( l1 >= l && r1 <= r && l1<=r1 ){
        int mid = ( l1 + r1 )/2;
        if( isValid(mid*k, l2, r2) ){
            ret = mid;
            l1 = mid + 1;
        }else{
            if(mid*k <= l2)
                l1 = mid + 1;
            else
                r1 = mid - 1;
        }
    }
    return ret;
}

int solve( int k, int l1, int r1, int l2, int r2 ){
    int limit = 0;
    int p = pwr( k,limit );
    int cont = 0;
    while( r2/p >= l1 ){
        int l = binaryInf( l1, r1, p, l2, r2 );
        if( l != -1 ){
            int r = binarySup( l1, r1, p, l2, r2 );
            cont += ( r - l + 1 );
        }
        p = pwr( k,++limit );
    }
    return cont;
}

int32_t main(){
    ios::sync_with_stdio( false );
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin>>T;

    while( T-- ){
        int k, l1, r1, l2, r2;
        cin>>k>>l1>>r1>>l2>>r2;
        cout<<solve( k, l1, r1, l2, r2 )<<endl;
    }

    return 0;
}