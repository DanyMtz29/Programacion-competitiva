#include <bits/stdc++.h>
using namespace std;

const int MAX = 481;

int32_t main(){
    int n,m; cin>>n>>m;
    int axis[MAX];
    int axis2[MAX];
    axis[MAX] = INT_MAX;
    for( int i = 0 ; i <= MAX-1 ; i++ ){
        axis[i] = 0;
        axis2[i] = 0;
    }
    for( int i = 0 ; i < n ; i++ ){
        int s,d;
        cin>>s>>d;
        int lim = s+d;
        while( s<=lim ){
            if( s%m <= MAX-1 ) {
                axis[s%m]++;
                if( s<=MAX-1) {
                    axis2[s]--;
                }
            }
            s++;
        }
    }
    int mn = INT_MAX;
    int activities = INT_MAX;

    for( int i = 0 ; i <= MAX-1 && i<m ; i++ ){
        int curActivites = axis[i];
        if( curActivites < activities ){
            activities = curActivites;
            mn = i;
        }else if( curActivites == activities ){
            mn = min(mn,i);
        }
        if( axis2[i] < 0 ){
            curActivites+=axis2[i];
        }
        for( int j = i+m; j<= MAX-1 ; j+=m ){
            if( axis[j] > 0 ){
                curActivites += axis[j];
            }
            if( curActivites < activities ){
                activities = curActivites;
                mn = j;
            }else if( curActivites == activities ){
                mn = min(mn,j);
            }
            if( axis2[j]<0 ){
                curActivites += axis2[j];
            }
        }
    }
    cout<<mn<<" "<<activities<<"\n";
    return 0;
}