#include <bits/stdc++.h>
//#define int long long int
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
const int MOD=1e9+7;
using namespace std;

#define ll long long int

const ll MOD1 = 1000000007;  
const ll P1   = 31;          
const ll MOD2 = 1000000009;  
const ll P2   = 37;          

ll poly_hash(const string &s) {
    ll h1 = 0, p1 = 1;
    ll h2 = 0, p2 = 1;
    for (ll i = 0; i < (ll)s.size(); i++) {
        ll x = s[i] - 'a' + 1;
        
        h1 = (h1 + x * p1) % MOD1;
        p1 = (p1 * P1) % MOD1;
        
        h2 = (h2 + x * p2) % MOD2;
        p2 = (p2 * P2) % MOD2;
    }
    
    return ((int64_t)h1 << 32) | (unsigned ll)h2;
}


ll powr(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}


ll inv(ll x, ll mod) {
    return powr(x, mod - 2, mod);
}


ll rabin_karp(const string &text, const string &pattern) {
    ll n = text.size(), m = pattern.size();
    if (m > n) return 0;

    
    ll pat_hash = poly_hash(pattern);
    
    ll text_hash = poly_hash(text.substr(0, m));

    ll ans = 0;
    if (text_hash == pat_hash) ans++;

    
    ll inv_p1 = inv(P1, MOD1);
    ll inv_p2 = inv(P2, MOD2);
    ll high1  = powr(P1, m - 1, MOD1);
    ll high2  = powr(P2, m - 1, MOD2);

    for (ll i = 1; i + m <= n; i++) {
        
        unsigned ll low2 = (unsigned ll)(text_hash & 0xFFFFFFFF);
        ll h1 = text_hash >> 32;
        ll h2 = low2;

        ll out = text[i - 1] - 'a' + 1;
        ll in  = text[i + m - 1] - 'a' + 1;
        
        
        h1 = (h1 - out + MOD1) % MOD1;
        h1 = (h1 * inv_p1) % MOD1;
        h1 = (h1 + in * 1LL * high1 % MOD1) % MOD1;
        
        
        h2 = (h2 - out + MOD2) % MOD2;
        h2 = (h2 * inv_p2) % MOD2;
        h2 = (h2 + in * 1LL * high2 % MOD2) % MOD2;

        
        text_hash = ((int64_t)h1 << 32) | (unsigned ll)h2;

        if (text_hash == pat_hash) ans++;
    }
    return ans;
}



int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
    
    }
    return 0;
}