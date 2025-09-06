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
int ft[2*MAXN], euler[2*MAXN], tin[MAXN],tout[MAXN];
int n, N, timer,q;

void dfs(int x, int p){
    tin[x] = timer++;
    forEC(y, nodes[x].nbr){
        if(y!=p){
            dfs(y,x);
        }
    }
    tout[x] = timer++;
}

void add(int i, int val)
    {
        for (i++; i <= N; i += (i & (-i))) 
            ft[i] += val;
    }

int query(int i)
{
    int ans = 0;
    for (i++; i; i -= (i & (-i)))
        ans += ft[i];
    return ans;
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
        N = (2*n)+1;
        timer = 0;
        for( int i = 1; i <=n ; i++ ){
            cin>>nodes[i].val;
        }
        for( int i = 0; i < n-1; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }

        dfs(1,0);
        for( int i = 1; i <= n; i++ ){
            add( tin[i],nodes[i].val );
            add( tout[i],-nodes[i].val );
        }

        while(q--){
            int opt,v,x;
            cin>>opt;
            if( opt == 1 ){
                cin>>v>>x;
                add( tin[v], (x-nodes[v].val) );
                add( tout[v], -(x-nodes[v].val) );
                nodes[v].val = x;
            }else{
                cin>>v;
                cout<<query(tin[v])<<"\n";
            }
        }
    }
    return 0;
}