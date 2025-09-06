//https://www.spoj.com/problems/SUBSUMS/
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
const int MOD = 1e9 + 7;
using namespace std;

vi subsetSums(vi &a){
    int n = a.size();
    vi result;

    for (int i = 0; i < (1 << n); i++){
        int sum = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1)
                sum += a[j];

        result.pb(sum);
    }
    return result;
}

void meet_in_the_middle(int a, int b, int n, vi& v){
    vi left, right;
    for (int i = 0; i < n; i++){
        if (i <= n / 2)
            left.pb(v[i]);
        else
            right.pb(v[i]);
    }
    vi left_sums = subsetSums(left);
    vi right_sums = subsetSums(right);

    sort(all(right_sums));
    int ans = 0;
    for (auto x : left_sums)
        ans += upper_bound(all(right_sums), b - x) - lower_bound(all(right_sums), a - x);

    cout << ans << "\n";
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
        int n, a, b;
        cin >> n >> a >> b;
        vi v(n);
        forN(n, v);
        vi left, right;
        for (int i = 0; i < n; i++)
        {
            if (i <= n / 2)
                left.pb(v[i]);
            else
                right.pb(v[i]);
        }
        vi left_sums = subsetSums(left);
        vi right_sums = subsetSums(right);

        sort(all(right_sums));
        int ans = 0;
        for (auto x : left_sums)
            ans += upper_bound(all(right_sums), b - x) - lower_bound(all(right_sums), a - x);

        cout << ans << "\n";
    }
    return 0;
}