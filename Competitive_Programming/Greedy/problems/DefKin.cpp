//https://www.spoj.com/problems/DEFKIN/
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
const int MOD = 1e9 + 7;
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int w, h, t;
        cin >> w >> h >> t;
        t += 2;
        vi x(t), y(t);
        x[t - 2] = 0, x[t - 1] = w + 1;
        y[t - 2] = 0, y[t - 1] = h + 1;

        for (int i = 0; i < t - 2; i++)
        {
            int a, b;
            cin >> a >> b;
            x[i] = a;
            y[i] = b;
        }

        sort(all(x));
        sort(all(y));

        int mnX = 0, mnY = 0;
        for (int i = 1; i < t; i++)
        {
            mnX = max(mnX, x[i] - x[i - 1] - 1);
            mnY = max(mnY, y[i] - y[i - 1] - 1);
        }
        cout << mnX * mnY << "\n";
    }
    return 0;
}