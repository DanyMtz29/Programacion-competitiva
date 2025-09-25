#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n,x; cin>>n>>x;
    int a[n];
    for( int i = 0 ; i < n ; i++ ){
        cin>>a[i];
    }

    int mx = 1;
    int cur =1;
    for( int i = 0 ; i+1 < n ; i++ ){
        if( a[i]+x >= a[i+1] ){
            cur++;
            mx = max(mx,cur);
        }else{
            cur=1;
        }
    }
    cout<<mx<<"\n";
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    solve();

    return 0;
}