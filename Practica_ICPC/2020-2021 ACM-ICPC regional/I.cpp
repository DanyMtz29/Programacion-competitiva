#include <bits/stdc++.h>
using namespace std;
#define int long long int

unordered_map<string,int> mp;

int getDay(int day, int invest){
    int res = invest%7;
    cout<<"Mod: "<<res<<"\n";
    if( res >= day ){
        return 7-res+day;
    }else{
        return day-res;
    }
}

int getRenewedDay(int day, int time){
    int res = 0;
    if( day + 2 >= 6 ){
        res += 30+(8-(day+2));
        if( res >= time ) return res;
        day = 1;
    }else{
        day +=2;
        res+=30;
        if( res >= time ) return res;

        if( day + 2 >= 6 ){
            res += 30+(8-(day+2));
            if( res >= time ) return res;
            day = 1;
        }else{
            day = 1;
            res+=30;
            if( res>=time ) return res;
            res += 31;
            day = 1;
        }
    }
    if( res >= time ) return res;

    int tiempoRestante = time - res;
    
    int mul = tiempoRestante/91;
    res += (mul*91);
    if(res >= time) return res;

    if( res + 30 >= time) return res + 30;
    else return res + 60;
}

int32_t main(){

    mp["Mon"] = 1;
    mp["Tue"] = 2;
    mp["Wed"] = 3;
    mp["Thu"] = 4;
    mp["Fri"] = 5;
    mp["Sat"] = 6;
    mp["Sun"] = 7;

    string s;
    cin>>s;
    int n; cin>>n;

    int initialDay = mp[s];
    int mn = LONG_LONG_MAX;
    for (int i = 0; i < n; i++){
        int x;cin>>x;
        int invest = getDay(initialDay,x);
        cout<<"Day: "<<invest<<"\n";
        int ren = getRenewedDay(invest, x);
        //cout<<"Dia: "<<invest<<"\n";
        mn = min(mn, ren-x);
    }
    
    cout<<mn<<"\n";
    return 0;
}

/*

Sat 5
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
M M J V S D L M M J V  S  D  L  M  M  J  V  S  D  L  M  M  J  V  S  D  L  M  M  J  v

  1 1
S B

Lunes + 2 -> Miercoles
Miercoles + 2 -> Viernes
Viernes + 2 -> Lunes

Martes + 2 -> Jueves
Jueves + 2 -> Sabado

Miercoles + 2 -> Viernes
Viernes + 2 -> Lunes

1 2 3 4 5 6 7
L M M J V S D
        - .
            
*/