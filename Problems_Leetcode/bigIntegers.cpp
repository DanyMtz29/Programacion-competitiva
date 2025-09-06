#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void multiply(vector<int>& arr, int no, int& size){
    int carry = 0;
    for(int i=0;i<size;i++){
        int pr = arr[i]*no + carry;
        arr[i] = pr%10;
        carry = pr/10;
    }
    while(carry){
        arr[size] = carry%10;
        carry/=10;
        size++;
    }
}

void pwr(vector<int>& arr, int size, int a,int b){
    while(b){
        if(b&1) multiply(arr,a,size);
        a*=a;
        b>>=1;
    }
}

int main(){
    //int a =65;
    //int b = 128;
    vector<int> a(1000);
    int size = 1;
    vector<int> b(1000);
    int size = 1;

    
    
    
    //multiply(a,a,size);
    for(int i=size-1;i>=0;i--){
        //cout<<arr[i];
    }
    cout<<endl;

    return 0;
}