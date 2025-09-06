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

int mergeCounts(vi &arr, int start, int end)
{
    int i = start;
    int mid = (start + end) >> 1;
    int j = mid + 1;
    vi temp;

    int countPairs = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp.pb(arr[i++]);
        else
        {
            countPairs += (mid - i + 1);
            temp.pb(arr[j++]);
        }
    }

    while (i <= mid)
        temp.pb(arr[i++]);
    while (j <= end)
        temp.pb(arr[j++]);

    int k = 0;
    for (int it = start; it <= end; it++)
        arr[it] = temp[k++];

    return countPairs;
}

int mergeWithCount(vi &arr, int start, int end)
{
    // Base case
    if (start >= end)
        return 0;
    // Recursive case
    int mid = (start + end) / 2;
    int countLeft = mergeWithCount(arr, start, mid);
    int countRight = mergeWithCount(arr, mid + 1, end);
    int countMerges = mergeCounts(arr, start, end);
    return countLeft + countRight + countMerges;
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
        int n = 5;
        vi arr = {4, 5, 6, 7, 1};
        cout << mergeWithCount(arr, 0, n - 1) << "\n";
    }
    return 0;
}