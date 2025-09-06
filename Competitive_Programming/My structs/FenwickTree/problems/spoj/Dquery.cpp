//https://www.spoj.com/problems/DQUERY/
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int,int>
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define ppi pair<pair<int,int>,int>
#define pb push_back
#define F first
#define S second
const int MOD=1e9+7;
using namespace std;

// 1 based index
struct Fenwick
{
    vi ft;
    int n;

    void init(int sz){
        this->n=sz;
        this->ft.resize(sz+1,0);
    }

    void add(int i, int val)
    {
        for (i++; i <= n; i += (i & (-i))) // MODIFICAR SI VA HASTA N
            ft[i] += val;
    }

    int query(int i)
    {
        int ans = 0;
        for (i++; i; i -= (i & (-i)))
            ans += ft[i];
        return ans;
    }

    int rangeQuery(int l, int r)
    {
        return query(r) - query(l - 1);
    }

};

struct qry{
    int idx, l, r;
    bool operator<(qry p)const{
        return this->r<p.r;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        int n,q;
        cin>>n;

        vi arr(n);
        map<int,queue<int>> mp;
        map<int,int> prevs;
        for( int i = 0; i < n; i++ ){
            cin>>arr[i];
            mp[ arr[i] ].push(i);
        }
        cin>>q;        
        vector<qry> Q(q);
        vi ans(q);

        for( int i = 0; i < q; i++ ){
            cin>>Q[i].l;
            cin>>Q[i].r;
            Q[i].r--;Q[i].l--;
            Q[i].idx = i;
        }

        sort(all(Q));

        Fenwick ft;
        ft.init(n);

        int j = 0;
        for( int i = 0; i < q; i++ ){
            int l = Q[i].l;
            int r = Q[i].r;
            while( j < n && j <= r){
                int cur = arr[j];
                if( prevs.count(cur) ) ft.add( prevs[cur] , -1);
                
                int index = mp[cur].front();
                mp[cur].pop();
                prevs[cur] = index;
                ft.add( index, 1 );
                j++;
            }
            ans[ Q[i].idx ] = ft.rangeQuery( l,r );
        }
        for( auto x: ans)
            cout<<x<<"\n";
    }
    return 0;
}
// 0 1 2 3 4
// 3 2 3 1 2
// 0 0 1 2 3 