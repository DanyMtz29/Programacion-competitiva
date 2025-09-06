#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< vector< pair<int, int> > >
using namespace std;



int32_t main(){
    
    int ingredients, plates, orders;
    cin>>ingredients>>plates>>orders;

    vec ingre( ingredients+1 );
    vecP plat( plates+1 );

    for( int i = 1; i <= ingredients ; i++ ){
        cin>>ingre[i];
    }

    for( int i = 1; i <= plates; i++ ){
        int totalIngredient, ingredient, quantity;
        cin>>totalIngredient;
        for( int j = 0; j < totalIngredient; j++ ){
            cin>>ingredient>>quantity;
            plat[ i ].push_back( {ingredient, quantity} );
        }
    }

    bool flag = true;

    int cont = 0;

    for( int i = 0; i < orders; i++ ){
        int totalPlates, plate;
        cin>>totalPlates;
        for( int j = 0; j < totalPlates; j++ ){
            cin>>plate;
            if(!flag) continue;
            
            vector< pair< int, int> >& plateM = plat[ plate ];
            for( int k = 0; k < plateM.size(); k++ ){
                ingre[ plateM[ k ].first ] -= plateM[ k ].second;
                if( ingre[ plateM[ k ].first ] < 0 ){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cont++;
    }


    cout<<cont<<endl;

    return 0;
}