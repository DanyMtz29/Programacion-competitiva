#include <bits/stdc++.h>
using namespace std;

#define lli long long int

const int sz = 3;
const int mod = 1e9+7;

struct Mat{
    lli m[sz][sz];
    Mat(){
        memset(m,0,sizeof(m));
    }

    void identity(){
        for(int i=0;i<sz;i++){
            m[i][i] = 1;
        }
    }

    Mat operator* (Mat a){
        Mat res;

        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                for(int k=0;k<sz;k++){
                    res.m[i][j] += m[i][k]*a.m[k][j];
                    res.m[i][j] %=mod;
                }
            }
        }

        return res;
    }
};

lli fib(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    Mat res,T;
    
    res.identity();

    T.m[0][0] = T.m[0][1] = T.m[0][2] = 1;
    T.m[1][1] = T.m[1][1] = 1;
    T.m[2][1] = 1;
    n-=1;
    while(n){
        if(n&1) res = res*T;
        T = T * T;
        n>>=1;
    }
    return (res.m[0][0] + res.m[0][1])%mod; 
}

int main(){
    int t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int res = ((fib(b)-fib(a-1)+mod)%mod);
        cout<<res<<endl;
    }
    return 0;
}