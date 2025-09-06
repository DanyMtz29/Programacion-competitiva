#include <bits/stdc++.h>
#define lli long long int
using namespace std;

//1 2 3 5  7
//1 3 6 11 18

//1 3 1 
void solve(vector<int>& v, int n){
    lli sum = 0;
    vector<int> mod(n,-1);
    int l = 0, r=0;
    int sz = 0;
    for(int i=0;i<n;i++){//4 6 10   3
        sum+=v[i];
        int res = sum%n;
        if(mod[res] != -1){
            l = mod[res]+1;
            r = i;
            sz=r-l+1;
            break;
        }else{
            mod[res] = i;
        }
    }
    if(sz==0) cout<<"-1"<<endl;
    else{
        cout<<sz<<endl;
        for(int i=l;i<=r;i++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> v(N);
        for(int i=0;i<N;i++) cin>>v[i];
        solve(v,N);
    }
    return 0;
}