//https://codeforces.com/problemset/problem/982/C
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int cont;

int dfs(unordered_map<int, vector<int>> &mp, int curr, int parent)
{
    bool flag = false;
    int size = 1;
    for (int nbr : mp[curr])
    {
        if (nbr == parent)
            continue;

        int sizeNbr = dfs(mp, nbr, curr);
        if (sizeNbr & 1)
        {
            if (flag)
            {
                // cont--;
                flag = false;
            }
            else
            {
                // cont++;
                flag = true;
            }
            size += sizeNbr;
        }
        else
            cont++;
    }
    return size;
}

void solve(int n)
{
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n - 1; i++)
    {
        int src, dest;
        cin >> src >> dest;
        mp[src].push_back(dest);
        mp[dest].push_back(src);
    }
    if (n & 1)
    {
        cout << "-1" << endl;
        return;
    }
    dfs(mp, 1, 0);
    cout << cont << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cont = 0;
    solve(n);

    return 0;
}