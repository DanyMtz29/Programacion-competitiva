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
#define F first
#define S second
const int MOD = 1e9 + 7;
using namespace std;

// Retorna el total de la interseccion y el total de pasos
pi sol(int l1, int r1, int l2, int r2, int k)
{
    int total = abs(min(l1, l2) - max(r1, r2));
    int pasos = abs(l2 - l1) + abs(r1 - r2);
    if (total <= k)
        return {total, pasos};
    else
    {
        // Distancia entre el fin del primero y el inicio del segundo, es decir la union
        int dist = l2 - r1;
        // Como ya se unieron, se iguala el principio del segundo y el final del primero
        if (r1 - l2 >= k)
            return {r1 - l2, 0};

        // Si la distancia es negativa, se contraresta con el resto de pasos de k
        // Por ejemplo, r1=4 y l2=2. Dist seria -2, y suponiendo que restarian 4 pasos, en total
        // ya hay 2 de la interseccion, faltarian 2 mas para completar
        return {k, dist + k};
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int totalSegments, k, l1, r1, l2, r2;
        cin >> totalSegments >> k >> l1 >> r1 >> l2 >> r2;

        int ans = 0;

        if (l1 == l2)
        {
            if (r2 < r1)
                swap(r1, r2);
        }
        else if (l2 < l1)
        {
            swap(l1, l2);
            swap(r1, r2);
        }

        if ((r1 - l2) * totalSegments >= k)
            k = 0;

        int total = abs(min(l1, l2) - max(r1, r2));
        int pasos = abs(l2 - l1) + abs(r1 - r2);
        cout << "pasos: " << pasos << "\n";
        cout << "Total: " << total << "\n";

        for (int i = 0; i < totalSegments; i++)
        {
            if (k == 0)
                break;
            if (i == 0)
            {
                auto p = sol(l1, r1, l2, r2, k);
                ans += p.S;
                k -= p.F;
            }
            else
            {
                auto p = sol(l1, r1, l2, r2, k);
                int intersection = p.F;
                int dist = p.S;
                if (dist < (intersection * 2))
                {
                    ans += dist;
                    k -= intersection;
                }
                else
                {
                    ans += (intersection * 2);
                    k -= intersection;
                }
            }
            cout << "i: " << i << ", K: " << k << "\n";
        }
        cout << "Ans: " << ans << "\n";
        if (k > 0)
            ans += (k * 2);

        cout << ans << "\n";
    }
    return 0;
}