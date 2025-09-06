#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

int MAX = 1e7 + 5;
vec sieve(MAX, 0);

void criba(){
    sieve[1]=1;
    for(int i=2;i<=MAX;i++){
        if(!sieve[i]){
            sieve[i] = i;
            for(int j=i*i;j<=MAX;j+=i){
                sieve[j]=i;
            }
        }
    }
}

int gcd (int a, int b){
    if( b==0 ){
        return a;
    }else{
        return gcd( b, a%b );
    }
}

set<int> calculateFactors(int b){
    set<int> factors;
    while( b>1 ){
        factors.insert( sieve[b] );
        b /= sieve[b];
    }
    return factors;
}

bool check( vec& arr ){
    //Calculate the gcd of the array
    int N = arr.size();
    int GCD = 0;
    for( int i = 0; i < N; i++ ){
        GCD = gcd( GCD, arr[i] );
    }

    //Set to keep primer factors of all numbers
    set<int> factors;
    for( int i = 0; i < N; i++ ){
        int b = arr[i]/GCD;

        //Set of prime factors of b
        set<int> factorsB = calculateFactors( b );

        for( auto& f: factorsB ){
            
            if( factors.count( f ) ){ //If the Set already contains prime factor return false
                return false;
            }else{
                factors.insert( f );
            }
        }   
    }
    return true;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;
    vec arr(N);
    for( int i = 0; i < N; i++ ){
        cin>>arr[i];
    }
    criba();

    if( check( arr ) ){
        cout<< "YES" <<endl;
    }else{
        cout<< "NO" << endl;
    }

    return 0;
}