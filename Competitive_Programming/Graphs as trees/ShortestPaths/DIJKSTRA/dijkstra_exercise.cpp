#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int, int>
#define INFS 1e9
#define INFI -1e9
const int MOD = 1e9 + 7;
using namespace std;

int V;
list<pair<int, int>> *l;

void addEdge(int u, int v, int w)
{
    l[u].push_back({v, w});
    l[v].push_back({u, w});
}

vector<int> dijkstra(int src, int end)
{
    vector<pair<int, int>> dist(V, {INT_MAX, -1});
    set<pair<int, int>> s;

    s.insert({0, src});
    dist[src] = {src, 0};
    while (!s.empty())
    {

        auto it = s.begin();
        int node = it->second;
        int w = it->first;
        s.erase(it);

        for (auto nbr : l[node])
        {
            int dest = nbr.first;
            int we = nbr.second;

            if (we + w < dist[dest].first)
            {
                auto f = s.find({dist[dest].first, dest});
                if (f != s.end())
                {
                    s.erase(f);
                }

                dist[dest].first = w + we;
                dist[dest].second = node;
                s.insert({dist[dest].first, dest});
            }
        }
    }

    if (dist[end].second == -1)
        return vector<int>{-1};

    vector<int> ans;
    int cur = dist[end].second;
    ans.push_back(end + 1);
    while (cur != src)
    {
        ans.push_back(cur + 1);
        cur = dist[cur].second;
    }
    ans.push_back(src + 1);
    reverse(ans.begin(), ans.end());
    delete l;
    return ans;
}

vector<int> shortestPath(vector<vector<int>> roads, int n)
{
    l = new list<pair<int, int>>[n];
    V = n;
    for (vector<int> vec : roads)
    {
        int u = vec[0] - 1;
        int v = vec[1] - 1;
        int w = vec[2];
        addEdge(u, v, w);
    }
    return dijkstra(0, n - 1);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(m, vi(3));
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {u, v, w};
        }
        vector<int> ans = shortestPath(edges, n);
        if (ans.size() == 1)
            cout << "-1" << "\n";
        else
            for (auto x : ans)
                cout << x << " ";
        cout << "\n";
    }
    return 0;
}