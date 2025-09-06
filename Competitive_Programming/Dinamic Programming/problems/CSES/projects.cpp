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

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int MAXN = 4000010;
        int n;
        cin >> n;

        vector<vi> aux(n);
        // reward, endEvent
        vector<vector<pi>> days(MAXN);
        vi totalDays;
        for (int i = 0; i < n; i++)
        {
            int s, e, r;
            cin >> s >> e >> r;
            // days[s].pb({r, e});
            totalDays.pb(s);
            totalDays.pb(e);
            aux[i] = {s, e, r};
        }

        // Compresion de coordenadas
        sort(all(totalDays));
        eraseU(totalDays);
        unordered_map<int, int> mp;
        for (int i = 0; i < totalDays.size(); i++)
            mp[totalDays[i]] = i + 1;

        for (int i = 0; i < n; i++)
        {
            int s = aux[i][0], e = aux[i][1], r = aux[i][2];
            // cout << "Dia " << s << ", corresponde a la coordenada " << mp[s] << "\n";
            // cout << "Dia " << e << ", corresponde a la coordenada " << mp[e] << "\n";
            s = mp[s];
            e = mp[e];
            days[s].pb({r, e});
        }

        vector<int> dp(MAXN, 0);
        int currReward = 0;
        for (int day = 1; day <= MAXN; day++)
        {
            vector<pi> events = days[day];
            for (const auto &p : events)
            {
                int reward = p.F;
                int endEvent = p.S;
                dp[endEvent] = max(dp[endEvent], currReward + reward);
            }
            currReward = max(currReward, dp[day]);
        }
        cout << currReward << "\n";
    }
    return 0;
}