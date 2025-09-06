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

int ternarySearchPeak(const vector<int> &a){
    int l = 0, r = (int)a.size() - 1;
    // Mientras el intervalo tenga al menos 3 elementos
    while (r - l > 2){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        // Comparamos valores en m1 y m2
        if (a[m1] < a[m2])// El máximo está a la derecha de m1
            l = m1;
        else// El máximo está a la izquierda de m2 (o en m2)
            r = m2;
    }
    // Al terminar, r−l ≤ 2, así que comprobamos manualmente l, l+1, …, r
    int peak = l;
    for (int i = l + 1; i <= r; ++i)
        if (a[i] > a[peak])
            peak = i;
    return peak;
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
        vi arr = {1, 5, 10, 100, 64, 31, 31, 23, 10, 5, 1};
        cout << ternarySearchPeak(arr) << endl;
    }
    return 0;
}

/*
 0 1  2  3  4  5            5  4  3  2  1 0
 1 10 15 20 21 35           21 17 15 12 7 3
            |               |

14 5     = 15               6 2 = 23
20 10 6 1 = 36

*/