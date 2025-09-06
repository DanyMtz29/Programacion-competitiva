#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    vector<int> criba(n+1, 0);
    int cont = 0;
    for(int i=2; i<n; i++){
        if(criba[i]==0){//Si es primo
            for(int j=i;j<=n;j+=i){
                criba[j]++;
            }
        }
    }

    for(int i=0;i<=n;i++){
        if(criba[i]==2) cont++;
    }
    cout<<cont<<endl;
}

int main(){
    int n;
    cin>>n;
    solve(n);
    return 0;
}