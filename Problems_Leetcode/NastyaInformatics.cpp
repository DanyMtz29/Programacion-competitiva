#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

//gcd(a,b) = x
//lcm(a,b) = y

int solve(lli l, lli r, lli x, lli y){
    lli mul = x*y;
    vector<pair<lli,lli>> vec;

    lli root = sqrt(mul);

    if(mul-(root*root)==0) root--;
    
    int cont=0;

    for(lli i=l;i<=root;i++){
        if(mul%i==0){
            lli b = mul/i;
            if(i<=r && b<=r){
                lli g = gcd(i,b);
                if(g==x){
                    if( ((i*b)/g) == y){
                        cont+=2;
                    }
                }
            }
        }
    }

    return cont;
}

int solve2(lli l, lli r, lli x, lli y){
    lli mul = x*y;
    int cont = 0;
    lli i=1;
    for( ; i*i <= mul ; i++){
        if( mul % i == 0 ){
            lli D = mul/i;
            if( i != D ){
                if(i >= l && i <= r && D >= l && D<= r){
                    lli G = gcd( i, D );
                    if( G == x && (( i * D ) / G) == y){
                        cont+=2;
                    }
                }
            }
        }
    }
    return cont;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli l,r,x,y;
    while(cin>>l>>r>>x>>y){
    //cin>>l>>r>>x>>y;
    cout<<solve2(l,r,x,y)<<endl;
    }
    
    return 0;
}