#include <bits/stdc++.h>

#define lli long long int

using namespace std;
const int mod = 1e9+7;

lli getGcd(lli a, lli b){
    return (b==0)?a:getGcd(b,a%b);
}

lli get(lli a, lli b){
    return (a*b)/getGcd(a,b);
}

int main(){
    lli n,t;
    cin>>t;
    while(t--){
        cin>>n;
        lli num = 1;
        lli total = 0;
        int div = 2;
        do{
            lli numPrev = n/num;
            num = get(num,div);
            lli numNext = n/num;
            total = (total + ( ( numPrev-numNext ) * div++ ) ) %mod;
        }while(num<=n);
        cout<<total<<endl;
    }
    return 0;
}