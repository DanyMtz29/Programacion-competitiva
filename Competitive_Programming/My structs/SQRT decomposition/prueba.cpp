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
const int MOD=1e9+7;
using namespace std;
#define maxn 1000001
long long block,total;
 
bool comp(const vector<int>&v1, const vector<int> &v2){
    int x=(v1[0]+1)/block,y=(v2[0]+1)/block;
    if(x==y){
        return v1[1]<v2[1];
    }
    return x<y;
}
 
void add(int x,int val,vector<int>&cnt){
    total-=(long long)cnt[x]*(long long)cnt[x]*(long long)x;
    cnt[x]+=val;
    total+=(long long)cnt[x]*(long long )cnt[x]*(long long)x;
}
 
vector<long long> solve(int n,int m, vector<int> a, vector<vector<int>> query){
    block=sqrt(n);
    total=0;
    vector<vector<int>>vec;
    for(int i=0;i<m;i++){
        vec.push_back({query[i][0]-1,query[i][1]-1,i});
    }
    sort(vec.begin(),vec.end(),comp);
 
    vector<long long>ans(m);
    vector<int>cnt(maxn);
    int curl=0,curr=0;
 
    for(int i=0;i<m;i++){
        int l=vec[i][0],r=vec[i][1];
        while(curl<l){
            add(a[curl],-1,cnt);
            curl++;
        }
        while(curl>l){
            add(a[curl-1],1,cnt);
            curl--;
        }
        while(curr<=r){
            add(a[curr],1,cnt);
            curr++;
        }
        while(curr>r+1){
            add(a[curr-1],-1,cnt);
            curr--;
        }
        ans[vec[i][2]]=total;
    }
    return ans;
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        vi a(n);
        forN(n,a);
        vvi qry(m);
        for( int i = 0; i < m; i++ ){
            int l,r;
            cin>>l>>r;
            qry[i] = {l,r};
        }
        vi ans = solve(n,m,a,qry);
        for( auto x: ans )
            cout<<x<<"\n";    
    }
    return 0;
}