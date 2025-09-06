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
        vvi a(n);
        
        for( int i = 0; i < n; i++ ){
            int l,r,real;
            cin>>l>>r>>real;
            a[i] = {l,r,real};
        }

        sort( all(a) );

        priority_queue<vi> pq;

        /*
        1 4 5
        1 11 15
        3 4 20
        4 5 10
        */
        // cout<<"CASINOS"<<"\n";
        // for( auto x: a )
        //     cout<<"{"<<x[0]<<","<<x[1]<<","<<x[2]<<"}\n";
        int j = 0;
        int ans = k;
        while( j < n && a[j][0] <= k){
            while( j<n ){
                auto &cur = a[j];
                if( cur[0] <= k ) pq.push({cur[2],cur[1],cur[0]});
                else break;
                j++;
            }
            while( !pq.empty() ){
                if( pq.top()[1] >= k ){
                    k = pq.top()[0];
                    ans = max(ans,k);
                    pq.pop();
                    break;
                }else
                    pq.pop();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}