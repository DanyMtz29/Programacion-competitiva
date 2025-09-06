#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& v, int n){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    bool turn = false; // Alicius

    int cont = 0;
    n = v.size();
    for(int i=0;i<n;i++){
        if(v[i]-cont==1){
            turn = !turn;//Change turn
            cont++;
        }else{
            cout<<((turn)?"Bobius":"Alicius")<<endl;
            return;
        }
    }

    cout<<((turn)?"Bobius":"Alicius")<<endl;
}


int main(){
    //CON ESTO SE SOLUCIONO!!!!!!!!!
    ios::sync_with_stdio(0);
    cin.tie(0);
    //================================================================
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    solve(v, n);

    return 0;
}