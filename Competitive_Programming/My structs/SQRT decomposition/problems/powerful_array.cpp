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

const int MAXN = 1e6+5;

using namespace std;

vi cnt(MAXN,0);        
int total = 0;

void add(int x){
    total -= ( cnt[x]*cnt[x]* x);
    cnt[x]++;
    total += ( cnt[x]*cnt[x] * x);
}

void remove(int x){
    total -= ( cnt[x]*cnt[x] * x);
    cnt[x]--;
    total += ( cnt[x]*cnt[x] * x);
    
}

struct qry{
    int l,r,ans,idx,block;
    bool operator<(qry P)const{
        return make_pair(this->block, this->r)<make_pair(P.block, P.r);
    }
};

bool cmp2(const qry& a, const qry& b){
    if( a.block != b.block ) return a.block<b.block;
    return (a.r<b.r)^(a.block%2);
}

bool cmp( const qry& a, const qry& b){
    return a.idx < b.idx;
}

void Mo_algorithm(){
    int n,q, root;
    cin>>n>>q;
    //root = sqrt(n);
    root = 1000;

    vi a(n);
    vector<qry> Q(q);
    forN(n,a);

    for( int i = 0; i < q; i++ ){
        cin>>Q[i].l>>Q[i].r;
        Q[i].l--;
        Q[i].r--;
        Q[i].block = Q[i].l/root;
        Q[i].idx = i;
    }

    sort( all(Q));
        
    int x = 0, y = 0;
    for( int i = 0; i < q; i++ ){
        //adding y
        while( y <= Q[i].r ){
            add(a[y]);
            y++;
        }
        //removing y
        while( y > Q[i].r+1 ){
            y--;
            remove(a[y]);
        }
        //adding x
        while( x > Q[i].l ){
            x--;
            add(a[x]);
        }
        //removing x
        while( x < Q[i].l ){
            remove(a[x]);
            x++;
        }
        Q[i].ans = total;
    }

    sort( all(Q), cmp );
    for( int i = 0; i < q; i++ )
        cout<<Q[i].ans<<"\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        int n,q, root;
        cin>>n>>q;
        //root = sqrt(n);
        root = 1000;

        vi a(n);
        vector<qry> Q(q);
        forN(n,a);

        for( int i = 0; i < q; i++ ){
            cin>>Q[i].l>>Q[i].r;
            Q[i].l--;
            Q[i].r--;
            Q[i].block = Q[i].l/root;
            Q[i].idx = i;
        }

        sort( all(Q));
            
        int x = 0, y = 0;
        for( int i = 0; i < q; i++ ){
            //adding y
            while( y <= Q[i].r ){
                add(a[y]);
                y++;
            }
            //removing y
            while( y > Q[i].r+1 ){
                y--;
                remove(a[y]);
            }
            //adding x
            while( x > Q[i].l ){
                x--;
                add(a[x]);
            }
            //removing x
            while( x < Q[i].l ){
                remove(a[x]);
                x++;
            }
            Q[i].ans = total;
        }

        sort( all(Q), cmp );
        for( int i = 0; i < q; i++ )
            cout<<Q[i].ans<<"\n";
    }
    return 0;
}