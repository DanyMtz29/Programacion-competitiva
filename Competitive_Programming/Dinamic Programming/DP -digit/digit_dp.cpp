#include <bits/stdc++.h>

#define int unsigned long long
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e4;

string k;
int d, apaar = 1e9 + 7;
int memo[22][2][10];

int dp(int i, bool last, int la)
{
    if (i == k.size())
    {
        // cout << "Num: " << num << endl;
        return 1;
    }

    int &ans = memo[i][last][la];
    if (ans != -1)
        return ans;

    ans = 0;

    int till = last ? (k[i] - '0') : 9;

    for (int digits = 0; digits <= till; digits++)
    {
        if (la == 1 && digits == 3)
            continue;
        if (digits == 4)
            continue;
        ans += dp(i + 1, last && (digits == till), digits);
    }

    return ans;
}

int solve(int x)
{
    k = to_string(x);
    memset(memo, -1, sizeof(memo));
    int res = dp(0, 1, 0) - 1;
    return res;
}

int binary(int target)
{
    int li = 1, ls = numeric_limits<int>::max();
    int ans = 0;
    while (li <= ls)
    {
        int middle = li + ((ls - li) >> 1);
        if (solve(middle) >= target)
        {
            // cout << "Ans: " << ans << endl;
            ans = middle;
            ls = middle - 1;
        }
        else
        {
            li = middle + 1;
        }
    }
    return ans;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    while (cin >> d)
    {
        cout << binary(d) << endl;
    }

    return 0;
}