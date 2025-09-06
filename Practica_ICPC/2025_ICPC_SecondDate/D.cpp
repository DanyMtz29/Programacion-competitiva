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
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define pb push_back
#define F first
#define S second
const int MOD = 1e9 + 7;
using namespace std;

int find(int x, vi &par)
{
    if (par[x] == -1)
        return x;

    return par[x] = find(par[x], par);
}

void unionDSU(int a, int b, vi &par, vi &rank)
{
    int x = find(a, par);
    int y = find(b, par);
    if (x != y)
    {
        if (rank[x] > rank[y])
        {
            par[y] = x;
            rank[x] += rank[y];
        }
        else
        {
            par[x] = y;
            rank[y] += rank[x];
        }
    }
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
        vi arr(n + 1);
        multimap<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            int e;
            cin >> e;
            arr[i] = e;
            mp.insert({e, i});
        }

        unordered_map<int, priority_queue<pi, vector<pi>, greater<pi>>> graph;
        vector<int> parent(n + 1, -1);
        vector<int> rank(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            int start, end;
            cin >> start >> end;
            graph[start].push({arr[end], end});
            graph[end].push({arr[start], start});
        }

        vi ans(n + 1, -1);
        queue<int> prevs;
        int valPrev = mp.begin()->first;
        for (auto parClave : mp)
        {
            int valor = parClave.F;
            int index = parClave.S;

            if (valor == valPrev)
                prevs.push(index);
            else
            {
                valPrev = valor;
                while (!prevs.empty())
                {
                    int it = prevs.front();
                    prevs.pop();
                    ans[it] = rank[find(it, parent)];
                }
                prevs.push(index);
            }

            auto p = graph[index];

            while (!p.empty())
            {
                int nbr = p.top().F;
                int indexNbr = p.top().S;
                if (nbr > valor)
                    break;
                if (find(index, parent) != find(indexNbr, parent))
                    unionDSU(index, indexNbr, parent, rank);

                p.pop();
            }
        }
        while (!prevs.empty())
        {
            int it = prevs.front();
            prevs.pop();
            ans[it] = rank[find(it, parent)];
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << "\n";
    }
    return 0;
}