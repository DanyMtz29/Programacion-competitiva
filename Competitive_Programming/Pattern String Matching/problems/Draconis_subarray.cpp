//https://codeforces.com/problemset/gymProblem/104412/D
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
const int SHIFT = 1000000001;
using namespace std;

const int MOD1 = 1000000007; 
const int MOD2 = 1000000009;

const int P1 = 91138233;
const int P2 = 97266353;
      


int poly_hash(const vector<int> &a, int tam) {
    int h1 = 0, p1 = 1;
    int h2 = 0, p2 = 1;
    for (int i = 0; i < tam; i++) {
        int x1 = a[i]%MOD1;
        int x2 = a[i]%MOD2;
        
        h1 = (h1 + x1 * 1LL * p1) % MOD1;
        p1 = (p1 * 1LL* P1) % MOD1;
        
        h2 = (h2 + x2 * 1LL* p2) % MOD2;
        p2 = (p2 * 1LL* P2) % MOD2;
    }
    
    return ((int64_t)h1 << 32) | (unsigned int)h2;
}


int powr(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}


int inv(int x, int mod) {
    return powr(x, mod - 2, mod);
}


int rabin_karp(const vector<int> &text, const vector<int> &pattern) {
    int n = text.size(), m = pattern.size();
    if (m > n) return 0;

    
    int64_t pat_hash = poly_hash(pattern, pattern.size());
    
    int64_t text_hash = poly_hash(text,pattern.size());

    int ans = 0;
    if (text_hash == pat_hash) ans++;

    
    int inv_p1 = inv(P1, MOD1);
    int inv_p2 = inv(P2, MOD2);
    int high1  = powr(P1, m - 1, MOD1);
    int high2  = powr(P2, m - 1, MOD2);

    for (int i = 1; i + m <= n; i++) {
        
        unsigned int low2 = (unsigned int)(text_hash & 0xFFFFFFFF);
        int h1 = text_hash >> 32;
        int h2 = low2;

        int out = text[i - 1];
        int in  = text[i + m - 1];
        
        int out1 = out % MOD1;
        int out2 = out % MOD2;
        int in1 = in % MOD1;
        int in2 = in % MOD2;
        
        
        h1 = (h1 - out1 + MOD1) % MOD1;
        h1 = (h1 * inv_p1) % MOD1;
        h1 = (h1 + in1 * 1LL * high1 % MOD1) % MOD1;
        
        
        h2 = (h2 - out2 + MOD2) % MOD2;
        h2 = (h2 * inv_p2) % MOD2;
        h2 = (h2 + in2 * 1LL * high2 % MOD2) % MOD2;

        
        text_hash = ((int64_t)h1 << 32) | (unsigned int)h2;

        if (text_hash == pat_hash) ans++;
    }
    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n);
    vi b(m);
    forN(n,a);
    forN(m,b);

    vi pattern(n-1);
    vi text(m-1);
    int ans = 0;
    if( n > m ){
        cout<<"0\n";
        return;
    }
    if( n == 1 ){
        cout<<m<<"\n";
        return;
    }else{
        for( int i = 1; i <n ; i++ )
            pattern[i-1] = a[i]-a[i-1]+SHIFT;
        for( int i = 1; i < m; i++ )
            text[i-1] = b[i]-b[i-1]+SHIFT;
    }

    ans = rabin_karp(text,pattern);
    cout<<ans<<"\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}