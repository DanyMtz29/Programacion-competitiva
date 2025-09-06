#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct node{
    vector<int> nbr;
};

int n;
node nodes[MAXN];

//Variables para el algoritmo
int sz;
int subtree_sz[MAXN], vis[MAXN], par[MAXN];
node centroid_tree[MAXN];

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

//Algoritmo centroid decomposition
int decompose_tree(int x){
    sz = 0;
    dfs(x,-1);
    int cend_tree = getCentroid(x,-1);
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

void show(int x, int p){
    cout<<"Nodo "<<x<<" tiene de hijos: \n";
    for( auto const& y: centroid_tree[x].nbr ){
        if( y != p){
            cout<<y<<" ";
        }
    }
    cout<<"\n";
    for( auto const& y: centroid_tree[x].nbr ){
        if( y != p){
            show(y,x);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    cin>>n;
    for( int i = 0; i <= n; i++ ){
        vis[i] = 0;
        par[i] = -1;
    }
    
    for( int i = 0; i < n; i++ ){
        int u,v;cin>>u>>v;
        nodes[u].nbr.push_back(v);
        nodes[v].nbr.push_back(u);
    }

    int centroid = decompose_tree(0);
    show(centroid,-1);

    return 0;
}
/*
Con este ejemplo inicia en 0
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