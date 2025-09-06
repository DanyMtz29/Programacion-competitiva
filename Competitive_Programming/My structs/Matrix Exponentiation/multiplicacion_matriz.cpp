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

struct Mat{
    int sz;
    vvi m;

    Mat(int n){
        this->sz = n;
        this->m.resize(n,vi(n,0));
    }
    void identity(){
        for(int i=0;i<sz;i++){
            m[i][i] = 1;
        }
    }
    void cpy(vvi& a){
        for( int i = 0; i < sz; i++ ){
            for( int j = 0; j < sz; j++ ){
                m[i][j] = a[i][j];
            }
        }
    }
    Mat operator*(Mat a){
        Mat res(sz);
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                for(int k=0;k<sz;k++)
                    res.m[i][j] += m[i][k] * a.m[k][j];
        return res;
    }

    void show(){
        cout<<"Matriz"<<"\n";
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
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cout<<"Ingresa el tamanio de la matriz"<<"\n";
        int sz; cin>>sz;
        Mat m(sz), res(sz);
        
        vvi a(sz,vi(sz));
        cout<<"Ingresa los valores de la matriz"<<"\n";
        for( int i = 0; i < sz; i++ ){
            for( int j = 0; j < sz; j++ ){
                cin>>a[i][j];
            }
        }
        m.cpy(a);
        res.identity();

        cout<<"Ingresa la potencia a la que vas a elevar M"<<"\n";
        int N; cin>>N;
        int n = N;
        N--;
        while( N ){
            if( N&1 ) res = res*m;
            m = m*m;
            N>>=1;
        }
        res.show();

    }
    return 0;
}
/*

*/