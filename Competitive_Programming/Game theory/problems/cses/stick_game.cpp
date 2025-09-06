//https://cses.fi/problemset/task/1729
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
        int n,p;
        cin>>n>>p;
        vector<bool> arr(n+1,false);
        vi sticks(p);
        for( int i = 0; i < p; i++ ){
            cin>>sticks[i];
            arr[sticks[i]]=1;
        }
        sort(all(sticks));
        for( int i = 1; i <= n; i++ ){
            if( !arr[i] ){
                for( auto s: sticks ){
                    if( i+s > n ) break;
                    arr[i+s] = 1;
                }
            }
        }

        for( int i = 1; i <= n; i++ ){
            cout<<(arr[i]?"W":"L");
        }
        cout<<"\n";
    }
    return 0;
}