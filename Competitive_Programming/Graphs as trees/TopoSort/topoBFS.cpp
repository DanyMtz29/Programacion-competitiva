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

int32_t main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        edges[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (edges[i] == 0) // If it hasn't edges before it
            q.push(i);

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        topoOrder.push_back(cur);
        for (int nbr : graph[cur])
            if (--edges[nbr] == 0)
                q.push(nbr);
    }
    if (topoOrder.size() != n)
        cout << "There is a cycle" << endl;
    else
        for (auto x : topoOrder)
            cout << x << " ";
    return 0;
}