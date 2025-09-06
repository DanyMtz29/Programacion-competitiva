#include <bits/stdc++.h>

using namespace std;

vector<int> divisors(int n){
    int root = sqrt(n);
    int a = 0;
    int b = 0;
    int mn = INT_MIN;
    for(int i=1;i<=root;i++){
        if(n%i==0){
            if(abs(i-n/i)<mn){
                a = i;
                b = n/i;
                mn = abs(a-b);
            }
        }
    }
    return vector<int>{a,b};
}

vector<int> solve(int n){
    vector<int>  a = divisors(n+1);
    vector<int>  b = divisors(n+2);
    return (abs(a[1]-a[0])<abs(b[1]-b[0]))?a:b;
}

int main(){
    int n = 999;
    return 0;
}