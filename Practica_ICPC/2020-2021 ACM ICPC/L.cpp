#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;

int32_t main(){
    int n,m; cin>>n>>m;
    int axis[MAX];
    for( int i = 0 ; i <= MAX ; i++ ){
        axis[i] = 0;
    }

    for( int i = 0 ; i < n ; i++ ){
        int s,d;
        cin>>s>>d;
        for( int j = s+d ;j>= 0 && j >= s && j > s+d-m ;j--){
            int min = j;
            if( j>=480 ){
                int res = j%m;
                int div = 480/res;
                min = div * res;
            }
        }
    }
    return 0;
}

/*
5 30
195 30
120 45
240 30
30 60
300 180

451 1

0:30 - 1:30
2:00 - 2:45
3:15 - 3:45
4:00 - 4:30
5:00 - 8:00

7:31


0 - 30 - 60 - 90 - 120 - 150 - 180 - 210 - 240 - 270 - 300 - 330 - 360 - 390 - 420 - 450 - 480
    ACT1       ACT1
                   ACT2    ACT2
                                ACT3    ACT3
                                           ACT4  ACT4
                                                       ACT5                                ACT5


*/