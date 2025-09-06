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

int n,m,posx,posy,tx,ty,movs;
vvi matriz;
vvi vis;
vector<string> dir;
int posFI, posFJ;
vvi dist;

void dijkstra(){
    priority_queue<pair<int, pi>, vector<pair<int,pi>>, greater<pair<int,pi>>> pq;
    pq.push({0,{posx,posy}});

    while( !pq.empty() ){
        int curDist = pq.top().F;
        int x = pq.top().S.F;
        int y = pq.top().S.S;
        pq.pop();

        if( vis[x][y] ) continue;

        vis[x][y] = 1;

        for( string s: dir ){
            int sz = s.size();
            int tempx = x;
            int tempy = y;
            int cont = 0;
            for( int i = 0 ; i < sz; i++ ){
                if( s[i] == 'U' && tempx-1 >= 0 && matriz[tempx-1][tempy] != -1){
                    tempx--;
                    cont++;
                }
                if( s[i] == 'D' && tempx+1 < n && matriz[tempx+1][tempy] != -1){
                    tempx++;
                    cont++;
                }
                if( s[i] == 'L' && tempy-1 >= 0 && matriz[tempx][tempy-1] != -1){
                    tempy--;
                    cont++;
                }
                if( s[i] == 'R' && tempy+1 < m && matriz[tempx][tempy+1] != -1){
                    tempy++;
                    cont++;
                }
            }//Termine con ese movimiento
            if( dist[tempx][tempy] > curDist + cont ){
                dist[tempx][tempy] = curDist + cont;
                pq.push({ dist[tempx][tempy] , {tempx, tempy}});
            }
        }
    }
    if( dist[tx][ty] != INT_MAX ) cout<<dist[tx][ty];
    else cout<<"-1";

    cout<<"\n";
}

void bfs(){
    queue<pi> q;
    q.push({posx,posy});
    vis[posx][posy] = 1;

    while( !q.empty()){
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        for( string s: dir ) {
            int sz = s.size();
            int tempx = x;
            int tempy = y;
            int cont = 0;
            for( int i = 0 ; i < sz; i++ ){
                if( s[i] == 'U' && tempx-1 >= 0 && matriz[tempx-1][tempy] != -1){
                    tempx--;
                    cont++;
                }
                if( s[i] == 'D' && tempx+1 < n && matriz[tempx+1][tempy] != -1){
                    tempx++;
                    cont++;
                }
                if( s[i] == 'L' && tempy-1 >= 0 && matriz[tempx][tempy-1] != -1){
                    tempy--;
                    cont++;
                }
                if( s[i] == 'R' && tempy+1 < m && matriz[tempx][tempy+1] != -1){
                    tempy++;
                    cont++;
                }
            }//Termine con ese movimiento
            matriz[tempx][tempy] = min( matriz[tempx][tempy], matriz[x][y]+cont );
            if( vis[tempx][tempy]==false ){
                vis[tempx][tempy] = true;
                q.push({tempx,tempy});
            }
        }
    }
    if( matriz[tx][ty] != INT_MAX ) cout<<matriz[tx][ty];
    else cout<<"-1";

    cout<<"\n";
}

void solve() {
    cin>>n>>m;
    
    //Llenado de matrix
    matriz.resize(n,vi(m));
    vis.resize(n,vi(m, false));
    dist.resize(n,vi(m,INT_MAX));
    for( int i = 0 ; i < n; i++ ) {
        string aux; cin>>aux;
        //cout<<"Aux: "<<aux<<"\n";
        for( int j = 0 ; j < m ; j++){
            if( aux[j]=='0' ) matriz[i][j] = INT_MAX;
            else matriz[i][j] = -1;
        }
        // for( int j = 0; j < m ; j++){
        //     char x;cin>>x;
        //     if( x == '0' ) matriz[i][j] = INT_MAX;
        //     else matriz[i][j] = -1;
        // }
    }
    
    //Posiciones de entrada y salida
    cin>>posx>>posy>>tx>>ty;

    // cout<<"Posx: "<<posx<<"\n";
    // cout<<"Posy: "<<posy<<"\n";
    // cout<<"tx: "<<tx<<"\n";
    // cout<<"ty: "<<ty<<"\n";

    //Total de movimientos
    cin>>movs;

    //Llenado de movimientos
    dir.resize(movs);
    for( int i = 0 ; i < movs ; i++){
        cin>>dir[i];
    }

    matriz[posx][posy] = 0;
    dijkstra();
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}