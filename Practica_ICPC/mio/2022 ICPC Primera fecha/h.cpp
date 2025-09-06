#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

int32_t main()
{
    int N;
    cin >> N;

    int count = 0;
    int square = N / 4;
    int rectangle = (N - (square * 2)) / 2 * square;
    square *= square;

    cout << (square > rectangle ? square : rectangle) << endl;

    return 0;
}