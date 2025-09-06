#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, unordered_map<int,vector<int>>& edges, int parent){
    vector<int> v = edges[node];
    int sz = v.size();

    if(sz==1){
        edges.erase(node);
        return true;
    }

    vector<int> r;

    for(int i=0;i<sz;i++){
        if(edges[node][i]==parent || edges[node][i] == -1) continue;

        if(!dfs(edges[node][i],edges,node)){
            r.push_back(edges[node][i]);
        }
    }
    edges[node] = r;
    return false;

}


vector<int> solve(int n, vector<vector<int>>& edges){
    //Grafo de nodos
    unordered_map<int,vector<int>> mp;

    //Rellenando el mapa bidireccional
    int mx = 0;
    for(vector<int>& v: edges){
        if( mp.find(v[0]) != mp.end()){
            mp[v[0]].push_back(v[1]);
        }else{
            mp[v[0]] = vector<int>{v[1]};
            mx = v[0];
        }

        if( mp.find(v[1]) != mp.end()){
            mp[v[1]].push_back(v[0]);
        }else{
            mp[v[1]] = vector<int>{v[0]};
            mx = v[0];
        }
    }

    //eliminacion de nodos
    while(mp.size()>3){
        for(auto& p: mp){
            vector<int> r;
            if(p.second.size()>2){
                !dfs(p.first,mp,-1);
            }
        }
    }
    vector<int> res;
    for(auto& p: mp){
        res.push_back(p.first);
    }
    return res;
}

int main(){
    vector<vector<int>> v = { {1,0}, {1,2}, {1,3} };
    int n = 4;
    //vector<vector<int>> v = { {3,0}, {3,1}, {3,2}, {3,4} };
    vector<int> r = solve( n, v );
    copy( r.begin(), r.end(), ostream_iterator<int> ( cout, "|" ) );
    return 0;
}