//https://codeforces.com/problemset/problem/888/E
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

vi fillArray(vi &a, int m)
{
    vi res;
    int n = (int)a.size();
    for (int i = 0; i < (1 << n); i++){
        int sum = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1){
                sum += a[j];
                sum %= m;
            }
        res.pb(sum);
    }
    return res;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--){
        int n, m;
        cin >> n >> m;
        vi lefts, rights;
        int s = 0;
        for (int i = 0; i < n; i++){
            int e;
            cin >> e;
            if (i < n / 2)
                lefts.pb(e);
            else
                rights.pb(e);
            s += e;
        }
        vi lefts_sums = fillArray(lefts, m);
        vi rights_sums = fillArray(rights, m);

        eraseU(lefts_sums);
        eraseU(rights_sums);

        sort(all(rights_sums));

        int ans = 0;
        for (auto x : lefts_sums){
            int find = lower_bound(all(rights_sums), m - 1 - x) - rights_sums.begin();
            if (find < rights_sums.size() && find >= 0){
                if (find - 1 >= 0)
                    ans = max((x + rights_sums[find - 1]) % m, ans);
                ans = max((x + rights_sums[find]) % m, ans);
            }
            else{
                if (find + 1 == 0)
                    ans = max((x + rights_sums[0]) % m, ans);
                else
                    ans = max((x + rights_sums[find - 1]) % m, ans);
            }

            if (ans == m - 1)
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}