#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define pb push_back
#define F first
#define S second
#define e "\n"
#define IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

//Constantes

//Estructuras

//Variables
string s;
int b;

void solve(){
    cin>>s>>b;
    int n = s.size();
    s += s;
    int l = 0;
    int r = 0;
    int ans = 0;
    queue<int> q;
    while(r < b){
        if( s[r]=='E' )
            q.push(r);
        r++;
    }

    while( l < n ){
        if( s[l] == 'P' ){
            if( !q.empty() )
                ans += (r - q.front());
        }else{
            q.pop();
            ans += b;
        }

        l++;
        if( s[r] == 'E' ){
            q.push(r);
        }
        r++;
    }
    cout<<ans<<"\n";
}

int32_t main(){
    IO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}