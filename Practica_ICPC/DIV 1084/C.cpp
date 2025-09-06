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
const int MOD = 1e9 + 7;
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vi arr(n);
        forN(n, arr);

        vi lefts(n, 0), rights(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(arr[i]);
                lefts[i] = 1;
                continue;
            }
            else
            {
                while (!st.empty() && st.top() >= arr[i])
                    st.pop();

                if (st.empty())
                    lefts[i] = 1;
                else
                    lefts[i] = 0;
                st.push(arr[i]);
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                st.push(arr[i]);
                rights[i] = 1;
                continue;
            }
            else
            {
                while (!st.empty() && st.top() <= arr[i])
                    st.pop();

                if (st.empty())
                    rights[i] = 1;
                else
                    rights[i] = 0;
                st.push(arr[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (lefts[i] || rights[i])
                cout << "1";
            else
                cout << "0";
        }
        cout << "\n";
    }
    return 0;
}

/*
    1 5 3 7 2 4 6

          7
*/