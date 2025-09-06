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
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    int k;
    cin >> k;
    int sz = s.length();
    unordered_map<int, priority_queue<char, vector<char>, greater<char>>> mp;
    mp[0].push(s[0]);
    for (int i = 1; i < sz; i++)
    {
        mp[i % k].push(s[i]);
    }

    s[0] = mp[0].top();
    mp[0].pop();
    int i = 1;
    while (i < sz)
    {
        s[i] = mp[i % k].top();
        mp[i++ % k].pop();
    }
    cout << s << endl;

    return 0;
}