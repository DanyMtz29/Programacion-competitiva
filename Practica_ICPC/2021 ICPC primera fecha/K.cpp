#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        vector<bool> ans(7);
        int sz = s.length();
        if (sz < 2)
        {
            if ((s[0] - '0') % 2 == 0)
                ans[2] = 1;
            if ((s[0] - '0') % 3 == 0)
                ans[3] = 1;
            if ((s[0] - '0') % 4 == 0)
                ans[4] = 1;
            if ((s[0] - '0') % 5 == 0)
                ans[5] = 1;
            if ((s[0] - '0') % 6 == 0)
                ans[6] = 1;
        }
        else
        {
            if ((s[sz - 1] - '0') % 2 == 0)
                ans[2] = 1;

            int count = 0;
            for (int i = 0; i < sz; i++)
                count += (s[i] - '0');

            if (count % 3 == 0)
                ans[3] = 1;

            if ((((s[sz - 2] - '0') * 10) + (s[sz - 1] - '0')) % 4 == 0)
                ans[4] = 1;

            if (s[sz - 1] == '5' || s[sz - 1] == '0')
                ans[5] = 1;
            if (ans[3] && ans[2])
            {
                ans[6] = 1;
            }
        }

        bool flag = false;
        vector<int> answer;
        for (int i = 2; i <= 6; i++)
        {
            if (ans[i])
            {
                answer.push_back(i);
                flag = true;
            }
        }
        if (!flag)
            cout << "-1" << endl;
        else
        {
            int sz = answer.size();
            int i = 0;
            for (; i < sz - 1; i++)
            {
                cout << answer[i] << " ";
            }
            cout << answer[i] << endl;
        }
    }
    return 0;
}