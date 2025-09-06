#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6;
int fact[N];

int mulm(int a, int b)
{
    return (a * b) % MOD;
}

void factorials()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = mulm(fact[i - 1], i);
    }
}

int pwrm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = mulm(res, a);
        a = mulm(a, a);
        b /= 2;
    }
    return res;
}

int inv(int x)
{
    return pwrm(x, MOD - 2);
}

void updateMap(unordered_map<int, int> &mp, int &factElements, int oldVal, int val)
{
    if (mp[oldVal] >= 2)
    {
        mp[oldVal]--;
        factElements = mulm(mulm(factElements, inv(fact[mp[oldVal] + 1])), fact[mp[oldVal]]);
    }
    else
        mp[oldVal]--;

    mp[val]++;
    if (mp[val] >= 2)
        factElements = mulm(mulm(factElements, inv(fact[mp[val] - 1])), fact[mp[val]]);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    factorials();

    int szArray, queries;
    cin >> szArray >> queries;

    vec arr(szArray);
    unordered_map<int, int> mp;

    int element;
    int factElements = 1;
    for (int i = 0; i < szArray; i++)
    {
        cin >> element;
        arr[i] = element;
        mp[element]++;
        factElements = mulm(factElements, mp[element]);
    }

    int invTotal = inv(fact[szArray]);
    int res = mulm(factElements, invTotal);
    cout << res << endl;

    while (queries--)
    {
        int index, val;
        cin >> index >> val;
        index--;

        updateMap(mp, factElements, arr[index], val);
        arr[index] = val;

        res = mulm(factElements, invTotal);
        cout << res << endl;
    }

    return 0;
}