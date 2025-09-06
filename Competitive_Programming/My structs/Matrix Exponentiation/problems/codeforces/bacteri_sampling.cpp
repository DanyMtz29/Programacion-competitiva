//https://codeforces.com/problemset/gymProblem/105164/B
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

const int sz = 20;

struct Mat{
    int m[sz][sz];
    Mat(){
        memset(m,0,sizeof(m));
    }
    void identity(){
        for(int i=0;i<sz;i++){
            m[i][i] = 1;
        }
    }
    Mat operator*(Mat a){
        Mat res;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                for(int k=0;k<sz;k++){
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= MOD;
                }
        return res;
    }

    void show(){
        for( int i = 0; i < sz; i++ ){
            for( int j = 0; j < sz; j++ ){
                 cout<<m[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--){
        Mat a,res;
        res.identity();
        a.m[0][5] = a.m[0][9] = a.m[0][13] = a.m[0][17] = 3;
        for( int i = 0; i < sz-1; i++ ){
            a.m[i+1][i] = 1;
        }

        int n;
        cin>>n;

        while(n){
            if( n&1 ) res = res*a;
            a = a*a;
            n>>=1;
        }
        int ans = 0;
        for( int i = 0; i < sz; i++ ){
            ans += res.m[i][0];
            ans%=MOD;
        }
        cout<<ans<<"\n";
    }
    return 0;
}