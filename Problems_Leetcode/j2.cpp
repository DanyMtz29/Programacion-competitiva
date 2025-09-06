#include <bits/stdc++.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int thetaDeg, N;
    cin >> thetaDeg >> N;

    // 1) Convertir ángulo a radianes y preparar el factor 1/tan(θ).
    double theta = thetaDeg * M_PI / 180.0;
    double invTan = 1.0 / tan(theta);

    // 2) Array para alturas en cada X (hasta 300,000).
    static int heightAt[300001]; 
    memset(heightAt, 0, sizeof(heightAt));

    // 3) Leemos datos y guardamos alturas:
    for(int i=0; i<N; i++){
        int X, H;
        cin >> X >> H;
        heightAt[X] = H;
    }

    // 4) Construimos intervalos en orden (ya “ordenados” por X).
    vector<pair<double,double>> intervals; 
    intervals.reserve(N);
    for(int x=0; x<=300000; x++){
        if(heightAt[x] != 0){
            double left = (double)x;
            double right = x + heightAt[x] * invTan; 
            intervals.push_back({left, right});
        }
    }
    // intervals.size() == N

    // 5) Barrido lineal para unir intervalos.
    double totalCoverage = 0.0;

    double L = intervals[0].first;
    double R = intervals[0].second;

    for(int i=1; i<(int)intervals.size(); i++){
        double l_i = intervals[i].first;
        double r_i = intervals[i].second;
        if(l_i > R){
            // No hay solapamiento
            totalCoverage += (R - L);
            L = l_i;
            R = r_i;
        } else {
            // Hay solapamiento, extender R si hace falta
            R = max(R, r_i);
        }
    }
    // Sumar el último tramo
    totalCoverage += (R - L);

    // 6) Imprimimos el resultado (con suficiente precisión):
    cout << fixed << setprecision(6) << totalCoverage << "\n";
    return 0;
}
