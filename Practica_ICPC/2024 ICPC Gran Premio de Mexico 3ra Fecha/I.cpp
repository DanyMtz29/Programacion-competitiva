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

const int MAXN = 1000001;

int primes[MAXN], freq[MAXN], d[MAXN];
int n,q;

void fillPrimes(){
    for (int i = 2; i <= MAXN; i++){
        if (primes[i] == 0){
            primes[i] = i;
            for (int j = i * i; j <= MAXN; j += i){
                primes[j] = i;
            }
        }
    }
}

set<int> factorization(int x){
    set<int> ans;
    while (x > 1){
        ans.insert(primes[x]);
        x /= primes[x];
    }
    return ans;
}

int exclusion_inclusion(set<int>& divisors){
    vi divs(divisors.begin(), divisors.end());
    int m = divs.size();
    int ans = 0;
    for (int i = 1; i < (1 << m); i++) {
		int lcm = 1;
		for (int j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				lcm *= divs[j];
			}
		}
		if (__builtin_popcount(i) % 2 == 0) {
			ans -= d[lcm];
		}
		else {
			ans += d[lcm];
		}
	}
    return ans;
}

int pwr(int a, int b){
    int r = 1;
    while(b){
        if(b&1) r*=a,r%=MOD;
        a*=a,a%=MOD;
        b>>=1;
    }
    return r%MOD;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        //Llenado de los primos
        fillPrimes();
        cin>>n;
        for( int i = 0; i < n; i++ ){
            int x;
            cin>>x;
            freq[x]++;
        }

        d[1] = n;
        for( int i = 2; i <= MAXN ; i++ ){
            d[i] += freq[i];
            for( int j = i+i; j <= MAXN ; j+=i ){
                 d[i] += freq[j];
            }
        }
        cin>>q;
        while(q--){
            int platillo;
            cin>>platillo;
            //if( platillo == 1 ) {cout<<n<<"\n"; continue;}

            set<int> sts = factorization(platillo);
            int ans = exclusion_inclusion(sts);
            cout<<(pwr(2,n-ans))<<"\n";
        }
        
    }
    return 0;
}