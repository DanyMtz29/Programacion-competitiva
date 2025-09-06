#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

void dfs( vector<vector<int>>& supervisors, vec& groups, int emp, unordered_set<int>& st, vec& totalGroups, int total ){
    bool flag = false;
    if( !st.count( groups[ emp ] ) ){
        st.insert( groups[ emp ] );
        total+=1;
        flag = true;
    }
    totalGroups[ emp ] = total;

    for( int emps : supervisors[ emp ] ){
        dfs( supervisors, groups, emps, st, totalGroups, total);
    }
    if( flag ){
        st.erase( groups[ emp ] );
    }
}

int32_t main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, s; cin>>N;
    vector<vector<int>> supervisors(N+1);
    vec groups( N+1 );
    vec totalGroups( N+1 , 0);
    for( int i = 1; i <= N; i++ ){
        cin>>s;
        supervisors[ s ].push_back( i );
    }

    for( int i = 1; i <=N ; i++ ){
        int g; cin>>g;
        groups[ i ] = g;
    }

    unordered_set<int> st;
    for( int emps : supervisors[0]){
        dfs( supervisors, groups, emps, st, totalGroups, 0);
    }

    for( int i = 1; i <= N; i++ ){
        cout<<totalGroups[i]<<" ";
    }
    cout<<endl;

    return 0;
}