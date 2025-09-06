//https://codeforces.com/gym/102644/problem/B
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
const int MOD = 1e9 + 7;
using namespace std;

const int sz = 2;

struct Mat
{
    int m[sz][sz];
    Mat()
    {
        memset(m, 0.0, sizeof(m));
    }

    void identity()
    {
        for (int i = 0; i < sz; i++)
            m[i][i] = 1.0;
    }

    Mat operator*(Mat A)
    {
        Mat res;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++)
                    res.m[i][j] = (res.m[i][j] + ((m[i][k] * A.m[k][j]) % MOD)) % MOD;
        return res;
    }
};

void solve(int n)
{
    Mat A;
    A.m[0][0] = 19;
    A.m[0][1] = 6;
    A.m[1][0] = 7;
    A.m[1][1] = 20;
    Mat R;
    R.identity();

    while (n)
    {
        if (n & 1)
            R = R * A;

        A = A * A;
        n >>= 1;
    }
    int res = R.m[0][0];
    cout << res << "\n";
    // cout << fixed << setprecision(10) << res << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}