//https://cses.fi/problemset/task/2416
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

#define top st.top()

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        vi arr(n), next(n), prefix(n+1);
        //Para el binary lifting
        int M = 20;
        vector<vector<int>> par(n, vector<int>(M, n));
        vector<vector<int>> changes(n, vector<int>(M, 0));

        //Construccion del arreglo prefix
        prefix[0] = 0;
        for( int i = 1; i <= n; i++ ){
            cin>>arr[i-1];
            prefix[i] = prefix[i-1] + arr[i-1];
        }

        //Construccion del arreglo NEXT
        stack<int> st;
        for( int i = n-1; i >= 0 ; i-- ){
            while( !st.empty() && arr[top] <= arr[i]){
                st.pop();
            }
            if( st.empty() ){
                next[i] = n;
                changes[i][0] = ((n-i)*arr[i]) - ( prefix[n]-prefix[i]);
            }else{
                next[i] = top;
                par[i][0] = top;
                changes[i][0] = ((top-i)*arr[i]) - ( prefix[top]-prefix[i]);
            }
            st.push(i);
        }
        //Construir de padres (saltos) y cambios
        for( int i = n-2; i >= 0; i-- ){
            int curSum = 0;
            for( int j = 1; j < M ; j++ ){
                if( par[i][j-1] == n ) break;
                par[i][j] = par[ par[i][j-1] ][j-1];
                changes[i][j] = changes[ par[i][j-1] ][j-1] + changes[i][j-1];
            }
        }

        // for( int i = 0; i < n; i++ ){
        //     cout<<"\narr["<<i<<"]: "<<arr[i]<<"\n";
        //     for( int j = 0; j < 4; j++ ){
        //          cout<<"padre "<<j<<": "<<par[i][j]<<" ";
        //          cout<<"Cambios en "<<j<<": "<<changes[i][j]<<"\n";
        //     }
        //     cout<<"\n";
        // }

        while(q--){
            int l, r; cin>>l>>r;
            l--;r--;
            int ans = 0;
            for( int j = M-1; j >= 0; j-- ){
                if( par[l][j] != n && par[l][j] <= r ){
                    ans += changes[l][j];
                    l = par[l][j];
                }
            }
            if( l < r ){
                ans += ((r-l)*arr[l]) - ( prefix[r+1]-prefix[l+1]);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
/*
NEXT
 2 5 1 4 3 7 2 8 1
 0 1 2 3 4 5 6 7 8
 1 5 3 5 5 7 7 9 9

PREFIX SUM
 2 5 1 4  3  7  2  8  1
 2 7 8 12 15 22 24 32 33
PADRES
-
8 0 0 0 0 0 0 0 0 0
4 9 0 9 0 0 0 0 0 0
2 5 7 5 7 7 9 9 0 0
1 1 5 3 5 5 7 7 9 9
- 2 5 1 4 3 7 2 8 1
        
CAMBIOS
-
8 0  0  0  0 0 0  0 0 0 0
4 19 0  13 0 0 0  0 0 0 0
2 7  12 1  6 5 12 7 0 0 0
1 0  7  0  1 0 5  0 7 0 0
- 2  5  1  4 3 7  2 8 1 -
*/