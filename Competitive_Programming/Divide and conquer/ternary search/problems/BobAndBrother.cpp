//https://codeforces.com/problemset/problem/439/D
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

int f(int x, vi &a, vi &b, int itA, int itB)
{
    int cost = 0;
    // Costo de A
    for (int i = 0; i < itA; i++)
        cost += (x - a[i]);
    // Costo de B
    for (int i = b.size() - 1; i >= itB; i--)
        cost += (b[i] - x);
    return cost;
}

void ternarySearch(vi &a, vi &b)
{
    if (a[0] > b[b.size() - 1])
    {
        cout << "0\n";
        return;
    }
    int left = a[0];
    int right = b[b.size() - 1];

    while (right - left > 2)
    {

        int mid1 = (2 * left + right) / 3;
        int mid2 = (left + 2 * right) / 3;

        int idMenor1 = lower_bound(all(a), mid1) - a.begin();
        int idMayor1 = upper_bound(all(b), mid1) - b.begin();
        int costMid1 = f(mid1, a, b, idMenor1, idMayor1);

        int idMenor2 = lower_bound(all(a), mid2) - a.begin();
        int idMayor2 = upper_bound(all(b), mid2) - b.begin();
        int costMid2 = f(mid2, a, b, idMenor2, idMayor2);

        if (costMid1 > costMid2)
            left = mid1;
        else
            right = mid2;
    }

    int minCost = LONG_LONG_MAX;
    while (left <= right)
    {
        int itA = lower_bound(all(a), left) - a.begin();
        int itB = upper_bound(all(b), left) - b.begin();
        minCost = min(minCost, f(left++, a, b, itA, itB));
    }
    cout << minCost << endl;
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
        vi a(n), b(m);
        forN(n, a);
        forN(m, b);
        sort(all(a));
        sort(all(b));
        ternarySearch(a, b);
    }
    return 0;
}