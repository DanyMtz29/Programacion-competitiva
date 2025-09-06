//https://atcoder.jp/contests/abc206/tasks/abc206_d
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

const int MAXN = 2e5 + 1;

vi parent(MAXN);

int find(int a)
{
    if (parent[a] == -1)
        return a;
    return parent[a] = find(parent[a]);
}

bool unir(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y)
    {
        parent[y] = x;
        return true;
    }
    else
        return false;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    for (int i = 0; i <= MAXN; i++)
        parent[i] = -1;

    // cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vi arr(n);
        forN(n, arr);
        int movs = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (arr[i] == arr[n - i - 1])
                continue;
            if (unir(arr[i], arr[n - i - 1]))
                movs++;
        }
        cout << movs << endl;
    }
    return 0;
}