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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vi arr(n);
        forN(n, arr);
        int l = 0, r = n - 1;

        int moves = 0;
        int alice = 0;
        int bob = 0;
        bool flag = true;
        int target = arr[0] - 1;
        while (l <= r)
        {
            moves++;
            if (flag)
            {
                int aux = 0;
                while (l <= r && aux <= target)
                    aux += arr[l++];
                alice += aux;
                target = aux;
                flag = !flag;
            }
            else
            {
                int aux = 0;
                while (l <= r && aux <= target)
                    aux += arr[r--];
                bob += aux;
                target = aux;
                flag = !flag;
            }
        }
        cout << moves << " " << alice << " " << bob << "\n";
    }
    return 0;
}