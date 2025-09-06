//https://codeforces.com/problemset/problem/1280/A
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

const int MAXN = 1e6;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--){
        int x;
        cin>>x;
        string s;
        cin>>s;
        int it = 1;
        int ans = s.size();
        while(it<=x){
            if( s.size() < x  ){
                int times = (s[it-1]-'0')-1;
                string sub(s.substr(it));
                while(times--) s+=sub;
                ans = s.size();
            }else{
                int res = ((ans-it)%MOD + MOD)%MOD;
                int times = ((s[it-1]-'0')-1);
                res = (res*times)%MOD;
                ans = (ans+res)%MOD;
            }
            it++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}