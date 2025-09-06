#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

void permutar(vector<int> &nums, vector<pair<int, vector<int>>> &arr, double sum, double total, vector<int> actual, int califMin, int &mnSize, int index)
{

    int prom = (sum / total) * 100;
    if (prom >= califMin)
    {
        if (actual.size() < mnSize)
        {
            arr.clear();
            arr.push_back({prom, actual});
            mnSize = actual.size();
            return;
        }
        else if (actual.size() == mnSize)
        {
            arr.push_back({prom, actual});
            return;
        }
    }

    if (index >= nums.size())
        return;

    vector<int> actual2 = actual;
    actual.push_back(index + 1);
    permutar(nums, arr, sum + nums[index], total, actual, califMin, mnSize, index + 1);

    permutar(nums, arr, sum, total, actual2, califMin, mnSize, index + 1);
}

int32_t main()
{

    int n, p;
    cin >> n >> p;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    };

    vector<int> a;
    vector<pair<int, vector<int>>> ans;
    // permutar(arr, ans, 0, sum, a, p, 1000, 0);
    int inf = INT_MAX;
    permutar(arr, ans, 0, sum, a, p, inf, 0);

    cout << ans[0].second.size() << " " << ans.size() << endl;
    int k = 0;
    for (auto &p : ans)
    {
        cout << p.first << " ";
        int sz = p.second.size();
        k = 0;
        for (int i : p.second)
        {
            if (k++ == sz - 1)
                cout << i;
            else
                cout << i << " ";
        }
        cout << "" << endl;
    }

    return 0;
}