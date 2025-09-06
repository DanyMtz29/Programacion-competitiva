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
const int MOD=1e9+7;
using namespace std;

int GCD(int a, int b){
    if(b==0)
        return a;
    return GCD(b, a%b);    
}

bool solve(){
    int n;
    cin>>n;
    vi a(n),b(n);
    forN(n,a);
    forN(n,b);
    vi g_a(n);
    vi g_b(n);
    g_a[0] = a[0];
    for(int i=1;i<n;i++){
        g_a[i] = GCD(g_a[i-1],a[i]);
        if( g_a[i] != a[i] ) return false;
    }
    g_b[n-1] = b[n-1];
    for(int i=n-2;i>=0;i--){
        g_b[i] = GCD(g_b[i+1],b[i]);
        if( g_b[i] != b[i] ) return false;
    }

    if( g_b[0]!=g_a[n-1] ) return false;


    int maxGCD = g_b[0];
    
    int i = 0;
    for(; i < n; i++ ){
        if( GCD( a[i],b[i] ) != maxGCD || b[i] != maxGCD) return false;
        if( a[i]==b[i] ) break;
    }
    
    for( ; i < n; i++ ){
        if( GCD( a[i],b[i] ) != maxGCD || a[i] != maxGCD) return false;
    }

    return true;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--){
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    return 0;
}