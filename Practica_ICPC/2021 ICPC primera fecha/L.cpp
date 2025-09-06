#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

string solve(int n)
{
    if (n == 1)
        return "2";

    if (n % 2 == 0)
        return "(" + solve(n / 2) + ")^2";
    else
        return "(2*" + solve(n - 1) + ")";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}