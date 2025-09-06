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
const int MOD = 1e9 + 7;
using namespace std;

// 1 based index
struct Fenwick{
    vi ft;
    int n;

    void init(int _n){
        this->n = _n+1;
        this->ft.resize(n,0);
    }

    void add(int i, int val){
        for (i++; i <= n; i += (i & (-i))) 
            ft[i] += val;
    }

    int query(int i){
        int ans = 0;
        for (i++; i; i -= (i & (-i)))
            ans += ft[i];
        return ans;
    }

    int rangeQuery(int l, int r){
        return query(r) - query(l - 1);
    }

    void show(){
        cout << "FENWICK TREE" << endl;
        for (int i = 0; i < n - 1; i++)
            cout << this->query(i) << " ";
        cout << "\n";
    }
};

int32_t main()
{
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    // int n = arr.size();
    //  Fenwick ft(7);
    //  for (int i = 0; i < n; i++)
    //      ft.add(i, arr[i]);

    // QUERIES
    // cout << "1-7: " << ft.rangeQuery(0, 6) << "\n";
    // cout << "2-5: " << ft.rangeQuery(1, 4) << "\n";
    // ft.show();
    // ft.add(3, 100 - (ft.rangeQuery(3, 3)));
    // ft.show();
    // cout << "1-7: " << ft.rangeQuery(0, 6) << "\n";
    // cout << "2-5: " << ft.rangeQuery(1, 4) << "\n";
    // cout << "1-3: " << ft.rangeQuery(0, 2) << "\n";

    // UPDATE RANGE
    vector<int> arr = {3, 2, 4, 5, 1, 1, 5, 3};
    int n = arr.size();
    Fenwick ft;
    ft.init(n);
    cout << "4-4: " << ft.query(3) + arr[3] << "\n";
    ft.add(4, -1);
    ft.show();
    ft.add(1, 1);
    ft.show();
    cout << "4-4: " << ft.query(3) + arr[3] << "\n";
    cout << "6-6: " << ft.query(5) + arr[5] << "\n";

    return 0;
}