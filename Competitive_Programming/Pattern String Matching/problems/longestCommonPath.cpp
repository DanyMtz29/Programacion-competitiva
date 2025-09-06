//https://leetcode.com/problems/longest-common-subpath/
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
#define ll long long int

const int MOD1=1e9+7;
const int P1 = 31;
const int MOD2=1e9+9;
const int P2 = 29;

using namespace std;

ll poly_hash(vector<int> a, ll tam){
    int h1 = 0, p1 = 1;
    int h2 = 0, p2 = 1;
    for (int i = 0; i < tam; i++) {
        int x = a[i]+1;
        h1 = (h1 + x * p1) % MOD1;
        p1 = (p1 * P1) % MOD1;
        h2 = (h2 + x * p2) % MOD2;
        p2 = (p2 * P2) % MOD2;
    }
    return ((int64_t)h1 << 32) | (unsigned int)h2;
}

ll pwer( ll a, ll b, ll mod ){
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv( ll x, ll mod){
    return pwer( x, mod-2, mod );
}

bool check(vector<vector<int>>& paths, ll tam){
    set<ll> pathsTotal;

    ll inv_p1 = inv(P1, MOD1);
    ll inv_p2 = inv(P2, MOD2);
    ll high1  = pwer(P1, tam - 1, MOD1);
    ll high2  = pwer(P2, tam - 1, MOD2);

    for( ll i = 0 ; i < paths.size(); i++ ){
        set<ll> curPaths;
        vector<int>& path = paths[i];
        ll pattern_pat = poly_hash(path, tam);

        if( i!=0 ){
            if( pathsTotal.count( pattern_pat ) )
                curPaths.insert(pattern_pat);
        }else{
            curPaths.insert(pattern_pat);
        }

        for( ll j = 1 ; j+tam <= path.size(); j++ ){
             // Desempaqueta los hashes previos
            unsigned int low2 = (unsigned int)(pattern_pat & 0xFFFFFFFF);
            int h1 = pattern_pat >> 32;
            int h2 = low2;

            int out = path[j-1]+1;
            int in = path[j+tam-1]+1;
            
            // Rolling primer hash
            h1 = (h1 - out + MOD1) % MOD1;
            h1 = (h1 * inv_p1) % MOD1;
            h1 = (h1 + in * 1LL * high1 % MOD1) % MOD1;
            
            // Rolling segundo hash
            h2 = (h2 - out + MOD2) % MOD2;
            h2 = (h2 * inv_p2) % MOD2;
            h2 = (h2 + in * 1LL * high2 % MOD2) % MOD2;

            // Reempaqueta
            pattern_pat = ((int64_t)h1 << 32) | (unsigned int)h2;

            if( i!=0 ){
                if(pathsTotal.count( pattern_pat )){
                    curPaths.insert( pattern_pat );
                }
            }else
                curPaths.insert(pattern_pat);
        }
        if( curPaths.empty() ) return false;
        
        swap( curPaths,pathsTotal );
    }
    return true;
}

ll longestCommonPath(vector<vector<int>>& paths){
    int minSize = INT_MAX;
    for( auto path: paths )
        minSize = min(minSize, (int)path.size());
    
    ll l = 1;
    ll r = minSize;
    ll ans = 0;
    while( l<=r ){
        ll mid = (l+r)>>1;
        if( check( paths,mid) ){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return ans;
}

void solve(){
    vvi paths = {{0,1,2,3,4}, {2,3,4}, {4,0,1,2,3}};
    //vvi paths = {{0,1,2,3,4}, {4,3,2,1,0}};
    ll n = 5;
    
    cout<<longestCommonPath( paths )<<"\n";
    //cout<<poly_hash( {0,1,2,3,4},2)<<"\n";
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