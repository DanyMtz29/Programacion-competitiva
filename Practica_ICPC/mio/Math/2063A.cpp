//Problem: https://codeforces.com/problemset/problem/2063/A
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

/**
 * For the range [l-r], the coprime numbers are always determined by the difference
 * between r and l. This is because all consecutive numbers are coprime.
 * 
 * Example: [{2,3}, {3,4}, {4,5}, {5,6}, {6,7}, ...]
 * 
 * This happens because the difference between any number n and n+1 is always 1, 
 * and gcd(1, n) is always 1. This means that gcd(n, n+1) = 1, so they are coprime.
 */


int32_t main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin>>T;

    while( T-- ){
        int l, r; cin>>l>>r;
        if(l==1 && r==1) cout<<"1"<<endl;
        else cout<<(r-l)<<endl;
    }


    return 0;
}