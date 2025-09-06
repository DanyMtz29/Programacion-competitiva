#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

vector<string> solve(vector<vector<string>> &tickets)
{
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    for (vector<string> &tik : tickets)
    {
        mp[tik[0]].push(tik[1]);
    }

    vector<string> ans;
    stack<string> st;
    st.push("JFK");
    while (st.size() > 0)
    {
        string current = st.top();
        st.pop();

        if (mp.count(current) && mp[current].empty())
        {
            st.push(mp[current].top());
            mp[current].pop();
        }
        else
        {
            ans.push_back(current);
            st.pop();
        }
    }
    return ans;
}

int32_t main()
{

    return 0;
}