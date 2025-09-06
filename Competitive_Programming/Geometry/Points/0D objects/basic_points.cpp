#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1);

//struct point_i{ int x,y; };
struct point_i{
    int x,y;
    point_i(){x = y = 0;};
    point_i(int _x, int _y) : x(_x), y(_y) {}
};

struct point_d{
    double x,y;
    point_d(){x = y = 0.0;};
    point_d(double _x, double _y) : x(_x), y(_y) {}

    bool operator<(point_d& other) const {
        //Differents x's
        if (fabs(this->x - other.x) > EPS) return this->x < other.x;
        if (fabs(this->y - other.y) > EPS) return this->y < other.y;
        return false; // considered equal within EPS
    }

    bool operator==(point_d& other) const{
        return (fabs(this->x - other.x)) < EPS &&  (fabs(this->y - other.y)) < EPS;
    }

    double hypo(double dx, double dy){
        return sqrt(dx*dx + dy*dy);
    }

    double distance(const point_d& other){
        double dx = other.x-this->x;
        double dy = other.y-this->y;
        return hypo(dx,dy);
    }

    void rotate(double teta){
        //Rotacion de matrices
        /*
            |x| = cos(teta)*x - sin(teta)*y
            |y| = sin(teta)*x + cos(teta)*y
        */
        double rad = teta * (PI/180.0);
        double x_ = (cos(rad) * this->x) - (sin(rad)*this->y);
        double y_ = (sin(rad) * this->x) + (cos(rad)*this->y);
        this->x = x_;
        this->y = y_;
    }
};

ostream& operator<<(ostream& out, const point_d& A){
    out<<"{"<<A.x<<","<<A.y<<"}";
    return out;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(20);

    point_d A(0.1, 0.4);
    point_d B(0.3, 0.4);

    //A.x = A.x * 3; // 0.1 * 3 ≈ 0.30000000000000004

    //cout << "Valor de Ax: " << A.x << "\n";
    //cout << "Valor de Bx: " << B.x << "\n";

    //if (A == B) cout << "Son iguales\n";
    //else        cout << "Son diferentes\n";

    cout << fixed << setprecision(10);
    point_d C(0.31, 0.3);
    point_d D(0.1,  0.7);
    point_d E(0.5,  0.3);
    point_d F(0.5,  0.35);

    vector<point_d> points = {A, B, C, D, E, F};

    //cout << "Puntos sin ordenar\n";
    for (size_t i = 0; i < points.size(); ++i) {
        //cout << "Punto " << (i+1) << ": {" << points[i].x << "," << points[i].y << "}\n";
    }

    sort(points.begin(), points.end());

    //cout << "\nPuntos ordenados\n";
    for (size_t i = 0; i < points.size(); ++i) {
        //cout << "Punto " << (i+1) << ": {" << points[i].x << "," << points[i].y << "}\n";
    }
    //cout << "Distancia entre A y F: "<<A.distance(F)<<"\n";

    point_d test(10.0,3.0);
    //cout<<"Punto sin rotar: "<<test<<"\n";
    test.rotate(90.0);
    //cout<<"Punto rotado 90 grados: "<<test<<"\n";

    return 0;
}