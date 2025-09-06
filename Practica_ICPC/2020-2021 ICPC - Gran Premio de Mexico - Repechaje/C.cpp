#include <bits/stdc++.h>
#define int long long int
#define vv vector<vector<int>>
#define vvb vector<vector<double>>
#define vb vector<double>
using namespace std;

struct Mat
{
    vvb m;
    int sz;
    Mat(int N)
    {
        sz = N;
        m.resize(sz, vb(sz));
        // memset(m, 0, sizeof(m));
    }

    void cpy(vvb &arr)
    {
        m.resize(sz, vb(sz));
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                m[i][j] = arr[i][j];
            }
        }
    }

    void identity()
    {
        for (int i = 0; i < sz; i++)
        {
            m[i][i] = 1;
        }
    }
    Mat operator*(Mat a)
    {
        Mat res(sz);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    // res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

void solve(vvb &arr, int N, int M)
{
    Mat res(N);
    res.identity();
    Mat T(N);
    T.cpy(arr);
    while (M)
    {
        if (M & 1)
            res = res * T;
        T = T * T;
        M /= 2;
    }
    for (int i = 0; i < N; i++)
    {
        cout << res.m[0][i] << " ";
    }
    cout << "" << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vvb arr(N, vb(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    solve(arr, N, M);

    return 0;
}