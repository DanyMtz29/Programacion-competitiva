#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

/*
Example:
7
0 1
1 2
2 3
3 5
5 6
4 5
0 4
3 4
*/

int bfs(unordered_map<int, vector<int>> &mp, int N, int src, int dest)
{
    queue<int> q;
    bool *visited = new bool[N]{0};
    int *dist = new int[N]{0};
    int *parent = new int[N]{0};

    for (int i = 0; i < N; i++)
        parent[i] = -1;

    q.push(src);
    visited[src] = true;
    parent[src] = src;
    dist[src] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int nbr : mp[front])
        {
            if (!visited[nbr])
            {
                q.push(nbr);
                parent[nbr] = front;
                dist[nbr] = dist[front] + 1;
                visited[nbr] = true;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << "Shortest dist to " << i << " is " << dist[i] << endl;

    int temp = dest;
    while (temp != src)
    {
        cout << temp << "--";
        temp = parent[temp];
    }
    cout << src << endl;
    return dist[dest];
}

int32_t main()
{
    unordered_map<int, vector<int>> graph;

    int n;
    cin >> n;
    for (int i = 0; i < 8; i++)
    {
        int src, dest;
        cin >> src >> dest;

        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    bfs(graph, n, 1, 6);

    return 0;
}