#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

void pascalTriangle(vector<vector<int>> &pascal, int n, int r){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= min(i, r); j++){
            // Case base
            if (j == 0 || j == i){
                pascal[i][j] = 1;
            }else{
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }
}

int32_t main(){
    int N = 10;
    vector<vector<int>> pascal(N + 1, vector<int>(N + 1));
    int row, col;
    pascalTriangle(pascal, N, N);
    for (vec &v : pascal){
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, "|"));
        cout << endl;
    }

    return 0;
}