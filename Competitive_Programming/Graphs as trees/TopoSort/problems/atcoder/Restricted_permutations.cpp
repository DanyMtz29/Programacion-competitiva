//https://atcoder.jp/contests/abc223/tasks/abc223_d
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

const int N = 2e5 + 1;
vvi graph(N);
vi topoOrder;
vi edges(N);

int32_t main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        edges[y]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++)
        if (edges[i] == 0)
            pq.push(i);

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        topoOrder.push_back(cur);
        for (int nbr : graph[cur])
            if (--edges[nbr] == 0)
                pq.push(nbr);
    }

    if (topoOrder.size() != n)
        cout << "-1" << endl;
    else
        for (auto x : topoOrder)
            cout << x << " ";

    return 0;
}