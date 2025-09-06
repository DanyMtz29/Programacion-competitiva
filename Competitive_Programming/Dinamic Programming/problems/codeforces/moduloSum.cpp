//https://codeforces.com/problemset/problem/577/B
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
#define forn(arr, n)            \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];

using namespace std;

bool solve(vec &arr, int n, int m){
    if (n >= m)
        return true;
    

    vector<vector<bool>> dp(n + 1, vector<bool>(m, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < m; j++){
            if (dp[i - 1][j]){
                dp[i][j] = true;
                int sum = arr[i - 1] + j;
                if (sum % m == 0){
                    return true;
                }
                sum = ((sum % m) + m) % m;
                dp[i][sum] = true;
            }
        }
    }
    return false;
}

int32_t main(){

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec arr(n);
    forn(arr, n);

    if (solve(arr, n, m)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}