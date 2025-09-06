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
#define forEC(var, container) for( const auto& var: container)
#define forE(var, container) for( const auto& var: container)
const int MOD=1e9+7;
using namespace std;

const int MAXN = 200005;

struct node{
    int val;
    vi nbr;
};

node nodes[MAXN];
int tin[MAXN], tout[MAXN], timer;
int ft[2*MAXN],n, ans[MAXN];
unordered_map<int,int> mp;


void dfs(int x, int par){
    tin[x] = timer++;
    forEC(y,nodes[x].nbr){
        if( y!=par ) dfs(y,x);
    }
    tout[x] = timer++;
}

void add(int i, int val){
    for (i; i <= 2*n; i += (i & (-i))) 
        ft[i] += val;
}

int query(int i){
    int ans = 0;
    for (i; i; i -= (i & (-i)))
        ans += ft[i];
    return ans;
}

int rangeQuery(int l, int r){
    return query(r) - query(l - 1);
}

void dfs2(int x, int par){
    //cout<<"NODO: "<<x<<"\n";
    if( mp.count(nodes[x].val) ){
        add(mp[ nodes[x].val ],-1);
    }
    mp[nodes[x].val] = tin[x];
    add(tin[x], 1);
    //cout<<"Fenwick Tree en este nodo"<<"\n";
    //show();
    forEC(y, nodes[x].nbr){
        if( y!=par ){
            dfs2(y,x);
        }
    }
    ans[x] = rangeQuery(tin[x], tout[x]);
    //cout<<""<<"\n";
    //cout<<"Termina con el nodo "<<x<<"\n";
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cin>>n;
        timer = 1;
        for( int i = 1; i <=n; i++ ){
            cin>>nodes[i].val;
        }
        for( int i = 0; i < n-1; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }
        dfs(1, -1);
        dfs2(1,-1);
        for( int i = 1; i <= n ; i++ ){
            cout<<ans[i]<<(i==n?"\n":" ");
        }
    }
    return 0;
}
/*
    1-2
   / \
  2-3 3-2
 /   / \
6-1 4-2 5-1
EULER TOUR
 1 2 3  4 5 6
 1 2 5  6 8 3
11 4 10 7 9 4
FT
 1 2 3 4 5 6 7 8 9 10
 1 1 1 1 1 2 2 3 3 3

[1] = 8
[2] = 1
[3] = 5
[4] = 
[5] = 

*/