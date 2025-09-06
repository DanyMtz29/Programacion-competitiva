#include <bits/stdc++.h>

using namespace std;

void sieve(vector<int>& primes, vector<int>& sieveArr, int n){
    for(int i=2;i<n;i++){
        if(sieveArr[i]){
            primes.push_back(i);
            for(int j=i*i;j<n;j+=i){
                sieveArr[j]=0;
            }
        }
    }
}

int main(){
    int N =30;
    vector<int> sieveArr(N,1);
    vector<int> primes;
    sieve(primes,sieveArr,N);
    copy(primes.begin(),primes.end(),ostream_iterator<int>(cout,"|"));
    return 0;
}