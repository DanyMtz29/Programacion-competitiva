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

const int MAXN = 5000005;

int sieve[MAXN], dp[MAXN+1];

void fillSieve(){
    for( int i = 1; i <= MAXN; i++ ){
        sieve[i] = i;
    }
    sieve[0] = sieve[1] = 0;
    for( int i = 2; i <= MAXN; i++ ){
        if( sieve[i] == i){
            for( int j = i*i; j <= MAXN ; j+=i ){
                sieve[j] = i;
            }
        }
    }
}

int fact(int n){
    int res = 0;
    while( n > 1 ){
        res++;
        n = (n/sieve[n]);
    }
    return res;
}

void fillDp(){
    dp[0] = 0;
    for( int i = 1; i <= MAXN ; i++ ){
        dp[i] = fact(i) + dp[i-1];
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    fillSieve();
    fillDp();
    cin>>T;
    while(T--){
        int a,b; cin>>a>>b;
        cout<<dp[a]-dp[b]<<"\n";
    }
    return 0;
}