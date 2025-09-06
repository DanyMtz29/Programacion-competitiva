#include<bits/stdc++.h>
using namespace std;

#define lli long long int

int a;
int cont;
bool flag;

void findMin(int n){
    if(n==1) return;
    int root = sqrt(n);
    while(n-(root*root)==0){
        a = root;
        n = root;
        root = sqrt(n);
        cont++;
    }
    lli minimum = INT_MAX;
    for(lli i=2;i<=root;i++){
        if(n%i==0){
            lli pw = n/i;
            lli res = pw*pw;
            if(res%n==0 && pw<minimum){
                minimum = pw;
                flag = true;
                a = pw;
                //cout<<"pw: "<<pw<<endl;
                //cout<<"Res: "<<res<<endl;
            }
        }
    }
    if(minimum!=INT_MAX){
        cont++;
        findMin(minimum);
    }
}


int main(){
    int n;
    cin>>n;
    //while(cin>>n){
    a = n;
    cont = 0;
    flag = false;
    findMin(n);
    cont = (flag)?cont+1:cont;  
    cout<<a<<" "<<cont<<endl;
    //}
    return 0;
}