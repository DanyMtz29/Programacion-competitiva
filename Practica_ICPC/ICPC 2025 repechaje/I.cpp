#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define pb push_back
#define F first
#define S second
#define e "\n"
#define IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

//Constantes    
const int MOD=1e9+7;

//Estructuras

//Variables
int n;
vector<int> dist;
vector<pi> points;

bool canOrbit(){
    pair<int, bool> limInf = {1, false};
    pair<int, bool> limSup = {dist[0], true};

    for( int i = 0 ; i < n-1 ;i++ ){
        if( limInf.F >= dist[i] ){
            return false;
        }

        if( limSup.F >= dist[i] ){
            limSup.F = dist[i];
        }

        pair<int, bool> a;
        a.F = dist[i] - limSup.F;
        a.S = limSup.S;

        pair<int, bool> b;
        b.F = dist[i] - limInf.F;
        b.S = limInf.S;

        if( a.F > b.F ){
            limSup = a;
            limInf = b;
        }else{
            limSup = b;
            limInf = a;
        }
    }

    int radius;
    if( limInf.S ) radius = limInf.F;
    if( limSup.S ) radius = limSup.F;

    for( int i = n-2 ; i >= 0 ; i-- ){
        radius = dist[i]-radius;
    }
    cout<<radius<<"\n";
    return true;
}

int32_t main(){
    
    cin>>n;
    points.resize(n);
    dist.resize(n-1);
    for( int i = 0 ; i < n ; i++ ){
        int x,y;
        cin>>x>>y;

        points[i] = {x,y};
        if( i>0 ){
            if( points[i].S == points[i-1].S ){
                dist[i-1] = abs(points[i].F-points[i-1].F);
            }else{
                dist[i-1] = abs(points[i].S-points[i-1].S);
            }
        }
    }

    if( !canOrbit() ){
        cout<<"-1\n";
    }

    return 0;
}