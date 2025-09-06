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

bool solve(vi& a, int k, int n, int mx){
    int levelWater = 0;
    int curTower = a[k];
    sort( all(a) );
    while( levelWater < curTower && curTower != mx){
        int find = curTower - levelWater;
        int it = lower_bound(all(a), find+curTower) - a.begin();
        if( it == n || a[it]-curTower > find )
            it--;
        if( a[it] == curTower ) return false;
        
        int diff = a[it] - curTower;
        curTower = a[it];
        levelWater += diff;
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
        int n,k;
        cin>>n>>k;
        k--;
        vi a(n);
        int mx = -1;
        for( int i = 0; i < n; i++ ){
            cin>>a[i];
            mx = max(mx,a[i]);
        }
        if( solve(a,k,n,mx) ) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}

/*
    1 2 3 5 6

    3 5
*/