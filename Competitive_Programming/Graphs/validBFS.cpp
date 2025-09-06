#include <bits/stdc++.h>
#define int long long int
using namespace std;

bool solve(int n, unordered_map<int, unordered_set<int>> &mp, vector<int> &arr)
{
    if (arr[0] != 1)
        return false;

    vector<bool> visited(n + 1, false);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    int index = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        while (mp[curr].size() > 0 && !visited[arr[index]])
        {
            if (!mp[curr].count(arr[index]))
                return false;

            q.push(arr[index]);
            mp[curr].erase(arr[index]);
            mp[arr[index]].erase(curr);
            visited[arr[index]] = true;
            index++;
        }
    }

    return index == n;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    unordered_map<int, unordered_set<int>> mp;

    for (int i = 0; i < n - 1; i++)
    {
        int src, dest;
        cin >> src >> dest;
        mp[src].insert(dest);
        mp[dest].insert(src);
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << (solve(n, mp, arr) ? "Yes" : "No") << endl;

    return 0;
}