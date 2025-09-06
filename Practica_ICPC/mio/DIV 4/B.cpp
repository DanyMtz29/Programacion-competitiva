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

void check(int n, int k, int sub)
{
    cout << "YES" << "\n";
    while (k > 1)
    {
        cout << sub << " ";
        n -= sub;
        k--;
    }
    cout << n << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        if (n == k)
            check(n, k, 1);
        else if (n % 2 == 0)
        {
            if (n / 2 >= k)
                check(n, k, 2);
            else if (n - 3 >= k - 1 && k % 2 == 0)
                check(n, k, 1);
            else
                cout << "NO" << "\n";
        }
        else if (n - 3 >= k - 1 && k % 2 != 0)
            check(n, k, 1);
        else
            cout << "NO" << "\n";
        // else if (n - 3 >= k - 1 && (((k - 1) % 2 == 0 && ((n - (k - 1)) % 2) != 0) || (k - 1) == n - 3))
        //     check(n, k, 1);
        // else
        //     cout << "NO" << "\n";
    }
    return 0;
}