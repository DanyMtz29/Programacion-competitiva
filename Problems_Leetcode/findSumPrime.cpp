#include <bits/stdc++.h>

#define lli long long int

using namespace std;

void sieve(vector<int>& v, int N, vector<int>& primes){
    for(lli i=2;i<N;i++){
        if(v[i]){
            primes.push_back(i);
            for(lli j=i*i;j<=N;j+=i){
                v[j]=0;
            }
        }
    }
}

int solve(int n){
    vector<int> v(n+1,1);
    vector<int> primes;
    sieve(v,n,primes);

    int sz = primes.size();
    int cont = 0;

    for(int i=0;i<sz;i++){
        for(int j=i;j<sz;j++){
            lli sum = primes[i]+primes[j];
            if(sum>n) break;
            if(v[sum]) {
                cout<<"primes[i]: "<<primes[i]<<endl;
                cout<<"primes[j]: "<<primes[j]<<endl;
                cout<<"Sum: "<<sum<<endl;
                cout<<endl;
                cont++;
            }
        }
    }
    return cont;
}

int main(){
    //666 -> 30
    //285 -> 19
    cout<<"Solve: "<<solve(666)<<endl;   
    return 0;
}