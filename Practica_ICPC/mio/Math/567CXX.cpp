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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> r;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        r[e]++;
        arr[i] = e;
    }

    if (k == 1ll)
    {
        int ans = 0;
        unordered_map<int, int> conteo;
        for (int num : arr)
        {
            conteo[num] = (conteo.count(num) ? conteo[num] : 0) + 1;
            // conteo.put(num, conteo.getOrDefault(num, 0) + 1);
        }

        for (auto &p : conteo)
        {
            int max = p.second - 3 + 1;
            for (int i = 1; i <= max; i++)
                ans += i * (i + 1) / 2;
        }
        cout << ans << endl;
        return 0;
    }

    unordered_map<int, int> l;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            continue;
        l[arr[i]]++;
        r[arr[i]]--;
        if (arr[i] % k == 0)
            if (r.count(arr[i] * k))
                ans += l[arr[i] / k] * r[arr[i] * k];
    }

    int max = r[0] - 3 + 1;
    for (int i = 1; i <= max; i++)
        ans += i * (i + 1) / 2;

    cout << ans << endl;
    return 0;
}