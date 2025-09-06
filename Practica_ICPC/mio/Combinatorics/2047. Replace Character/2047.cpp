#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
using namespace std;

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        int sz;
        cin >> sz;
        string s;
        cin >> s;
        map<char, int> mp;
        for (char c : s)
        {
            mp[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto &p : mp)
        {
            pq.push({p.second, p.first});
        }
        char mx = pq.top().second;

        while (pq.size() > 1)
            pq.pop();

        char mn = pq.top().second;
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == mn)
            {
                s[i] = mx;
                break;
            }
        }

        cout << s << endl;
    }

    return 0;
}