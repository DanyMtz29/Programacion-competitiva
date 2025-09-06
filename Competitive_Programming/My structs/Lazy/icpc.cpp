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
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vi arr(n);
    forN(n, arr);

    // sqrt-decomposition setup
    int B = max<int>(1, sqrt(n));
    int nb = (n + B - 1) / B;
    vi blockAdd(nb, 0), blockMin(nb, LLONG_MAX), blockMax(nb, LLONG_MIN);

    // build blocks
    for (int i = 0; i < n; i++)
    {
        int b = i / B;
        blockMin[b] = min(blockMin[b], arr[i]);
        blockMax[b] = max(blockMax[b], arr[i]);
    }

    auto rebuild_block = [&](int b)
    {
        int l = b * B;
        int r = min(n, l + B);
        int mn = LLONG_MAX, mx = LLONG_MIN;
        for (int i = l; i < r; i++)
        {
            int v = arr[i];
            mn = min(mn, v);
            mx = max(mx, v);
        }
        blockMin[b] = mn;
        blockMax[b] = mx;
    };

    function<int(int, int)> query = [&](int l, int r)
    {
        int res = LLONG_MIN;
        int bl = l / B, br = r / B;
        if (bl == br)
        {
            for (int i = l; i <= r; i++)
                res = max(res, arr[i] + blockAdd[bl]);
        }
        else
        {
            int end_bl = (bl + 1) * B - 1;
            for (int i = l; i <= end_bl; i++)
                res = max(res, arr[i] + blockAdd[bl]);
            for (int b = bl + 1; b < br; b++)
                res = max(res, blockMax[b] + blockAdd[b]);
            for (int i = br * B; i <= r; i++)
                res = max(res, arr[i] + blockAdd[br]);
        }
        return res;
    };

    auto update = [&](int l, int r, int val)
    {
        int bl = l / B, br = r / B;
        if (bl == br)
        {
            for (int i = l; i <= r; i++)
                arr[i] += val;
            rebuild_block(bl);
        }
        else
        {
            int end_bl = (bl + 1) * B - 1;
            for (int i = l; i <= end_bl; i++)
                arr[i] += val;
            rebuild_block(bl);
            for (int b = bl + 1; b < br; b++)
            {
                blockAdd[b] += val;
            }
            for (int i = br * B; i <= r; i++)
                arr[i] += val;
            rebuild_block(br);
        }
    };

    auto reset_range = [&](int l, int r, int M)
    {
        int bl = l / B, br = r / B;
        if (bl == br)
        {
            for (int i = l; i <= r; i++)
            {
                if (arr[i] + blockAdd[bl] == M)
                    arr[i] = 0 - blockAdd[bl];
            }
            rebuild_block(bl);
        }
        else
        {
            int end_bl = (bl + 1) * B - 1;
            for (int i = l; i <= end_bl; i++)
            {
                if (arr[i] + blockAdd[bl] == M)
                    arr[i] = 0 - blockAdd[bl];
            }
            rebuild_block(bl);

            for (int b = bl + 1; b < br; b++)
            {
                if (blockMin[b] + blockAdd[b] > M || blockMax[b] + blockAdd[b] < M)
                    continue;
                if (blockMin[b] + blockAdd[b] == M && blockMax[b] + blockAdd[b] == M)
                {
                    // entire block equals M
                    blockAdd[b] -= M;
                    // now all real values (arr+add) are zero, so rebuild to 0
                    int l0 = b * B, r0 = min(n, l0 + B);
                    for (int i = l0; i < r0; i++)
                        arr[i] = 0 - blockAdd[b];
                    blockMin[b] = blockMax[b] = 0;
                }
                else
                {
                    int l0 = b * B, r0 = min(n, l0 + B);
                    for (int i = l0; i < r0; i++)
                    {
                        if (arr[i] + blockAdd[b] == M)
                            arr[i] = 0 - blockAdd[b];
                    }
                    rebuild_block(b);
                }
            }

            for (int i = br * B; i <= r; i++)
            {
                if (arr[i] + blockAdd[br] == M)
                    arr[i] = 0 - blockAdd[br];
            }
            rebuild_block(br);
        }
    };

    int M;
    while (q--)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'Q')
        {
            cout << query(a - 1, b - 1) << '\n';
        }
        else if (c == 'A')
        {
            update(a - 1, b - 1, 1);
        }
        else
        {
            M = query(0, n - 1);
            reset_range(a - 1, b - 1, M);
        }
    }
    return 0;
}