//https://cses.fi/problemset/task/3304
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int,int>
#define INFS 1e17
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define ppi pair<pair<int,int>,int>
#define pb push_back
#define F first
#define S second
const int MOD=1e9+7;
using namespace std;

const int M = 18;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        int n, q;
        cin>>n>>q;
        vi a(n);
        forN(n,a);

        stack<int> st;
        vi parent(n);
        //Para el binari lifting
        vvi greaters(n, vi(M, INFS));

        for( int i = n-1 ; i >=0 ; i-- ){
            int x = a[i];
            while( !st.empty() && a[st.top()] <= x){
                st.pop();
            }
            if( st.empty() ){
                parent[i] = INFS;
            }else{
                parent[i] = st.top();
                greaters[i][0] = parent[i];
            }
            st.push( i );
        }
        
        // cout<<"PARENT"<<"\n";
        // for( int i = 0; i < n; i++ )
        //     cout<<"Building: "<<i<<", Grater: "<<parent[i]<<"\n";
        // cout<<""<<"\n";

        //Binary lifting
        for( int i = n-1; i >=0 ; i-- ){
            for( int k = 1; k < M; k++ ){
                if( greaters[i][k-1]  == INFS ) break;
                greaters[i][k] = greaters[greaters[i][k-1]][ k-1 ];
            }
        }

        // cout<<"Padres"<<"\n";
        // for( int i = 0; i < n; i++ ){
        //     cout<<"\nPadres de "<<i<<"\n";
        //     for( int j = 0; j < 4; j++ ){
        //         if( greaters[i][j]==INFS )
        //             cout<<j<<": MAX, ";
        //         else
        //          cout<<j<<": "<<greaters[i][j]<<", ";
        //     }
        //     cout<<"\n";
        // }

        while(q--){
            int l,r;
            cin>>l>>r;
            l--;r--;
            int ans = 1;
            for( int k = M-1; k >= 0; k-- ){
                if( greaters[l][k]==INFS || greaters[l][k] > r) continue;
                ans += (1<<k);
                l = greaters[l][k];
            }
            cout<<ans<<"\n";
        }

    }
    return 0;
}