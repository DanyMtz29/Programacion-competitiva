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
const int MOD=1e9+7;

//Estructuras

//Variables
int n;
vi a;

void fillTable(vi& table, int s, int ed){
    stack<int> st;
    while( s!=ed ){
        while(!st.empty() && a[ st.top() ] <= a[s] ){
            st.pop();
        }
        if( !st.empty() ) table[s] = st.top();

        st.push(s);
        if(s>=ed) s--;
        else s++;
    }


}

void solve(){
    cin>>n;
    a.resize(n+1);
    for( int i = 1; i <= n ; i++ ){
        cin>>a[i];
    }

    //Build left and right monotonic stack
    vi left(n+1,0), right(n+1,n+1);
    fillTable(left,1,n+1);
    fillTable(right, n,0);

    // cout<<"LEFT"<<"\n";
    // for( auto x: left ){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    // cout<<"\nRIGHT"<<"\n";
    // for( auto x: right ){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";

    vector<int> range(n+5);
    pi l, r;
    for( int i = 1 ; i <= n ; i++ ){
        // IZQUIERDA
        if (left[i] == 0) {
            l.F = 1;
            l.S = i - 1;
        } else {
            l.F = (left[i] + i) / 2 + 1;  // floor((L+i)/2) + 1
            l.S = i - 1;
        }


        // DERECHA
        if (right[i] == n + 1) {
            r.F = i + 1;
            r.S = n;
        } else {
            r.F = i + 1;
            r.S = (right[i] + i - 1) / 2; // ceil((R+i)/2) - 1
        }

        if( l.S >= l.F ){
            range[l.F]++;
            range[l.S+1]--;
        }
        if( r.S >= r.F ){
            range[r.F]++;
            range[r.S+1]--;
        }
    }

    int cur = 0;
    for( int i = 1 ; i <= n ; i++ ){
        cur += range[i];
        cout<<cur<<(i==n?"\n":" ");
    }
    cout<<"\n";
}

int32_t main(){
    IO;

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}