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

const int N = 26;

void floyd(vvi &g)
{
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
        {
            if (k == i)
                continue;
            for (int j = 0; j < N; j++)
            {
                if (k == j || i == j)
                    continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
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
        string s1, s2;
        cin >> s1 >> s2;
        int m;
        cin >> m;
        vvi g(N, vi(N, INT_MAX));
        for (int i = 0; i < N; i++)
            g[i][i] = 0;

        for (int i = 0; i < m; i++)
        {
            char a, b;
            cin >> a >> b;
            int u = a - 'a', v = b - 'a', w;
            cin >> w;
            g[u][v] = min(g[u][v], w);
        }

        if (s1.length() != s2.length())
            cout << "-1" << "\n";
        else
        {
            floyd(g);

            int ans = 0;
            string ansS = s1;
            for (int i = 0; i < s1.length(); i++)
            {
                int u = s1[i] - 'a';
                int v = s2[i] - 'a';
                if (u == v)
                    continue;
                int letterMin;
                char letter;
                if (g[u][v] < g[v][u])
                {
                    letter = s2[i];
                    letterMin = g[u][v];
                }
                else
                {
                    letter = s1[i];
                    letterMin = g[v][u];
                }

                for (int i = 0; i < N; i++)
                {
                    if (i != u && i != v)
                    {
                        if (letterMin > g[u][i] + g[v][i])
                        {
                            letterMin = g[u][i] + g[v][i];
                            letter = i + 'a';
                        }
                    }
                }
                if (letterMin == INT_MAX)
                {
                    cout << "-1" << "\n";
                    return 0;
                }
                ansS[i] = letter;
                ans += letterMin;
            }
            cout << ans << "\n";
            cout << ansS << "\n";
        }
    }
    return 0;
}