#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

void fill(vector<vector<string>> &arr)
{
    arr[1].push_back("1");
    arr[3].push_back("169");
    arr[3].push_back("196");
    arr[3].push_back("961");
    // npm i bcryptjs jsonwebtoken
    // Actualizar modeloUSuarios.js
    for (int n = 5; n < 100; n += 2)
    {
        string s1 = "1";
        string s2 = "9";
        for (int i = 0; i < (n - 3) / 2; i++)
        {
            s1.append("0");
            s2.append("0");
        }

        s1.append("6");
        s2.append("6");

        for (int i = 0; i < (n - 3) / 2; i++)
        {
            s1.append("0");
            s2.append("0");
        }

        s1.append("9");
        s2.append("1");

        for (int i = 0; i < n - 2; i++)
        {
            string s = arr[n - 2][i];
            arr[n].push_back(s.append("00"));
        }

        arr[n].push_back(s1);
        arr[n].push_back(s2);
    }
}

int32_t main()
{
    vector<vector<string>> arr(101, vector<string>());
    fill(arr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
            cout << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[n][i] << endl;
            }
        }
    }
    return 0;
}