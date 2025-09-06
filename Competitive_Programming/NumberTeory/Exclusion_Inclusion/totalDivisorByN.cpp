#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
    int sz = primes.size();

    int ans = 0;
    for(int i=1;i<(1<<sz);i++){

        int lcm = 1;//minimo comun multiplo
        for(int j=0;j<sz;j++){
            if((i>>j)&1){
                //cout<<"Divisible por: "<<primes[j]<<endl;
                lcm *= primes[j];
            }

        }

        if(__builtin_popcount(i)%2==0){
            ans -= (n/lcm);
        }else{
            ans += (n/lcm);
        }
    }
    cout<<"\n\nAnswer: "<<ans<<endl;
    return 0;
}