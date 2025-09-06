//https://leetcode.com/problems/palindrome-partitioning-ii/description/
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int solve(string &s){
    int n = s.length();

    vector<vector<bool>> dp(n, vector<bool>(n, true));

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    

    for (int i = 1; i < n; i++){
        for (int j = 0; j + i < n; j++){
            if (i - 1 > 0){
                if (s[j] == s[j + i]){
                    if (dp[j + 1][j + i - 1])
                        dp[j][j + i] = 1;
                    else
                        dp[j][j + i] = 0;
                }
                else
                    dp[j][j + i] = 0;
            }
            else
                dp[j][j + i] = s[j] == s[j + i] ? 1 : 0;
            
        }
    }

    vector<int> minCuts(n, INT_MAX);

    for (int i = 0; i < n; i++){
        if (dp[0][i] == 1)
            minCuts[i] = 0;
        else{
            for (int j = 0; j < i; j++)
                if (dp[j + 1][i] == 1)
                    minCuts[i] = min(minCuts[i], minCuts[j] + 1);
        }
    }

    cout << "Matrix" << endl;
    for (vector<bool> &v : dp){
        copy(v.begin(), v.end(), ostream_iterator<bool>(cout, "|"));
        cout << "" << endl;
    }
    cout << "" << endl;

    cout << "COUNTMINS" << endl;
    copy(minCuts.begin(), minCuts.end(), ostream_iterator<int>(cout, "|"));
    cout << "" << endl;

    cout << "Valor minimo: " << minCuts[n - 1] << endl;

    return 0;
}

int32_t main(){
    // string s = "acddcadd";
    // string s = "cabababcbc";
    string s = "ccaacabacb";
    solve(s);
    return 0;
}