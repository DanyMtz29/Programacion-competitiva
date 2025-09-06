#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int32_t main()
{
    int N;
    cin >> N;
    int N2 = N;
    int count = 0;
    while (N > 0)
    {
        int number = N % 10;
        if (number != 0 && N2 % number == 0)
            count++;
        N /= 10;
    }
    cout << count << endl;
    return 0;
}