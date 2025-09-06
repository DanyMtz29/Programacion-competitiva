//https://leetcode.com/problems/maximum-product-subarray/description/
#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

// 3,-1,4

int max_product(vec &arr)
{
    int start = 1;
    int end = 1;
    int res = INT_MIN;
    int sz = arr.size();
    for (int i = 0; i < sz; i++)
    {
        if (start == 0)
            start = 1;
        if (end == 0)
            end = 1;
        start *= arr[i];
        end *= arr[sz - i - 1];
        res = max({res, start, end});
    }
}

int32_t main(){
    return 0;
}