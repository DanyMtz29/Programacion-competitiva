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

const int MAXN = 200105;
int n,m;

struct node{
    int value;
    map<int,int> nbr;
    map<int,int> neighbors;
};

node nodes[MAXN];
vector<pi> aux[MAXN];
int par[MAXN];
int totalCost;

//Precalculation of the total cost
void dfs(int node, int parent){
    par[node] = parent;

    for( const auto& pr: nodes[node].neighbors ){
        int nbrNode = pr.F;
        int cost = pr.S;
        
        int nbrValue = nodes[nbrNode].value;

        if( nodes[node].value != nbrValue )
            totalCost += cost;

        nodes[node].nbr[ nbrValue ]+=cost;
        
        dfs( nbrNode, node );
    }
}

void enraizar(int node, int par){
    for( const auto& nbr: aux[node] ){
        if( nbr.F == par ) continue;
        nodes[node].neighbors[nbr.F] = nbr.S;
        enraizar( nbr.F, node );
    }
}

void solve(){
    cin>>n>>m;
    totalCost = 0;
    for( int i = 1; i <= n; i++ ){
        cin>>nodes[i].value;
        par[i]=-1;
        aux[i].clear();
        nodes[i].nbr.clear();
        nodes[i].neighbors.clear();
    }

    int initialNode = 1;
    for( int i = 0; i < n-1; i++ ){
        int u,v;
        int ci;
        cin>>u>>v>>ci;
        aux[u].pb({v,ci});
        aux[v].pb({u,ci});
        //nodes[u].neighbors[v] = ci;
    }

    enraizar(1,-1);
    dfs(initialNode, -1);

    while( m-- ){
        int v,x;
        cin>>v>>x;

        node &curNode = nodes[v];
        int curValue = curNode.value;
        //Checando los hijos del nodo
        if( curNode.nbr.count(curValue) ){
            totalCost += curNode.nbr[curValue];
        }
        if( curNode.nbr.count( x ) ){
            totalCost -= curNode.nbr[x];
        }

        //Update from parent to children
        if( par[v] == -1 ){
            curNode.value = x;
            cout<<totalCost<<"\n";
            continue;
        }

        node &parNode = nodes[ par[v] ];//Padre
        int cost = parNode.neighbors.find( v )->S;//Costo de padre al hijo
        
        parNode.nbr[curValue] -= cost;
        //Eliminar para no saturar el mapa
        if( parNode.nbr[curValue] == 0 ) parNode.nbr.erase(curValue);

        parNode.nbr[x] += cost;

        if( parNode.value == curValue ) totalCost += cost ;

        if( parNode.value == x ) totalCost -= cost;

        curNode.value = x;
        cout<<totalCost<<"\n";
    }

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
