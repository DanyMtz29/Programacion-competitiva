//NO ha salido
//https://codeforces.com/problemset/problem/1042/D
#include <bits/stdc++.h>

#define vec vector<int>

using namespace std;

struct SegmentTree{

    int n;
    vec st;

    void init( int n ){
        this->n = n;
        this->st.resize( 4*n, 0 );
    }

    void build( int s, int e, int currentNode, vec& arr ){
        if( s == e ){
            st[ currentNode ] = arr[s]; 
            return;
        }

        int mid = ( s + e ) / 2;
        build( s, mid, currentNode*2+1, arr ); 
        build( mid+1, e, currentNode*2+2, arr ); 

        st[currentNode] = st[currentNode*2+1] + st[currentNode*2+2];
    }

    int query( int s, int e, int l, int r , int node){
        if( s > r || e < l ){ // No overlap
            return 0;
        }

        if( s >= l && e <= r ){ //Complete overlap
            return st[ node ];
        }

        int mid = ( s + e ) / 2;

        int q1 = query( s, mid, l, r, node*2+1 );
        int q2 = query( mid+1, e, l, r, node*2+2 );

        return q1 + q2;
    }

    int query( int left, int right ){
        return query( 0, n-1, left, right, 0);
    }

    void build( vec& arr ){
        build( 0, n-1, 0, arr );
    }
};

void search( int l, int r, int &ans, SegmentTree &st, int t){
    if( l == r ){
        //if( st.query( l, r ) < t ) ans++;
        return;
    }
    int mid = ( l + r ) / 2;

    int q = st.query( l, r );
    cout<< "L: "<<l<<", R: "<<r<<endl; 
    cout<<"Q: "<<q<<endl;

    if( q < t ) ans++;

    search( l, mid, ans, st, t );
    search( mid+1, r, ans, st, t );
}

int main(){
    int n, t;
    cin>>n;
    cin>>t;

    vec v(n);

    int ans = 0;

    for( int i = 0; i < n; i++ ){
        cin>>v[i];
        //if(v[i]<t) ans++;
    }

    SegmentTree st;
    st.init( n );
    st.build( v );

    /*
    0-4
    0-3, 1-4
    0-2, 1-3, 2-4
    0-1, 1-2, 2-3 3-4
    */

    int r = n-1;
    int l = 0;
    search( l , r , ans, st, t );

    cout<<ans<<endl;

    return 0;
}