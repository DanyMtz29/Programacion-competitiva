//https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

const int MOD = 1e9 + 7;

int dfs(vector<vector<int>> &hats, vector<vector<int>> &dp, int mask, int n, int hat){
    if (hat >= 41 && mask == 0)    
        return 1;

    if (hat >= 41 && mask != 0)
        return 0;

    if (dp[hat][mask] != -1)
        return dp[hat][mask];

    int total = 0;

    total = (total + dfs(hats, dp, mask, n, hat + 1)) % MOD;

    if (hats[hat].size()){
        int sz = hats[hat].size();
        for (int j = 0; j < sz; j++){
            if ((mask & (1 << hats[hat][j])) == 0)
                continue;

            total = (total + dfs(hats, dp, mask & (~(1 << hats[hat][j])), n, hat + 1)) % MOD;
        }
    }
    return dp[hat][mask] = total;
}

int solve(vector<vector<int>> &hats){
    int n = hats.size();
    vector<vector<int>> hts(41, vector<int>());
    for (int j = 0; j < n; j++){
        int sz = hats[j].size();
        for (int i = 0; i < sz; i++){
            hts[hats[j][i]].push_back(j);
        }
    }

    vector<vector<int>> dp(41, vector<int>((1 << n), -1));
    return dfs(hts, dp, (1 << n) - 1, n, 1);
}

int32_t main(){
    vector<vector<int>> hats = {{3, 5, 1}, {3, 5}};
    cout << "Solve: " << solve(hats) << endl;
    return 0;
}