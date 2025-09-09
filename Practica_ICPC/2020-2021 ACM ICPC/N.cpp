#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int convertir(string s){
    if( s[0] != '0' ) return (s[0]-'0')*10 + (s[1]-'0');
    return (s[1]-'0');
}

int32_t main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dec = 0;
    if( s.size()>5) dec += convertir(s.substr(4));
    else dec += convertir(s.substr(3));

    int movs = 0;
    for( int i = 0 ; i < n ; i++ ){
        cin>>s;
        if( s.size()>5) dec += convertir(s.substr(4));
        else dec += convertir(s.substr(3));
        dec%=100;
        if( dec == 0 ) continue;
        movs++;
    }
    cout<<movs<<"\n";
    return 0;
}