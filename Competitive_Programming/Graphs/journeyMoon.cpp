#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
#include <list>
using namespace std;

class Graph
{

    int N;
    list<int> *LIST;

public:
    Graph(int n)
    {
        this->N = n;
        this->LIST = new list<int>[N];
    }

    void addEdge(int x, int y, bool bidirectional = true)
    {
        LIST[x].push_back(y);
        if (bidirectional)
        {
            LIST[y].push_back(x);
        }
    }

    void print()
    {
        // Iterato over all the rows
        for (int i = 0; i < N; i++)
        {
            cout << i << "-->";
            for (auto node : LIST[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    void dfsHelper(int node, bool *visited, int &count)
    {
        visited[node] = true;
        count++;
        // make a dfs call on all its unvisited neighbors
        for (int nbr : LIST[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited, count);
            }
        }
        return;
    }
};

int32_t main()
{
    int N, edges;
    cin >> N >> edges;
    Graph g(N);
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }

    int total = 0;
    int count = 0;
    int prevs = 0;

    bool visited[N] = {0};
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            g.dfsHelper(i, visited, count);
            total += count * prevs;
            prevs += count;
            count = 0;
        }
    }

    cout << total << endl;

    return 0;
}