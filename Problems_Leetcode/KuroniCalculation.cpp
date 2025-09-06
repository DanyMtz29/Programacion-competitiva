#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve(lli mod, vector<lli> nums, int n){
    vector<int> v(mod,0);
    for(int i=0;i<n;i++){
        int rest = nums[i]%mod;
        if(v[rest]==2) {
            cout<<"0"<<endl;
            return;
        }else{
            v[rest]++;
        }
    }
    
    lli sum = 1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum *= abs(nums[i]-nums[j])%mod;
            sum %=mod;
        }
    }
    cout<<sum<<endl;
}

int main(){
    int N, mod;
    cin>>N>>mod;
    vector<lli> nums(N);
    for(int i=0;i<N;i++) cin>>nums[i];
    solve(mod,nums,N);
    return 0;
}