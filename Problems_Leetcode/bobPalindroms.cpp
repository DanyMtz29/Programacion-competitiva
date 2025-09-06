#include<bits/stdc++.h>
#define lli long long int
using namespace std;

const int mod = 1e9+7;

lli pwr(lli a, lli b){
    lli res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

lli solve(int n){
    lli a = 1;
    lli b = 1;
    lli potencia = 1;
    for(int i = 2;i<=n;i++){
        if(i%2==0) {
            potencia = (potencia*26)%mod;
            b = potencia;
            a = (a*26 + 1)%mod;
        }
        else{
            a+=1;
        }
    }
    cout<<"a: "<<a<<endl; 
    cout<<"b: "<<b<<endl; 
    //a = 18929;
    //lli ans = (a*pwr(b,mod-2))%mod;
    lli ans = (a * pwr(b,mod-2))%mod;
    lli ans2 = (5 * pwr(3,mod-2))%mod;
    cout<<"ans: "<<ans2<<endl;
    return 0;
}

vector<string> letterCombinations(string digits) {
    
    unordered_map<char, vector<char>> numbers;
    numbers['2'] = {'a','b','c'};
    numbers['3'] = {'d','e','f'};
    numbers['4'] = {'g','h','i'};
    numbers['5'] = {'j','k','l'};
    numbers['6'] = {'m','n','o'};
    numbers['7'] = {'p','q','r','s'};
    numbers['8'] = {'t','u','v'};
    numbers['9'] = {'w','x','y', 'z'};
    
    vector<string> res;
    string current( digits.size() );
    addString(0, 0, digits, numbers, res, current);
    return res;
}

int main(){
    cout<<solve(2)<<"\n"<<endl;
    cout<<solve(4)<<endl;
    
    return 0;
}