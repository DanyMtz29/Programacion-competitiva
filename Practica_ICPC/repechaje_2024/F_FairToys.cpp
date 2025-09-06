#include <bits/stdc++.h>
#define vec vector<int>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vec alice(5);
    vec bob(4);

    for( int i = 0; i < 5; i++ ){
        cin>>alice[i];
    }
    for( int i = 0; i < 4; i++ ){
        cin>>bob[i];
    }

    bool found = false;

    for( int i = 0; i < 5; i++ ){
        for( int j = 0; j < 4; j++ ){
            if( alice[i] == bob[j] ){
                found = true;
                break;
            }
        }
        if(!found){
            cout<<alice[i]<<endl;
            break;
        }
        found = false;
    }

    return 0;
}