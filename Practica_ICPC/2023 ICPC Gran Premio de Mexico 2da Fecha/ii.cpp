#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

// To execute C++, please define "int main()"
int32_t main()
{
    int a, b, c;

    cin >> a >> b >> c;

    int ans = 0;
    if (a >= 500)
    {
        ans = a - 100;
    }
    else
    {
        ans += a;
    }

    if (b >= 500)
    {
        ans += b - 100;
    }
    else
    {
        ans += b;
    }

    if (c >= 500)
    {
        ans += c - 100;
    }
    else
    {
        ans += c;
    }

    int ans2 = 0;
    if (a + b >= 500)
    {
        ans2 += (a + b) - 100;
        if (ans2 + c >= 500)
        {
            ans2 += c - 100;
        }
        else
        {
            ans2 += c;
        }
    }
    else
    {
        ans2 += a + b;
        if (ans2 + c >= 500)
        {
            ans2 += c - 100;
        }
        else
        {
            ans2 += c;
        }
    }

    int ans3 = 0;

    if (a + c >= 500)
    {
        ans3 += (a + c) - 100;
        if (ans3 + b >= 500)
        {
            ans3 += b - 100;
        }
        else
        {
            ans3 += b;
        }
    }
    else
    {
        ans3 += a + c;
        if (ans3 + b >= 500)
        {
            ans3 += b - 100;
        }
        else
        {
            ans3 += b;
        }
    }

    int ans4 = 0;

    if (b + c >= 500)
    {
        ans4 += (b + c) - 100;
        if (ans4 + a >= 500)
        {
            ans4 += a - 100;
        }
        else
        {
            ans4 += a;
        }
    }
    else
    {
        ans4 += b + c;
        if (ans4 + a >= 500)
        {
            ans4 += a - 100;
        }
        else
        {
            ans4 += a;
        }
    }

    ans = min({ans, ans2, ans3, ans4});

    cout << ans << endl;
}
