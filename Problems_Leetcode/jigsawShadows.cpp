#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

const int N = 300005;

int main(){
    int flantenders;
    double angle;
    cin>>angle>>flantenders;
    vector<double> people(N,0);
    vector<double> vec(2,0);
    double x;
    int h;
    double tanAngle = tan((angle*(M_PI/180)));
    for(int i=0;i<flantenders;i++){
        cin>>x>>h;
        double dx = h/tanAngle;
        people[x] = x+dx;
    }

    double sum = 0;
    for(int i=0;i<=N;i++){
        if(people[i]!=0){
            if(i>vec[1]){
                sum += vec[1]-vec[0];
                vec[0]=i;
                vec[1]=people[i];
            }else{
                if(people
                    [i]>=vec[i]){
                    vec[1] = people[i];
                }
            }
        }
    }
    //cout<<"Vec[0]: "<<vec[0]<<", vec[1]: "<<vec[1]<<endl;
    sum+=(vec[1]-vec[0]);
    cout<<fixed<<setprecision(10);
    cout<<sum<<endl;
    
    return 0;
}