//https://codeforces.com/problemset/problem/191/C
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

const int MAXN = 100005;
const int M = 20;

struct node{
    vector<pi> nbr;
};

node nodes[MAXN];
int n,q, parents[MAXN][M], depth[MAXN], cnt[MAXN];
int ansEdges[MAXN];

void dfs(int node, int par){
    depth[node] = depth[par] + 1;

    parents[node][0] = par;
    for( int i = 1; i < M; i++ ){
        parents[node][i] = parents[ parents[node][i-1] ][i-1];
    }

    forEC(pr, nodes[node].nbr){
        int x = pr.F;
        if( x == par ) continue;
        dfs(x, node);
    }
}

int LCA(int a, int b){
    if( a==b ) return a;

    if( depth[a] < depth[b] ) swap(a,b);

    int diff = depth[a] - depth[b];
    for( int i = M-1; i >=0 ; i-- ){
        if( (diff>>i)&1 ){
            a = parents[a][i];
        }
    }

    if( a==b ) return a;

    for( int i = M-1; i >=0 ; i-- ){
        if( parents[a][i]!=parents[b][i] ){
            a = parents[a][i];
            b = parents[b][i];
        }
    }

    return parents[a][0];
}

void dfs2(int node, int par){

    forEC(pr, nodes[node].nbr){
        int x = pr.F;
        int idx = pr.S;
        if( x == par) continue;
        dfs2(x,node);
        cnt[node] += cnt[x];
        ansEdges[idx] = cnt[x];
    }
    
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
        for( int i = 0; i < n-1; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb({v,i});
            nodes[v].nbr.pb({u,i});
        }

        dfs(1,0);
        cin>>q;

        while(q--){
            int a,b;
            cin>>a>>b;
            int c = LCA(a,b);
            cnt[a]++;
            cnt[b]++;
            cnt[c]-=2;
        }

        dfs2(1,0);
        for( int i = 0; i < n-1; i++ ){
            cout<<ansEdges[i]<<" ";
        }
        cout<<"\n";

    }
    return 0;
}