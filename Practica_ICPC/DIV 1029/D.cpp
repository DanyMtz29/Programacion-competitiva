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

const int MAXN = 200005;

int arr[MAXN],n;

bool solve(int x, int y){
    for( int i = 1; i <= n; i++ ){
        int xx = i*x;
        int yy = (n-i+1)*y;
        if( !(arr[i-1]-xx-yy==0) ) return false;
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
        cin>>n;
        forN(n,arr);

        //Formulas
        // y = (na-b)/n^2-1 -> y
        // x = a - n^2*a-nb/n^2-1 -> x
        
        int a = arr[0];
        int b = arr[n-1];
        int x = ( a - ( (n*n*a-n*b)/(n*n-1) ));
        int y = ( n*a-b )/(n*n-1);

        if( x >= 0 && y >= 0 && solve(x,y))
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    }
    return 0;
}