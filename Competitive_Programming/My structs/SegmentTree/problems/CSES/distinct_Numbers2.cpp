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

struct Segment
{
    vi st;
    int n;
    void init(int _n)
    {
        this->n = _n;
        this->st.resize(4 * n, INFS);
    }

    void build(int node, int start, int end, vector<pi> &a)
    {
        if (start == end)
        {
            st[node] = a[start].S;
            return;
        }

        int mid = (start + end) >> 1;
        build(node << 1, start, mid, a);
        build(node << 1 | 1, mid + 1, end, a);

        st[node] = min(st[node<<1], st[node<<1|1]);
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return INFS;
        if (start >= l && end <= r)
            return st[node];

        int mid = (start + end) >> 1;
        auto qryLeft = query(node << 1, start, mid, l, r);
        auto qryRight = query(node << 1 | 1, mid + 1, end, l, r);
        
        return min( qryLeft,qryRight );
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            st[node] = val;
            return;
        }

        int mid = (start + end) >> 1;
        if (idx <= mid)
            update(node << 1, start, mid, idx, val);
        else
            update(node << 1 | 1, mid + 1, end, idx, val);
        
        st[node] = min( st[node<<1], st[node<<1|1] );
    }
};

Segment seg;
map<int,set<int>> mp;
int n,q;

void add(int value, int idx, vector<pi>& next){//2 5

    //If the set is empty
    if( !mp.count(value) ){
        mp[value].insert(idx);
        next[idx] = {-1, n+1};
        seg.update( 1,0,n-1,idx,n+1 );
        return;
    }

    auto &st = mp[value];
    auto it = lower_bound(all(st), idx);
    
    if( it == st.end() ){
        auto prevIt = prev(it);
        int pred = *prevIt;
        next[ pred ].S = idx;
        next[ idx ] = {pred, n+1};
        seg.update(1,0,n-1,idx, n+1);
        seg.update( 1,0,n-1, pred, idx);
    }else if (it==st.begin()) {
        //auto sucIt = std::next( it );
        //int suc = *sucIt;
        next[ idx ] = { -1, *it };
        next[ *it ].F = idx;
        seg.update( 1,0,n-1,idx, *it);
    }else{
        auto prevIt = prev(it);
        next[idx] = {*prevIt, *it};
        next[ *prevIt ].S = idx;
        next[ *it ].F = idx;
        seg.update( 1,0,n-1,*prevIt, idx);
        seg.update( 1,0,n-1,idx, *it);
    }

    mp[value].insert(idx);
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cin>>n>>q;

        vi a(n);

        for( int i = 0; i < n; i++ ){
            cin>>a[i];
            mp[ a[i] ].insert(i);
        }

        vector<pi> next(n);
        for( const auto& p : mp ){
            int val = p.F;
            set<int> st = p.S;
            int prev = -1;
            int idx = -1;
            for( auto x: st ){
                if( idx==-1 )
                    idx = x;
                else{
                    next[idx] = {prev, x};
                    prev = idx;
                    idx = x;
                }
            }
            next[idx] = {prev,n+1};
        }

        seg.init(n);
        seg.build( 1, 0,n-1,next);
        
        
        while( q-- ){
            int op, A, B;
            cin>>op>>A>>B;
            if( op==1 ){
                A--;
                //Remove the prev element in the array
                int prevElement = a[A];
                auto it = lower_bound( all( mp[prevElement] ), A);
                mp[prevElement].erase(it);
                
                //Update the next Array
                int pred = next[A].F;
                int suc = next[A].S;

                if( pred != -1){
                    seg.update( 1,0,n-1,pred,suc);
                    next[ pred ].S = suc;
                }
                if( suc != n+1 )
                    next[ suc ].F = pred;
                
                add( B, A,next );
                a[ A ] = B;

            }else{
                int indexM = seg.query( 1, 0, n-1, A-1,B-1 );
                if( indexM <= B-1 )
                    cout<<"NO"<<"\n";
                else
                    cout<<"YES"<<"\n";
            }
        }
    }
    return 0;
}   