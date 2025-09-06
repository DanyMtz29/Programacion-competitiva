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

bool check(int diff, vi &tasks, vi &workers, int pills, int s)
{
    multiset<int> st;

    for (int i = workers.size() - diff; i < workers.size(); i++)
        st.insert(workers[i]);

    for (int i = diff - 1; i >= 0; i--)
    {
        if (*prev(st.end()) >= tasks[i])
            st.erase(prev(st.end()));
        else
        {
            if (pills == 0)
                return false;
            pills--;
            auto index = st.lower_bound(tasks[i] - s);
            if (index == st.end())
                return false;
            st.erase(index);
        }
    }
    return true;
}

int solve(vi &tasks, vi &workers, int pills, int s)
{
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int t = tasks.size();
    int w = workers.size();

    int l = 0;
    int r = min(t, w);

    int mid, ans = 0;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if (check(mid, tasks, workers, pills, s))
        {
            ans = mid;
            l = mid;
        }
        else
            r = mid - 1;
    }
    return ans;
}

int32_t main()
{

    // vi tasks = {3, 2, 1};
    // vi workers = {0, 3, 3};
    vi tasks = {5, 4};
    vi workers = {0, 0, 0};
    // vi tasks = {10, 15, 30};
    // vi workers = {0, 10, 10, 10, 10};
    int pills = 1;
    int s = 5;
    cout << solve(tasks, workers, pills, s) << endl;
    // vi arr = {5, 8, 9, -1, 15, 12};
    // int num = 1;
    // int index = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
    // if (index >= 0 && index < arr.size())
    // {
    //     cout << "index: " << index << endl;
    //     cout << "Valor en index: " << arr[index] << endl;
    // }
    // else
    //     cout << "Elemento no encontrado" << endl;
    return 0;
}