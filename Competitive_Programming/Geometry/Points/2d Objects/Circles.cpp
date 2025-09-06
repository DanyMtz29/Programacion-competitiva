/*
-Si el circulo tiene centro (h,k) y radio r, la ecuacion es:
    (x-h)^2 + (y-k)^2 = r^2
 Proviene de la distancia entre dos puntos
    distancia^2 = (x-h)^2 + (y-k)^2
-Un circulo con radio r tiene un diametro d = 2*r y una circunferencia (perimetro)
de c = 2*PI*r

Un circulo tiene un area de A = PI * r^2

Un arco de un circulo es definido como una seccion de conexion de la circunferencia C del circulo.
Dado el angulo central (con un vertice con el centro del circulo) en grados, se puede calcular
el arco como "teta/360.0 x c".

La cuerda de un circulo, con un angulo r y un angulo central teta en grados, se puede calcular su
longitud con sqrt( 2 * r^2 * ( 1-cos(teta) ) ). Esto se deriva de la ley de cosenos.



*/
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point{
    double x,y;
    Point(){x = y = 0.0;};
    Point(double _x, double _y) : x(_x), y(_y) {}

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
};

ostream& operator<<(ostream& out, const Point& A){
    out<<"{"<<A.x<<","<<A.y<<"}";
    return out;
}

bool insideCircle(Point& A, Point& B, double r){
    double dx = A.x - B.x, dy = A.y - B.y;
    double Euc = dx*dx + dy*dy,rSq = r*r ;
    return Euc < rSq+EPS? 0: Euc-rSq<EPS?1:2;//inside, border/outside
}

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    

    return 0;
}