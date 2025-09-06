#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point{
    double x,y;
    Point(){x = y = 0.0;};
    Point(double _x, double _y) : x(_x), y(_y) {}

    double hypo(double dx, double dy){
        return sqrt(dx*dx + dy*dy);
    }

    double distance(const Point& other){
        double dx = other.x-this->x;
        double dy = other.y-this->y;
        return hypo(dx,dy);
    }
};

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
bool ccw(Point& p, Point& q, Point& r){
    return cross( toVec(p,q), toVec(p,r) ) > 0;
}
bool collinear( Point& p, Point& q, Point& r ){
    return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int t;cin>>t;
    while(t--){
        double a1,a2,b1,b2,c1,c2;
        cin>>a1>>a2>>b1>>b2>>c1>>c2;
        Point A(a1,a2), B(b1,b2), P(c1,c2);
        if( collinear(A,B,P) ){
            cout<<"TOUCH"<<"\n";
        }else if( ccw(A,B,P) ){
            cout<<"LEFT"<<"\n";
        }else{
            cout<<"RIGHT"<<"\n";
        }
    }
    
    return 0;
}