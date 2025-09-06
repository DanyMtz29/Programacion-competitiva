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
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int disposicion, actC, actD;
    cin >> disposicion >> actC >> actD;
    vector<int> cansadas(actC);
    forN(actC, cansadas);
    int contador = actD;
    for (int i = 0; i < actD; i++)
    {
        int t;
        cin >> t;
        disposicion += t;
    }

    for (int i = 0; i < actC; i++)
    {
        disposicion -= cansadas[i];
        if (disposicion < 0)
            break;
        contador++;
    }

    cout << contador << endl;
    return 0;
}