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

struct Point{

    int x,y;
    bool operator < ( Point P )const{
        if( x == P.x ) return y < P.y;
        else return x<P.x;
    }    
    bool operator == ( Point P )const{
        return ( x == P.x && y == P.y);
    }
};

bool clockwise(Point& a, Point& b, Point& c){
    return a.x * ( c.y-b.y ) + b.x * ( a.y-c.y ) + c.x * ( b.y - a.y ) > 0;
}
bool anticlockwise(Point& a, Point& b, Point& c){
    return a.x * ( c.y-b.y ) + b.x * ( a.y-c.y ) + c.x * ( b.y - a.y ) < 0;
}
bool collinear(Point& a, Point& b, Point& c){
    return a.x * ( c.y-b.y ) + b.x * ( a.y-c.y ) + c.x * ( b.y - a.y ) == 0;
}

bool check_Grahm(vector<Point>& points, set<Point>& A){
    int n = points.size();

    sort(all(points));

    vector<Point> up,down;
    Point first = points[0], last = points.back();

    up.pb(first);down.pb(first);
    for( int i = 1; i < n; i++ ){
        //Up set
        if( i == n-1 || !anticlockwise(first,points[i],last)){
            while( up.size() >= 2 && anticlockwise(up[up.size()-2], up[up.size()-1], points[i]) ){
                up.pop_back();
            }
            up.pb(points[i]);
        }
        //Down set
        if( i==n-1 || !clockwise( first,points[i],last )){
            while( down.size() >= 2 && clockwise(down[ down.size()-2 ], down[ down.size()-1 ], points[i]) ){
                down.pop_back();
            }
            down.pb(points[i]);
        }
    }
    points.clear();
    for( int i = 0; i < up.size(); i++ ){
        points.pb( up[i] );
    }
    for( int i = 0; i < down.size(); i++ ){
        points.pb( down[i] );
    }
    sort( all(points) );
    eraseU(points);
    
    for( int i = 0; i < points.size(); i++ ){
        //if( points[i].x == A[i].x && points[i].y == A[i].y) return false;
        if( A.count( points[i] ) ) return false;
    }
    return true;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        int a; cin>>a;
        vector<Point> A(a);
        for( int i = 0; i < a; i++ ){
            cin>>A[i].x>>A[i].y;
        }
        int b;cin>>b;
        vector<Point> B(b);
        for( int i = 0; i < b; i++ ){
            cin>>B[i].x>>B[i].y;
        }
        vector<Point> C(a+b);
        for( int i = 0; i < a; i++ ){
            C[i].x = A[i].x;
            C[i].y = A[i].y;
        }
        int j = 0;
        set<Point> BB;
        for( int i = a; i < a+b; i++ ){
            BB.insert(B[j]);
            C[i].x = B[j].x;
            C[i].y = B[j++].y;
        }
        cout<<(check_Grahm(C, BB)?"YES":"NO")<<"\n";
    }
    return 0;
}