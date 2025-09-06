//No me acuerdo de que plataforma es
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
#define all(x) x.begin(), x.end()

const int MAX = 2 * 1e5;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vi arr(MAX, 0);
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mn = min(mn, x);
            arr[x]++;
        }

        vi ts;
        int prev = 0;

        for (int i = MAX; i > mn; i--)
        {
            prev += arr[i];
            if (prev > 0)
            {
                ts.push_back(prev);
            }
        }
        int sz = ts.size();
        int cont = 0;
        int slices = 0;
        for (int i = 0; i < sz; i++)
        {
            if (cont + ts[i] > k)
            {
                cont = ts[i];
                slices++;
            }
            else
            {
                cont += ts[i];
            }
        }

        if (sz == 0)
            cout << "0" << "\n";
        else
            cout << slices + 1 << "\n";
    }

    return 0;
}