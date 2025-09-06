#include <bits/stdc++.h>
using namespace std;
#define double long double

const double EPS = 1e-9;

struct Point{
    double x,y;
    Point(){x = y = 0.0;};
    Point(double _x, double _y) : x(_x), y(_y) {}
};

struct Line{
    double a,b,c;
};

void pointsToLine(Point& a, Point& b, Line& line){
    if( fabs(a.x - b.x) < EPS ){//Linea vertical
        line.a=1.0, line.b = 0.0, line.c = -a.x;//Valores por default
    }else{
        line.a = -(double)(a.y-b.y)/(a.x-b.x);
        line.b = 1.0;
        line.c = -(double)(line.a * a.x)-a.y;
    }
}

bool areParallel(Line& l1, Line& l2){//Check coefficients a&b
    return ( fabs(l1.a-l2.a) < EPS) && ( fabs(l1.b-l2.b) < EPS);
}

bool areIntersect(Line l1, Line l2, Point& p){
    if( areParallel(l1,l2) ) return false;
    //Solve the system of 2 linear algebraic equations with 2 unknows
    p.x = ( l2.b * l1.c - l1.b * l2.c ) / ( l2.a * l1.b - l1.a * l2.b );
    if( fabs(l1.b) > EPS ) p.y = -( l1.a * p.x + l1.c );
    else                   p.y = -( l2.a * p.x + l2.c );
    return true;
}

struct Vec{
    double x, y;
    Vec(double _x, double _y): x(_x), y(_y) {};
};

Vec toVec(Point& p1, Point& p2){
    return Vec(p2.x - p1.x, p2.y - p1.y);
}

double cross(Vec a, Vec b){
    return a.x * b.y - a.y * b.x;
}

bool collinear( Point& p, Point& q, Point& r ){
    return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;
}

bool inside(Point& A, Point& B, Point& C){
    return (C.x + EPS >= min(A.x,B.x) && C.x <= max(A.x,B.x) + EPS) &&
           (C.y + EPS >= min(A.y,B.y) && C.y <= max(A.y,B.y) + EPS);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int t;cin>>t;
    while(t--){
        double x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        Point A(x1,y1), B(x2,y2), C(x3,y3), D(x4,y4);
        Point P(0.0,0.0);
        Line l1,l2;
        pointsToLine(A,B,l1);
        pointsToLine(C,D,l2);

        if(!areIntersect( l1, l2, P )){
            if(collinear(A,B,C) && (inside(A,B,C) || inside(A,B,D) || inside(C,D,A) || inside(C,D,B))){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        if(inside(A,B,P) && inside(C,D,P)){
            cout<<"YES"<<"\n";
        }else
            cout<<"NO"<<"\n";
    }
    
    return 0;
}