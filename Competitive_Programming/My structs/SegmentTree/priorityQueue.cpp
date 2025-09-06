#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

const int N = 1e5;

struct value
{
    bool exist;
    int val;
    value()
    {
        this->exist = false;
    }
};

struct Pq
{
    vector<value> st;
    void build()
    {
        st.resize(4 * N);
    }

    void insert(int currentNode, int val)
    {
        if (!st[currentNode].exist)
        {
            st[currentNode].exist = true;
            st[currentNode].val = val;
            return;
        }
        else
        {
            if (val < st[currentNode].val)
            {
                insert(currentNode * 2 + 1, val);
            }
            else
            {
                insert(currentNode * 2 + 2, val);
            }
        }
    }

    void show()
    {
        for (int i = 0; i < 30; i++)
        {
            if (st[i].exist)
            {
                cout << st[i].val << "|";
            }
        }
        cout << endl;
    }

    void queryMax(int currentNode, int startPoint, int &max_val)
    {
        if (!st[currentNode].exist)
            return;

        if (st[currentNode].val == startPoint)
        {
            max_val = startPoint;
            return;
        }

        if (startPoint < st[currentNode].val)
        {
            max_val = st[currentNode].val;
            queryMax(currentNode * 2 + 1, startPoint, max_val);
        }
        else
        {
            queryMax(currentNode * 2 + 2, startPoint, max_val);
        }
    }

    void queryMin(int currentNode, int startPoint, int &min_val)
    {
        if (!st[currentNode].exist)
            return;

        if (st[currentNode].val == startPoint)
        {
            min_val = startPoint;
            return;
        }

        if (startPoint < st[currentNode].val)
        {
            queryMin(currentNode * 2 + 1, startPoint, min_val);
        }
        else
        {
            min_val = st[currentNode].val;
            queryMin(currentNode * 2 + 2, startPoint, min_val);
        }
    }
};

int32_t main()
{
    Pq pq;
    pq.build();
    pq.insert(0, 15);
    pq.insert(0, 6);
    pq.insert(0, 14);
    pq.insert(0, 21);
    pq.insert(0, 10);
    pq.insert(0, 19);
    pq.insert(0, 1e9);
    // pq.show();

    int n;
    while (cin >> n)
    {
        int min_val = INT_MIN;
        int max_val = INT_MAX;
        pq.queryMin(0, n, min_val);
        pq.queryMax(0, n, max_val);
        if (min_val == INT_MIN)
        {
            cout << "(,";
        }
        else
        {
            cout << "(" << min_val << ", ";
        }
        if (max_val == INT_MAX)
        {
            cout << ")" << endl;
        }
        else
        {
            cout << max_val << ")" << endl;
        }
    }

    return 0;
}