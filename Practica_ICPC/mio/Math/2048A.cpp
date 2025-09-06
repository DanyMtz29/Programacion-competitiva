//Problem: https://codeforces.com/problemset/problem/2048/A

#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

int32_t main(){
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        if( n%33 == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}