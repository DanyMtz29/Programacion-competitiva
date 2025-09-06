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

unordered_map<int, umii> dp;

struct Segment
{
    vector<pair<int, vi>> st;
    int n;

    void init(int _n)
    {
        this->n = _n;
        this->st.resize(4 * _n, {0, {}});
    }

    void build(int start, int end, int currNode, vi &a)
    {
        if (start == end)
        {
            st[currNode] = {a[start], {start}};
            return;
        }
        int mid = (start + end) >> 1;
        build(start, mid, currNode << 1, a);
        build(mid + 1, end, currNode << 1 | 1, a);
        if (st[currNode << 1].F > st[currNode << 1 | 1].F)
            st[currNode] = {st[currNode << 1].F, st[currNode << 1].S};
        else if (st[currNode << 1 | 1].F > st[currNode << 1].F)
            st[currNode] = {st[currNode << 1 | 1].F, st[currNode << 1 | 1].S};
        else
        {
            int val = st[currNode << 1].F;
            vi b;
            for (auto x : st[currNode << 1].S)
                b.pb(x);
            for (auto x : st[currNode << 1 | 1].S)
                b.pb(x);
            st[currNode] = {val, b};
        }
    }

    pair<int, vi> query(int start, int end, int currNode, int l, int r)
    {
        if (start > r || end < l)
            return {LONG_LONG_MIN, {}};

        if (start >= l && end <= r)
            return {st[currNode].F, st[currNode].S};

        int mid = (start + end) >> 1;
        auto left = query(start, mid, currNode << 1, l, r);
        auto right = query(mid + 1, end, (currNode << 1) | 1, l, r);
        if (left.F > right.F)
            return {left.F, left.S};
        else if (right.F > left.F)
            return {right.F, right.S};
        else
        {
            int val = left.F;
            vi b;
            for (auto x : left.S)
                b.pb(x);
            for (auto x : right.S)
                b.pb(x);
            return {val, b};
        }
    }
};

int solve(Segment &st, int i, int j, int n)
{
    if (j < i)
        return 0;
    if (dp.count(i) && dp[i].count(j))
        return dp[i][j];
    vi MAXS = st.query(0, n - 1, 1, i, j).S;
    sort(all(MAXS));
    int mx = 1;
    for (int idx = 0; idx < MAXS.size(); idx++)
    {
        int MAX = MAXS[idx];

        int right = 1 + solve(st, MAX + 1, (idx < MAXS.size() - 1 ? min(j, MAXS[idx + 1] - 1) : j), n);
        int left = 1 + solve(st, (idx > 0 ? max(i, MAXS[idx - 1] + 1) : i), MAX - 1, n);
        int MX = max(left, right);
        mx = max(mx, MX);
    }
    // int MAX = st.query(
    dp[i][j] = mx;
    return mx;
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
        int n;
        cin >> n;
        vi a(n);
        forN(n, a);

        eraseU(a);

        Segment st;
        st.init(n);
        st.build(0, n - 1, 1, a);
        cout << solve(st, 0, n - 1, n) << "\n";
    }
    return 0;
}
/*

    10
    20 15 17 35 25 40 12 19 13 12

    10
    3 46 77 16 59 32 22 41 87 89
         |     |  |  |  |  |   |

*/