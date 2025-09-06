#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int,int>
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define ppi pair<pair<int,int>,int>
#define pb push_back
#define F first
#define S second
#define forEC(var, container) for( const auto& var: container)
#define forE(var, container) for( const auto& var: container)
const int MOD=1e9+7;
using namespace std;

#define N 1000000

int sieveArr[N+1] = {0};
vector<int> primes;

//Sieve of Eratosthenes (O(NLogLogN))
void sieve(){
	for(long long i=2; i<=N; i++){
		//mark non primes as 1
		if(sieveArr[i]==0){
			primes.push_back(i);
			//marking all multiples of i (prime) as non-prime
			for(long long j= i*i; j<=N; j+=i){
				sieveArr[j] = 1; //non-prime
			}
		}
	}
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    sieve();
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int a = n+1, b = n+N;
        vector<int> segment(b-a+1,0);

        for(auto p : primes){

			//stop the loop if prime is larger than root n
			if( p*p > b){
				break;
			}

			int start = (a/p) * p;
			
			// don't start from 0, instead 2 * prime
			if(p>=a and p<=b){
				start = 2 * p;
			}

			for(int j = start; j<=b; j = j + p){
				if(j < a){
					continue;
				}
				//non-prime
				segment[j - a] = 1;
			}
		}
					//Loop over the number m ... n and print the primes
		for(int i=a; i<=b; i++){
			if(segment[i-a]==0 and i!=1){
				cout<<i<<endl;
                break;
			}
		}
    }
    return 0;
}