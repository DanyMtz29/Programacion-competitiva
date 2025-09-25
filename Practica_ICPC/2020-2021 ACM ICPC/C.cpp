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
const int MAXN = 100005;;

//Estructuras

//Variables
int n, tar;
int arr[MAXN];
int arr2[MAXN];

int lToR(int idx, int* a, deque<pi>& q, bool flag = true){
    int ans = 0;
    int i = idx;
    int it = 1;
    while( it <= n ){
        if(flag && i == n ) i = 0;
        if(!flag && i == -1) i=n-1;
        if( a[i] < tar ){
            if( q.empty() ) return INT_MAX;
            while( !q.empty() ){
                auto top = q.front();
                int resto = tar - a[i];
                if( top.S > resto ){
                    ans += ((it-top.F) * resto);
                    q.pop_front();
                    q.push_front({top.F, top.S-resto});
                    a[i] = tar;
                    break;
                }else{
                    ans += ((it-top.F) * top.S);
                    a[i] += top.S;
                    q.pop_front();
                    if( a[i] == tar ) break;
                }
            }
        }else if( a[i]>tar ){            
            int resto = a[i]-tar;
            a[i] = tar;
            q.push_front({it,resto});
        }

        it++;
        if(flag) i++;
        else i--;
    }
    return ans;
}

int check(int l, int r){
    deque<pi> q;
    int left = lToR(l,arr,q);
    int right = lToR(r,arr2,q,0);
    return min(left,right);
}

void solve(){
    cin >> n;
    int sum = 0;
    vector<int> idxs;
    int mx = -1;
    for( int i = 0 ; i < n ; i++ ) {
        cin>>arr[i];
        arr2[i] = arr[i];
        sum += arr[i];
        
    }
    tar = sum/n;
    
    //Search a valid index

    int l = 0, r=0, carry = 0, it= 1;
    while( it < n){
        int rem = arr[r]-tar;
        carry += rem;
        while( carry<0){
            if( l==0 ) l = n-1;
            else l--;
            rem = arr[l]-tar;
            carry+=rem;
            it++;
        }
        r++;
        it++;
    }
    int L = l;
    l = 0; r=0; carry = 0; it= 1;
    while( it < n){
        int rem = arr[r]-tar;        
        carry += rem;
        while( carry<0){
            l++;
            rem = arr[l]-tar;
            carry+=rem;
            it++;
        }
        if(r == 0 )r=n-1;
        else r--;
        it++;
    }

    int R = l;
    cout<<check(L,R)<<"\n";
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