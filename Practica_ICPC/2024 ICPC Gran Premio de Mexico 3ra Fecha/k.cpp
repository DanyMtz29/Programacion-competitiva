#include <bits/stdc++.h>
#include <algorithm>
#define int long long int
using namespace std;

void solve(vector<int> &arr, int N, vector<int> &ans)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        cout << "-1" << endl;
        return;
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, 0));
    dp[0][0] = 1;
    int i = 1;
    for (i = 1; i <= N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (!dp[i - 1][j])
                continue;

            dp[i][j] = 1;
            dp[i][j + arr[i - 1]] = 1;
        }
    }

    if (!dp[N][sum / 2])
    {
        cout << "-1" << endl;
        return;
    }

    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int j = sum / 2;
    i = N;
    while (i > 0)
    {
        if (!dp[i - 1][j])
        {
            // cout << "Inserta en p1: " << (i - 1) << endl;
            pq1.push(i - 1);
            j -= arr[i - 1];
        }
        else
        {
            // cout << "Inserta en p2: " << (i - 1) << endl;
            pq2.push(i - 1);
        }
        i--;
    }

    i = 0;
    // cout << "asds" << endl;
    if (pq2.top() <= pq1.top())
    {
        swap(pq1, pq2);
    }
    // cout << "asdsad" << endl;

    int alice = 0;
    int bob = 0;

    while (!pq1.empty() && !pq2.empty())
    {
        if (alice <= bob)
        {
            ans[i] = arr[pq1.top()];
            pq1.pop();
            alice += ans[i];
        }
        else
        {
            ans[i] = arr[pq2.top()];
            pq2.pop();
            bob += ans[i];
        }
        i++;
    }
    while (!pq1.empty())
    {
        ans[i++] = arr[pq1.top()];
        pq1.pop();
    }

    while (!pq2.empty())
    {
        ans[i++] = arr[pq2.top()];
        pq2.pop();
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> ans(N);
    solve(arr, N, ans);

    return 0;
}