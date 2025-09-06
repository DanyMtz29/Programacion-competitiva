#include <bits/stdc++.h>

using namespace std;

int divisible(int n, vector<int> &v)
{
    int ans = 0;
    int m = v.size();
    for (int i = 1; i < (1 << m); i++)
    {
        int lcm = 1;
        for (int j = 0; j < m; j++)
        {
            if ((i >> j) & 1)
            {
                lcm *= v[j];
            }
        }
        if (__builtin_popcount(i) % 2 == 0)
        {
            ans -= (n / lcm);
        }
        else
        {
            ans += (n / lcm);
        }
    }
    return ans;
}

int numDivisible(int l, int r, vector<int> &arr)
{
    return divisible(r, arr) - divisible(l - 1, arr);
}

int main()
{
    // int l = 579000;
    // int r = 987654;
    int r = 100;
    int l = 0;
    // vector<int> a = {2,3,5,7,11,13,17,19,23,29};
    vector<int> a = {2, 3, 5};
    cout << numDivisible(l, r, a) << endl;
    return 0;
}