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
    int n;
    cin >> n;
    map<int, int> firstPos;
    firstPos[0] = -1;

    int mask = 0;
    int maxLen = 0;

    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        int bit = c - 'a';

        mask ^= (1 << bit);

        if (firstPos.count(mask))
            maxLen = max(maxLen, i - firstPos[mask]);
        else
            firstPos[mask] = i;

        for (int j = 0; j < 26; ++j)
        {
            int testMask = mask ^ (1 << j);

            if (firstPos.count(testMask))
                maxLen = max(maxLen, i - firstPos[testMask]);
        }
    }
    cout << maxLen << endl;
    return 0;
}