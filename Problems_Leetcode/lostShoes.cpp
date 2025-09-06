#include <iostream>
using namespace std;

int sol(int a[], bool v[], int n){
    int countA = 0;
    for(int i=0;i<n;i++){
        int j = i;
        int countB=0;
        while(!v[j]){
            countB++;
            v[j] = true;
            j = a[j]-1;
        }
        if(countB>1) countA += countB-1; 
    }
    return countA;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    while(cin>>n){
        int right[n];
        int left[n];
        bool visitRight[n];
        bool visitLeft[n];
        int i;
        for(i=0;i<n;i++){
            cin>>right[i];
            visitRight[i] = false;
        }
        for(i=0;i<n;i++){
            cin>>left[i];
            visitLeft[i] = false;
        }
        int cRight = sol(right,visitRight,n);
        int cLeft = sol(left,visitLeft,n);
        int totalChanges = cRight + cLeft;
        cout<<totalChanges<<endl;
    }
    return 0;    
}