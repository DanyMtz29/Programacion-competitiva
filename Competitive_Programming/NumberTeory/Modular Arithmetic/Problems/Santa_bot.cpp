//https://codeforces.com/problemset/problem/1279/D
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
const int MOD=998244353;
using namespace std;

const int MAXN=1000005;

int pwr(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res*=a,res%=MOD;
        a*=a,a%=MOD;
        b>>=1;
    }
    return res;
}

vector<int> children[MAXN];
int presents[MAXN],n,k,present;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cin>>n;
        vvi children(n);
        for( int i = 0; i < n; i++ ){
            cin>>k;
            while(k--){
                cin>>present;
                children[i].pb(present);
                presents[present]++;
            }
        }

        int ans = 0;
        int invN = pwr(n,MOD-2);
        for( int i = 0; i < n; i++ ){
            int x = 1;
            int invX = (x*invN)%MOD;
            int k = children[i].size();
            int invK = pwr(k,MOD-2);
            for( int j = 0; j < k; j++ ){
                int y = 1;
                int invY = (y*invK)%MOD;
                int tempAns = ((invX * invY)%MOD) * ( presents[children[i][j]] * invN % MOD ) % MOD;
                ans = (ans+tempAns)%MOD;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
2
2 2 1
1 1
*/