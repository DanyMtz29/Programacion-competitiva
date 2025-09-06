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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        vi a(n),b(n);
        forN(n,a);
        forN(n,b);

        // 2 5 4
        // 3 6 4
        int ans = 0 ;
        for( int i = n-1; i >=0 ; i-- ){
            if( a[i] == b[i] ){
                ans = i+1;
                break;
            }
            if( i+1 < n && (a[i] == a[i+1] || b[i] == b[i+1])){
                ans = i+1;
                break;
            }
            if( i+2 < n && (a[i] == a[i+2] || b[i] == b[i+2] || a[i]==b[i+2] || b[i]==a[i+2])){
                ans = i+1;
                break;
            }
            if( i+3 < n && (a[i] == b[i+3] || b[i] == a[i+3]) ){
                ans = i+1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}