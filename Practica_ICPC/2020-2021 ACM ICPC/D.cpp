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

int n;

void solve(vi &a){
    if( n == 1  ){
        cout<<"N"<<"\n";
        return;
    }

    priority_queue<int, vector<int>, greater<int>> pq(all(a));
    //cout<<"LLega: "<<pq.size()<<"\n";
    int pot = -1;

    int temp = 0;

    while( !pq.empty() ){
        if( pot == -1 ){
            pot = pq.top();
            pq.pop();
        }else if( pq.top() == pot ){
            pq.push(pot+1);
            pq.pop();
            pot = pq.top();
            pq.pop();
        }else{
            temp++;
            if( temp == 2 ){
                cout<<"N"<<"\n";
                return;
            }
            pot = pq.top();
            pq.pop();
        }
    }
    cout<<"Y"<<"\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        cin>>n;
        vi a(n);
        forN(n,a);
        solve(a);
    }
    return 0;
}


/*
1 1 3 3 5
 2   4  5
*/