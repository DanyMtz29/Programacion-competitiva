#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
void solucionCuantica();

const int MAX = 500005;

int ans;

bool dfs(vector< vector< tuple <int,int,int> > >& graph, vector<int>& visit, int node, int parentProgram, int N, vector<int>& dp) {
  if(visit[node]==1) return false; // Evitar ciclo
  
  if(node==N) return true; // Llego al destino

  if(dp[node] != INT_MAX){
    if(dp[node] != -1){
      ans += dp[node];
      return true;
    }else{
      return false;
    }
  }

  visit[node]=1;//Esta haciendo recorrido
  bool change = false;

  //Recorrer vecinos
  vector<tuple<int,int,int>> vec = graph[node];  
  for(tuple<int,int,int> t: vec){

    //auto[destino, cambio, programa] = t;
    int destino, cambio, programa;
    tie(destino, cambio, programa) = t;

    if(parentProgram<programa){
        if( dfs(graph,visit, destino, programa, N, dp) ) {
          if(cambio) change = true;
          else change = false;

          ans += cambio;
          dp[node] = min(dp[node],ans);
          ans -=cambio;
        }
    }
  }

  visit[node] = 2; //Termino recorrido

  if(dp[node] != INT_MAX){
    if(change) ans += 1;
    return true;
  }

  dp[node] = -1;//No hubo camino

  return false;
}

int main() {

  int T;
  cin>>T;

  while(T--){
    int N, M;
    cin>>N>>M;
    //Grafo. Vecinos con su cambio respectivamente, programa
    vector< vector< tuple <int,int,int> > > nodes(N+1, vector<tuple<int,int,int>>());

    int nodoInicio, nodoFin, programa;

    ans = INT_MAX;

    for(int i=0; i<M; i++){
      cin>>nodoInicio>>nodoFin>>programa;

      //Almacenando grafo
      //Ej: 2                        1              10
      //    Nodo inicio           nodoFin, cambio, programa
      nodes[nodoInicio].push_back( {nodoFin, 0, programa });
      //Almacenando nodo con cambio
      nodes[nodoFin].push_back( {nodoInicio, 1, programa });

    }

    /*
    for(int i = 1;i<=N ; i++){
      vector< tuple< int,int,int > > vecinos = nodes[i];
      cout<<"Nodo: "<<i<<endl;
      for( tuple <int,int,int> t : vecinos ){
        int destino, cambio, progr;
        tie(destino, cambio, progr) = t;  
        cout<<"Destino: "<<destino<<", cambio: "<<cambio<<", programa: "<<progr<<endl;
      }
      cout<<endl;
    }
*/
  
    //int res = INT_MAX;

    ans = 0;

    vector<int> dp(N+1, INT_MAX);//Dp de caminos
    vector<int> visit(N+1, 0);//Dp para evitar ciclos
    visit[1] = 1;

    vector< tuple<int,int,int> > vec = nodes[1];

    for(tuple <int,int,int>& t: vec){//Por cada camino del nodo 1

      int destino, cambio, progr;
      //auto[destino, cambio, programa] = t;
      tie(destino, cambio, progr) = t;

      if( dfs(nodes, visit, destino, progr, N, dp) ) {
          ans += cambio;
          dp[1] = min( dp[1], ans );
          //res = min(ans,res);   
          ans-=cambio;
      }
    }

    if(dp[1]==INT_MAX){
      cout<<"-1"<<endl;
    }else{
      cout<<dp[1]<<endl;
    }

  }
 
  return 0;
}

