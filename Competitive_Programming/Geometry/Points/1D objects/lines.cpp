#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point{
    double x,y;
    Point(){x = y = 0.0;};
    Point(double _x, double _y) : x(_x), y(_y) {}

    bool operator<(Point& other) const {
        //Differents x's
        if (fabs(this->x - other.x) > EPS) return this->x < other.x;
        if (fabs(this->y - other.y) > EPS) return this->y < other.y;
        return false; // considered equal within EPS
    }

    bool operator==(Point& other) const{
        return (fabs(this->x - other.x)) < EPS &&  (fabs(this->y - other.y)) < EPS;
    }
};

//Ecuacion lineal: ax + by + c = 0
struct Line{
    double a,b,c;
};

void pointsToLine(Point& a, Point& b, Line& line){
    //Formula de la pendiente
    // m = (y2-y1)/(x2-x1)
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

bool areSame(Line& l1, Line& l2){//Check coefficients a&b&c
    return areParallel(l1,l2) && ( fabs(l1.c-l2.c) < EPS);
}

bool areIntersect(Line& l1, Line& l2, Point& p){
    if( areParallel(l1,l2)) return false;

    //Solve the system of 2 linear algebraic equations with 2 unknows
    p.x = ( l2.b * l1.c - l1.b * l2.c ) / ( l2.a * l1.b - l1.a * l2.b );
    if( fabs(l1.b) > EPS ) p.y = -( l1.a * p.x + l1.c );
    else                   p.y = -( l2.a * p.x + l2.c );

    return true;
}

ostream& operator<<(ostream& out, const Point& A){
    out<<"{"<<A.x<<","<<A.y<<"}";
    return out;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    Point X1(3.0, 7.0);
    Point Y1(6.0, 12.0);

    Point X2(11.0, 4.0);
    Point Y2(12.0, 1.0);

    Line A,B;
    pointsToLine(X1,Y1,A);
    pointsToLine(X2,Y2,B);
    cout<<"Linea A: "<<A.a<<","<<A.b<<","<<A.c<<"\n";
    cout<<"Linea B: "<<B.a<<","<<B.b<<","<<B.c<<"\n";
    Point ans(0.0,0.0); 
    if(areIntersect(A,B,ans)){
        cout<<"Punto de interseccion: "<<ans<<"\n";
    }else
        cout<<"No intersectan"<<"\n";
    
    return 0;
}