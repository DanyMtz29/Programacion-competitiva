#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-18;
const double PI = acos(-1);

struct Point{
    double x,y;
    Point(){x = y = 0.0;};
    Point(double _x, double _y) : x(_x), y(_y) {}

    bool operator<(Point& other) const {
        if (fabs(this->x - other.x) > EPS) return this->x < other.x;
        if (fabs(this->y - other.y) > EPS) return this->y < other.y;
    }

    bool operator==(Point& other) const{
        return (fabs(this->x - other.x)) < EPS &&  (fabs(this->y - other.y)) < EPS;
    }

    double hypo(double dx, double dy){
        return sqrt(dx*dx + dy*dy);
    }

    double distance(const Point& other){
        double dx = other.x-this->x;
        double dy = other.y-this->y;
        return hypo(dx,dy);
    }

    void rotate(double teta){
        double rad = teta * (PI/180.0);
        double x_ = (cos(rad) * this->x) - (sin(rad)*this->y);
        double y_ = (sin(rad) * this->x) + (cos(rad)*this->y);
        this->x = x_;
        this->y = y_;
    }
};

ostream& operator<<(ostream& out, const Point& A){
    out<<"{"<<A.x<<","<<A.y<<"}";
    return out;
}

struct Vec{
    double x, y;
    Vec(double _x, double _y): x(_x), y(_y) {};
};

Vec toVec(Point& p1, Point& p2){
    return Vec(p2.x - p1.x, p2.y - p1.y);
}

Vec scale(Vec& v, double s){
    return Vec(v.x * s, v.y * s);
}

Point translate(Vec v, Point& t){
    return Point(v.x + t.x, v.y + t.y);
}

double dot(Vec& a, Vec& b){//Producto punto
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(Vec& v){
    return (v.x * v.x + v.y * v.y);
}

// returns the distance from p to the line defined by
 // two points a and b (a and b must be different)
 // the closest point is stored in the 4th parameter (byref)
 double distToLine(Point p, Point a, Point b, Point &c) {
    // formula: c = a + u * ab
    Vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c= translate(scale(ab, u), a);
    //translate a toc
    return p.distance(c); 
}

 // returns the distance from p to the line segment ab defined by
 // two Points a and b (still OK if a == b)
 // the closest point is stored in the 4th parameter (byref)
double distToLineSegment(Point& p, Point& a, Point& b, Point& c) {
    Vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { 
        c = Point(a.x, a.y);
        return p.distance(a);
    }
    // Euclidean distance between p and a
    if (u > 1.0) { 
        c = Point(b.x, b.y);
        // closer to b
        return p.distance(b);
    }
    // Euclidean distance between p and b
    return distToLine(p, a, b, c); 

}

double angle(Point& a, Point& b, Point& P){
    Vec Pa = toVec(P,a), Pb = toVec(P,b);
    //Formula: angle = arccos( Pa*Pb/ (|Pa|*|Pb|) )
    return acos( dot(Pa,Pb) / sqrt( norm_sq(Pa) * norm_sq(Pb) ));
}

double cross(Vec a, Vec b){
    return a.x * b.y - a.y * b.x;
}
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(Point& p, Point& q, Point& r){
    return cross( toVec(p,q), toVec(p,r) ) > 0;
}
// returns true if point r is on the same line as the line pq
bool collinear( Point& p, Point& q, Point& r ){
    return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    Point A(3.0,1.0), B(6.0,4.0), P(4.0,5.0);
    //Point C(0.0,0.0);
    //cout<<distToLine(P,A,B,C)<<"\n";
    if( collinear(A,B,P) ){
        cout<<"Estan en la misma linea\n";
    }else{
        if( ccw(A,B,P) ){
            cout<<"El punto esta a la izquierda de la linea"<<"\n";
        }else
            cout<<"El punto esta a la derecha de la linea"<<"\n";
    }

    return 0;
}