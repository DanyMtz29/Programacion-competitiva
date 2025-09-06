#include <bits/stdc++.h>
using namespace std;
const int B = 2e5 + 100;
int n;
int col[B];
long long costt = 0;
vector <pair <int,int> > reb[B];
bool was[B];
map <int,long long> cnt[B];
int pred[B];
long long zn[B];
void dfs(int v) {
  was[v] = true;
  for(auto u:reb[v]) {
    if(was[u.first]) {
      pred[v] = u.first;
      continue;
    }
    if(col[v] != col[u.first]) costt+=u.second;
    dfs(u.first);
    zn[u.first] = u.second;
    cnt[v][col[u.first]]+=zn[u.first];
  }
}
void update(int v,int x) {
  if(v != 1) {
    cnt[pred[v]][col[v]]-=zn[v];
    if(col[pred[v]] == col[v]) costt+=zn[v];
    cnt[pred[v]][x]+=zn[v];
    if(col[pred[v]] == x) costt-=zn[v];
  }
  else {
      
  }
  costt+=cnt[v][col[v]];
  costt-=cnt[v][x];
  col[v] = x;
}
void clr() {
  for(int i = 1;i <= n;i++) {
    reb[i].clear();
    was[i] = false;
    cnt[i].clear();
    zn[i] = 0;
  }
  costt = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  int t = 1;
  //cin >> t;
  while(t--) {
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> col[i];
    for(int i = 1; i < n; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      reb[v].push_back({u,c});
      reb[u].push_back({v,c});
    }
    dfs(1);
    while(q--) {
      int pos,x;
      cin >> pos >> x;
      update(pos,x);
      cout << costt << "\n";
    }
    clr();
  }
}