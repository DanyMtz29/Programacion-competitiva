#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD = 1e9+7;

int inv(int a){
    int res = 1;
    int b = MOD-2;
    while(b){
        if(b&1) res*=a,res%=MOD;
        a*=a,a%=MOD;
        b>>=1;
    }
    return res;
}

int solve(int n, vector<int>& arr){
    vector<long long> ans(n);
    sort(arr.begin(), arr.end(), greater<int>());
    for( long long i = 2 ; i<n ; i++ ){
        cout<<"\nIteracion "<<i<<"\n";
        long long val = (i * (i+1) / 2 );
        cout<<"Val: "<<val<<"\n";
        val%=MOD;
        val = inv(val);
        ans[i] = (( 1 - val )*(ans[i-1]%MOD + MOD))%MOD;
        ans[i] = (ans[i] + (val*arr[i]%MOD))%MOD;
    }
}

int32_t main(){
    

    return 0;
}

/*
    Example 1
    arr = [1 2 3]

    the probability of 1 player:
        1*1/3
    the probability of 2 player:
        2*2/3
    Answer: 5/3
    2 1 1 3
    2 3 2 3

    Example 2
    arr = [1 2 3 4]
    the probability of 1 player:
            1*3/4
    en el juego de 1:
     juegan 2 y 4, juegan 3 y 4, y queda en segundo 1
     juegan 2 y 3, juegan 3 y 4, y queda en segundo 1
     juegan 3 y 4, juegan 2 y 4, y queda en segundo 1
    en el juego de 2:
     juegan 1 y 3, juegan 3 y 4, y queda en segundo 1.
    
    PAra [1 2 3] 
    1 = 1/3
    2 = 2/3
    R = 5/3

    Para [1 2 3 4]
    1 = 3/18 -> 1/6
    2 = 5/18 
    3 = 10/18 -> 5/9
    R = 43/18

    para [1 2 3 4 5]
    1 = 1/10
    2 = 3/20
    3 = 1/4
    4 = 1/2 
    R = 180/180
*/