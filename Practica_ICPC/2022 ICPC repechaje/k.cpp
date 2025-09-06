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

int getKey(char c)
{
    if (c <= 'c')
        return 2;
    else if (c <= 'f')
        return 3;
    else if (c <= 'i')
        return 4;
    else if (c <= 'l')
        return 5;
    else if (c <= 'o')
        return 6;
    else if (c <= 's')
        return 7;
    else if (c <= 'v')
        return 8;
    else
        return 9;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, Q;
        cin >> n >> Q;
        string s;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            int number = 0;
            for (int i = 0; i < s.length(); i++)
            {
                number = (number * 10);
                number += getKey(s[i]);
            }
            mp[number]++;
        }

        while (Q--)
        {
            int q;
            cin >> q;
            cout << mp[q] << "\n";
        }
    }
    return 0;
}