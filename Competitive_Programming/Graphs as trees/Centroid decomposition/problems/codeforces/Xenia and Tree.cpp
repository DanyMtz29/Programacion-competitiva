
#include <bits/stdc++.h>
using namespace std;
#define INFS 1e9

const int MAXN = 100005;

struct node{
    vector<int> nbr;
};

int n,q;
node nodes[MAXN];

//Variables para el algoritmo
int sz;
int subtree_sz[MAXN], vis[MAXN], par[MAXN];
node centroid_tree[MAXN];

//Variables of problem
int best[MAXN];
vector<pair<int,int>> up[MAXN];

//DFS, llenado del tamanio de cada subarbol
void dfs(int x, int p){
    sz++;
    subtree_sz[x] = 1;
    for( auto const& y: nodes[x].nbr ){
        if( y != p && !vis[y]){
            dfs( y, x);
            subtree_sz[x]+=subtree_sz[y];
        }
    }
}

int getCentroid(int x, int p){
    bool is_centroid = true;
    int heavy_child = -1;
    for( const auto& y : nodes[x].nbr ){
        if( y != p  && !vis[y]){
            if( subtree_sz[y] > sz/2 )
                is_centroid = false;
            if( heavy_child == -1 || subtree_sz[y] > subtree_sz[heavy_child] )
                heavy_child = y;
        }
    }

    //Si es centroid y su tamanio de sub arbol es menor que la mitad de total de nodos, es un centrod
    //Caso contrario, se prueba con el hijo mas pesado para ver si es centroid
    return (is_centroid && sz - subtree_sz[x] <= sz/2) ? x : getCentroid(heavy_child, x);
}

void fillUp(int x, int par,int d, int cent){
    up[x].push_back({cent,d});
    for( const auto& y:nodes[x].nbr ){
        if( y != par && !vis[y] ){
            fillUp(y,x,d+1,cent);
        }
    }
}

//Algoritmo centroid decomposition
int decompose_tree(int x){
    sz = 0;
    dfs(x,-1);
    int cend_tree = getCentroid(x,-1);
    fillUp(cend_tree, -1, 0, cend_tree);
    vis[cend_tree] = 1;
    for( auto const& y: nodes[cend_tree].nbr ){
        if( !vis[y] ){
            int cend_subtree = decompose_tree(y);
            //Formacion del nuevo grafo
            centroid_tree[cend_tree].nbr.push_back(cend_subtree);
            centroid_tree[cend_subtree].nbr.push_back(cend_tree);
            //Padre directo delcentroide
            par[cend_subtree] = cend_tree;
        }
    }
    return cend_tree;
}

void upd(int node){
    for( const auto& pr: up[node] ){
        int child_centroid = pr.first;
        int distance_centroid = pr.second;
        best[child_centroid] = min( best[child_centroid],distance_centroid );
    }
}

int qry(int node){
    int ans = INFS;
    for( const auto& pr: up[node] ){
        int child_centroid = pr.first;
        int distance_centroid = pr.second;
        ans = min( ans, best[child_centroid] + distance_centroid );
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    cin>>n>>q;
    for( int i = 0; i <= n; i++ ){
        vis[i] = 0;
        par[i] = -1;
        best[i] = INFS;
    }
    
    for( int i = 0; i < n-1; i++ ){
        int u,v;cin>>u>>v;
        nodes[u].nbr.push_back(v);
        nodes[v].nbr.push_back(u);
    }

    //cout<<"Arbol de centroides\n";
    int centroid = decompose_tree(1);
    //show(centroid,-1);

    best[1] = 0;
    upd(1);

    while( q-- ){
        int opt, nd;
        cin>>opt>>nd;
        if( opt==2 ){
            cout<<qry(nd)<<"\n";
        }else{
            best[nd] = 0;
            upd(nd);
        }
    }

    return 0;
}
/*
Con este ejemplo inicia en 1
25
1 2
2 0
2 7
2 6
6 9
9 10
10 11
10 12
10 14
14 13
14 15
15 16
15 17
9 20
20 18
20 19
20 23
23 21
23 24
24 25
20 8
8 22
8 5
8 3
3 4
*/