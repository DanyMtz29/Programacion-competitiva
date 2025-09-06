#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

vector<int> zAlgorithm(vec &arr)
{
    vector<int> z(arr.size());
    int left = 0, right = 0;
    for (int k = 0; k < arr.size(); k++)
    {
        if (k > right)
        {
            left = right = k;
            while (right < arr.size() && arr[right] == arr[right - left])
            {
                right++;
            }
            z[k] = right - left;
            right--;
        }
        else
        {
            int k1 = k - left;
            if (z[k1] < right - k + 1)
            {
                z[k] = z[k1];
            }
            else
            {
                left = k;
                while (right < arr.size() && arr[right] == arr[right - left])
                {
                    right++;
                }
                z[k] = right - left;
                right--;
            }
        }
    }
    return z;
}

int buildArray(vec &a, vec &b)
{
    vec newArray(a.size() + 1 + b.size());
    int i = 0;
    for (int num : a)
    {
        newArray[i++] = num;
    }
    newArray[i++] = INT_MIN;

    for (int num : b)
    {
        newArray[i++] = num;
    }

    vec z = zAlgorithm(newArray);
    int count = 0;
    for (int i = 0; i < z.size(); i++)
    {
        if (z[i] == a.size())
        {
            count++;
        }
    }

    return count;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec a(n - 1);
    vec b(m - 1);
    int temp1, temp2;
    cin >> temp1;
    for (int i = 1; i < n; i++)
    {
        cin >> temp2;
        a[i - 1] = temp1 - temp2;
        temp1 = temp2;
    }

    cin >> temp1;
    for (int i = 1; i < m; i++)
    {
        cin >> temp2;
        b[i - 1] = temp1 - temp2;
        temp1 = temp2;
    }

    if (n == 1)
        cout << m << endl;
    else
    {
        cout << buildArray(a, b) << endl;
    }

    return 0;
}