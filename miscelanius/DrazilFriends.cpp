/*
 problem: https://codeforces.com/problemset/problem/515/B
 Se resolvio iterativo, tal cual dice el problema, asi se hizo.
*/

#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int, int>
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define pb push_back
const int MOD = 1e9 + 7;
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--){
        int n, m;
        cin >> n >> m;
        vector<bool> boys(n, false);
        vector<bool> girls(m, false);
        int b;
        cin >> b;
        for (int i = 0; i < b; i++){
            int e;
            cin >> e;
            boys[e] = 1;
        }
        int g;
        cin >> g;
        for (int i = 0; i < g; i++){
            int e;
            cin >> e;
            girls[e] = 1;
        }

        int cntB = b;
        int cntG = g;
        for (int i = 0; i < 1e6 && (cntB < n || cntG < m); i++){
            bool curBoy = boys[i % n];
            bool curGirl = girls[i % m];
            if (curBoy || curGirl){
                if (!curBoy)
                    cntB++;
                if (!curGirl)
                    cntG++;
                boys[i % n] = 1;
                girls[i % m] = 1;
            }
        }
        if (cntB == n && cntG == m)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}