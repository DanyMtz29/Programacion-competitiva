#include <bits/stdc++.h>

using namespace std;

bool dfs(int origen, unordered_map<int,vector<int>>& nodes, vector<bool>& visits){
    if(visits[origen]) return false;
    
    visits[origen] =true;
    for(int node: nodes[origen]){
        if(!dfs(node, nodes, visits)) return false;
    }
    return true;
}

bool solve(vector<vector<int>>& m){
    unordered_map<int,vector<int>> nodes;
    for(vector<int>& v: m){
        int origen = v[0];
        int destino = v[1];
        if(nodes.find(origen)!=nodes.end()){
            nodes[origen].push_back(destino);
        }else{
            nodes[origen] = vector<int>{destino};
        }
    }
    vector<bool> visits (m.size(),false);
    for(auto& p: nodes){
        if(!dfs(p.first,nodes,visits)) return false;
    }
    return true;
}

int main(){

    return 0;
}