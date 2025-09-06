#include <bits/stdc++.h>
#define lli long long int

const int N = 1000000;
using namespace std;

void primeSieve(vector<int>& sieve){
    sieve[1]=0;
    for(lli i=2;i<=N;i++){
        if(sieve[i]){
            for(lli j=i*i;j<=N;j+=i){
                sieve[j]=0;
            }
        }
    }
}

void rangePrimes(vector<int>& sieve){
    sieve[1]=0;
    int cont = 0;
    for(lli i=2;i<=N;i++){
        if(sieve[i]){
            sieve[i] = ++cont;
            for(lli j=i*i;j<=N;j+=i){
                sieve[j]=0;
            }
        }else{
            sieve[i]=cont;
        }
    }
}

int  main(){
    vector<int> sieve(N,1);
    int a = 50;
    int b = 100;
    rangePrimes(sieve);
    cout<<sieve[b]-sieve[a-1]<<endl;
    return 0;
}