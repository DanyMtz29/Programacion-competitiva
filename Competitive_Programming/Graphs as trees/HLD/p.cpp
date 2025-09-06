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
int parent[MAXN], sz[MAXN], depth[MAXN];
int n,queries;
 
//Estructuras para el HLD
int heavy[MAXN], pos[MAXN], baseArr[MAXN], head[MAXN], currPos;

// --- Empieza adición HLD/LCA ---
const int LOG = 20;
int up[MAXN][LOG]; // tabla de ancestros para LCA

int dfs(int x, int par){
    parent[x] = par;//Padre del nodo
    depth[x] = depth[par]+1; // Profundidad del nodo
    sz[x] = 1;//Tamanio del sub arbol sumado mas lo de sus hijos
 
    //Para el HLD
    heavy[x] = -1; //Hijo mas pesado de mi nodo
    int maxChild = 0;//Maximo peso del hijo mas pesado
 
    for( int y : nodes[x].nbr ){
        if( y==par ) continue;
 
        sz[x] += dfs(y,x);//Procesar arbol del hijo
        //Buscando el hijo mas pesado de mi nodo
        if( sz[y] > maxChild ){
            heavy[x] = y;
            maxChild = sz[y];
        }
    }
    return sz[x];
}

void buildLCA(){
    // up[v][0] = parent[v]
    for(int v=1; v<=n; ++v) up[v][0] = parent[v];
    for(int j=1; j<LOG; ++j){
        for(int v=1; v<=n; ++v){
            int mid = up[v][j-1];
            up[v][j] = (mid ? up[mid][j-1] : 0);
        }
    }
}

int lca(int a, int b){
    if(a==b) return a;
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    for(int j=0;j<LOG;j++){
        if(diff & (1<<j)) a = up[a][j];
    }
    if(a==b) return a;
    for(int j=LOG-1;j>=0;j--){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return parent[a];
}

// pathUp: máximo en el camino u -> anc (excluyendo anc), asume anc es ancestro de u
int pathUp(int u, int anc, struct Segment &st); // forward decl
// --- Termina adición HLD/LCA ---

//Funcion para descomponer por cadenas
void decompose(int x, int h){
    head[x] = h;//Establecemos el head a este nodo
    pos[x] = currPos;//Posicion en cuanto al arreglo base
    baseArr[currPos] = nodes[x].val; //Valor en el arreglo base 
    currPos++;
 
    //Primero el heavy child
    if( heavy[x]!=-1 ) decompose(heavy[x],h); //Cadena con mismo head
 
    //Procesar hijos ligeros
    for( int y : nodes[x].nbr ){
        if( y == parent[x] ) continue;
        if( y == heavy[x] ) continue;
        decompose(y,y);//Crea una nueva cadena
    }
}
 
struct Segment{
    vi st;
    int sz;
    const int NEG = -1e18;
 
    void init(int _n){
        this->sz = _n;
        this->st.assign(4*_n, NEG);
    }
 
    void build(int node, int s, int e, int* a){
        if( s==e ){st[node] = a[s];return;}
        int m = (s+e)>>1;
        build( node<<1,s,m,a);
        build( node<<1|1,m+1,e,a);
        st[node] = max( st[node<<1], st[node<<1|1] );
    }
 
    int qry(int node, int s, int e, int l, int r){
        if( s > r || e < l ) return NEG;
        if( s>=l && e<=r ) return st[node];
        int m = (s+e)>>1;
        return max( qry(node<<1,s,m,l,r), qry(node<<1|1,m+1,e,l,r));
    }
 
    void upd(int node, int s, int e, int idx, int val){
        if( s==e ){st[node] = val;return;}
        int m = (s+e)>>1;
        if( idx<=m ) upd(node<<1, s,m,idx,val);
        else upd(node<<1|1, m+1,e,idx,val);
        st[node] = max(st[node<<1], st[node<<1|1]);
    }
};

// --- Implementación de pathUp y qryPath usando LCA ---
// pathUp: máximo en u -> anc (excluye anc). Usa optimizaciones:
//  - si head[u] == u (cadena de 1), compara directamente nodes[u].val
//  - si head[u] está por encima de anc, consulta toda la cadena: pos[head[u]]..pos[u]
//  - si parte de la cadena llega hasta anc, consulta pos[anc]+1..pos[u] y rompe
int pathUp(int u, int anc, Segment &st){
    int res = -1;
    while(u != anc){
        if(head[u] == u){
            // cadena de tamaño 1 (head es el propio nodo)
            res = max(res, (int)nodes[u].val);
            u = parent[u];
        } else if( depth[ head[u] ] > depth[ anc ] ){
            // la cabeza está estrictamente por debajo de anc -> podemos tomar toda la cadena
            int h = head[u];
            res = max(res, st.qry(1,1,n,pos[h], pos[u]));
            u = parent[h];
        } else {
            // la cabeza está por encima o igual a anc; necesitamos solo el segmento desde anc+1 hasta u
            int l = pos[anc] + 1;
            int r = pos[u];
            if(l <= r) res = max(res, st.qry(1,1,n,l, r));
            break;
        }
    }
    return res;
}

int qryPath(int a, int b, Segment& st){
    int L = lca(a,b);
    int r1 = pathUp(a, L, st);
    int r2 = pathUp(b, L, st);
    int ans = max( max(r1, r2), (int)nodes[L].val );
    return ans;
}
// ------------------------------------------------------------------

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cin>>n>>queries;
        //leyendo valores de los nodos
        for( int i = 1; i <= n ; i++ )
            cin>>nodes[i].val;
        
        //Leyendo aristas del arbol
        for( int i = 0; i < n-1; i++ ){
            int u,v;
            cin>>u>>v;
            nodes[u].nbr.pb(v);
            nodes[v].nbr.pb(u);
        }
 
        //Inicializaciones
        for( int i = 1; i <=n ; i++ ) heavy[i]=-1;
        
        //Llenando size, heavy, parent y depth
        depth[0]=0;
        dfs(1,0);

        // build LCA table (parte del HLD/preproceso)
        buildLCA();
 
        //Llenando baseArr, pos y head
        currPos = 1;
        decompose(1,1);
 
        //Segment tree
        Segment st;
        st.init(n);
        st.build(1,1,n,baseArr);
 
         // procesar queries
        while( queries-- ){
            int type;
            cin>>type;
            if( type == 1 ){//Actualizar en el segment tree
                int s, x;
                cin>>s>>x;
                st.upd(1,1,n,pos[s],x);
                nodes[s].val = x; // mantener valor en nodes también
            } else {//Query path sobre segment tree
                int a, b;
                cin>>a>>b;
                int ans = qryPath(a, b, st);
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
