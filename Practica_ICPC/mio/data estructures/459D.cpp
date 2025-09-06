#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> mp;
    vector<int> lefts(n);
    vector<int> rights(n);
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        arr[i] = element;
        mp[element]++;
        lefts[i] = mp[element];
    }

    mp.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        int element = arr[i];
        mp[element]++;
        rights[i] = mp[element];
    }

    cout << "Lefts" << endl;
    copy(lefts.begin(), lefts.end(), ostream_iterator<int>(cout, "|"));
    cout << "" << endl;
    cout << "Rights" << endl;
    copy(rights.begin(), rights.end(), ostream_iterator<int>(cout, "|"));
    cout << "" << endl;

    return 0;
}