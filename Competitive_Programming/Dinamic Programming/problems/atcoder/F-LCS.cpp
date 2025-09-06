//https://atcoder.jp/contests/dp/tasks/dp_f
#include <bits/stdc++.h>
#define int long long int
using namespace std;

string solve(string &s, string &t)
{
    int ss = s.length();
    int tt = t.length();
    vector<vector<int>> dp(ss + 1, vector<int>(tt + 1, 0));
    for (int i = 1; i <= ss; i++)
    {
        for (int j = 1; j <= tt; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    if (dp[ss][tt] == 0)
        return "";

    string ans = "";
    int i = ss;
    int j = tt;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j] && (dp[i - 1][j] == dp[i][j - 1]))
        {
            ans += t[j - 1];
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
    return 0;
}