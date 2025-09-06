/*
    //https://codeforces.com/problemset/problem/208/E
    Se resolvio con LCA con binary search
    usando aplanamiento de arboles
*/
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
    int val;
    vi nbr;
};

node nodes[MAXN];
int n,q, depth[MAXN], parents[MAXN][M];
int tin[MAXN], tout[MAXN], timer, mxD;
bool vis[MAXN];
vector<int> entradas[MAXN];

void dfs(int node, int par){
    vis[node] = true;

    //Llenando en profundidad esto
    tin[node] = timer++;
    depth[node] = depth[par]+1;
    mxD = max(mxD,depth[node]);

    //LCA
    parents[node][0] = par;
    for( int j = 1; j < M; j++ ){
        parents[node][j] = parents[parents[node][j-1]][j-1];
    }

    //DFS
    forEC(nbrNode, nodes[node].nbr){
        if( nbrNode == par) continue;

        dfs( nbrNode, node );
    }

    tout[node] = timer++;
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
        timer = mxD = 0;
        for( int i = 1; i <=n ; i++ ){
            int x;
            cin>>x;
            nodes[x].nbr.pb(i);
            vis[i]=false;
        }
        //Haciendo un dfs por cada subarbol
        //que pueda haber
        for( int i = 1; i <= n; i++ ){
            if( !vis[i] && !nodes[i].nbr.empty()){
                dfs(i,0);
            }
        }
        
        for( int i = 1; i <= n ; i++ ){
            entradas[depth[i]].pb(tin[i]);
        }

        for( int i = 1; i <= mxD ; i++ ){
            sort(all(entradas[i]));
        }

        // for( int i = 1; i <= mxD ; i++ ){
        //     cout<<"Profundidad: "<<i<<", idx: ";
        //     forEC(x,entradas[i])
        //         cout<<x<<" ";
        //     cout<<"\n";
        // }

        int q;
        cin>>q;
        while(q--){
            int v,k; cin>>v>>k;

            for( int i = M-1; i >=0 ; i-- ){
                if( (k>>i)&1 ){
                    v = parents[v][i];
                }
            }

            if( v == 0 ){
                cout<<"0\n";
                continue;
            }

            //V es el apdre
            //Buscamos la profundiad del padre mas k
            //cout<<"Padre: "<<v<<endl;
            int D = depth[v]+k;
            //cout<<"Profundidad del padre: "<<depth[v]<<"\n";
            //cout<<"D: "<<D<<"\n";
            //cout<<"Entrada de v: "<<tin[v]<<"\n";
            //cout<<"Salida de v: "<<tout[v]<<"\n";
            int total = upper_bound(all(entradas[D]),tout[v])-lower_bound(all(entradas[D]),tin[v]);
            cout<<total-1<<"\n";
        }



    }
    return 0;
}