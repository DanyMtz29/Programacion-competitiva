#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int dfs(int origen, int parent, vector<pair<int,int>> graph[], lli& ans, int totalNodes){
    int currentSize = 1;
    for(auto& p: graph[origen]){
        int destino = p.first;
        int peso = p.second;

        if(destino==parent) continue;

        int childTreeSize = dfs(destino, origen, graph, ans, totalNodes);

        int contribution = 2 * min(childTreeSize,totalNodes-childTreeSize) * peso;

        ans+=contribution;
        currentSize += childTreeSize;
    }
    return currentSize;
}

int main(){
    int T, N;
    cin>>T;
    int t = 1;
    vector<pair<int,int>> graph[100005];
    while(t<=T){
        cin>>N;
        for(int i=1;i<=N;i++) graph[i].clear();
        //u: Arista origen
        //v: Arista destino
        //w: Peso
        int u,v,w;
        for(int i=1;i<N;i++){
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        lli ans = 0;
        dfs(1,-1,graph,ans,N);
        cout<<"Case #"<<t++<<": "<<ans<<endl;
    }
    return 0;
}