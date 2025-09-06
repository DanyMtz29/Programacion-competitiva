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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n, k, cnt = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                cnt++;
        }

        if (k >= cnt)
        {
            cout << "Alice" << "\n";
            continue;
        }

        if ((int)(n / k) >= 2)
            cout << "Bob" << "\n";
        else
            cout << "Alice" << "\n";
    }
    return 0;
}
/*
    10110110
    00000110
    11100110
    00100010
    00111110
    00010100
    11110100
    01010000
    01011110
    00000110
    11100110
    01000010


    111111
    010100
    011111
    001000
    111100
    000000

    1011011
    1000000
    1001111
    0000010
    1111010
    0001000

    1111111
    0101010
    1111010
    0100000
    0111110
    0001000

    11111111
    01010111
    11110111
    01010011
    01011111
    01010010
    11110010
    01010000
    01011110
    01001000

    111111
    010101
    111101
    010100
    010111
    000100
    111100
    010000
    011110
    000100
    111

    111111

*/