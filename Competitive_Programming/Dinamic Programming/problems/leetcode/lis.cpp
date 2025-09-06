#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int lis(vec &arr){
    int n = arr.size();
    vec dp(n, 1);

    int len = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= i; j++){
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
                len = max(len, dp[i]);
            }
        }
    }
    return len;
}

int32_t main(){
    // vec arr = {50, 4, 10, 8, 30, 100};
    // vec arr = {10, 9, 2, 5, 3, 7, 101, 18};
    // vec arr = {0, 1, 0, 3, 2, 3};
    vec arr = {7, 7, 7, 7, 7, 7, 7};
    cout << lis(arr) << endl;
    return 0;
}