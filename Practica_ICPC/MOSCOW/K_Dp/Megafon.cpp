#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);

    int N;
    cin>>N;

    vector<int> arr(N);

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    lli mx = 0;
    lli cont = 0;

    // 5 -3 -2 1

    for(int i=1;i<N;i++){
        mx = max( arr[i], arr[i-1] );
        if( mx > 0){
            cont += mx;
        }
    }

    cout<<cont<<endl;

    return 0;
}