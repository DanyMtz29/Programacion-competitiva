#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n, v)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int, int>
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define pb push_back
#define F first
#define S second
const int MOD = 1e9 + 7;
using namespace std;

struct query{
    int l,r,idx,block,ans;
//Ordenamiento por SQRT decomposition
    bool operator<(query P)const{
        return make_pair(this->block,r) < make_pair(P.block, P.r);
    }
};

void add(umii& mp, int &total, int x){
    mp[x]++;
    if(mp[x] == x) total++;
    else if(mp[x] - 1 == x) total--;
}

void remove(umii& mp, int& total, int x){
    if( mp[x]==x ) total--;
    mp[x]--;
    if(mp[x] == x) total++;
}

bool cmp(const query& a, const query& b){
    return a.idx < b.idx;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        vi a(n);
        umii mp;
        for( int i = 0; i < n; i++ ){
            cin>>a[i];
            mp[ a[i] ] = 0;
        }

        //Aplicando SQRT decomposition - MO's Algorithm
        int root = sqrt(n);
        vector<query> Q( q );
        
        for( int i = 0; i < q; i++ ){
            cin>>Q[i].l>>Q[i].r;
            Q[i].l--;Q[i].r--;
            Q[i].block = Q[i].l / root;
            Q[i].idx = i;
        }

        sort( all(Q) );
        
        //Tecnica de 4 punteros
        int x = 0, y = 0;
        int total = 0;
        for( int i = 0; i < q; i++ ){
            
            //adding y
            while( y <= Q[i].r ){
                add(mp,total, a[y]);
                y++;
            }

            //removing y
            while( y > Q[i].r + 1){
                y--;
                remove(mp,total, a[y]);
            }

            //adding x
            while( x > Q[i].l){
                x--;
                add(mp,total,a[x]);
            }

            //removing x
            while(x < Q[i].l){
                remove(mp,total,a[x]);
                x++;
            }
            Q[i].ans = total;
        }


        sort( all(Q), cmp );
        for( int i = 0; i < q; i++ )
            cout<<Q[i].ans<<"\n";
    }
    return 0;
}