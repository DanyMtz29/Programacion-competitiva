//Problem: https://codeforces.com/problemset/problem/2062/A
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;cin>>T;
    while(T--){
        int cont=0; 
        string s;
        cin>>s;
        for( int i = 0; i < s.size(); i++ ){
            if( s[i]=='1' ) cont++;
        }
        cout<<cont<<endl;

    }
    return 0;
}