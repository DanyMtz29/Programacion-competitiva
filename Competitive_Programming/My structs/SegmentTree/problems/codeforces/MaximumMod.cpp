//No me acuerdo del link
#include <bits/stdc++.h>

#define int long long int
#define vec vector<int>

using namespace std;

struct SegmentTree{
    
    int n;
    vec st;

    void init( int n ){
        this->n = n;
        this->st.resize( 4*n, 0 );
    }

    void build( int s, int e, int node, vec& arr ){
        if( s==e ){
            st[ node ] = arr[s];
            return;
        }

        int mid = ( s + e ) / 2;

        build( s, mid, node*2+1, arr );
        build( mid+1, e, node*2+2, arr );

        st[ node ] = gcd( st[ node*2+1 ], st[ node*2+2 ] ); // I keep the gcd of the subs

    }

    void build(vec& arr){
        build( 0, n-1, 0, arr);
    }

    int query( int s, int e, int l, int r, int node ){
        if( s > r || e < l) return 0;

        if( s >= l && e <= r ){
            return st[ node ]; 
        }

        int mid = ( s + e ) / 2;
        int q1 = query( s, mid, l, r, node*2+1 );
        int q2 = query( mid+1, e, l, r, node*2+2 );

        return gcd( q1, q2 );
    }

    int query( int l, int r ){
        return query( 0, n-1, l, r, 0);
    }

    int gcd( int a, int b ){
        if ( b==0 ){
            return a;
        }else{
            return gcd( b, a%b );
        }
    }

};

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;//Cases
    while( T-- ){

        int n, q;
        cin >> n; //Size array

        cin >> q; // Queries

        int prev = 0; // Variable to store the array

        int x;

        vec prefixSub(n-1); // minus 1 because always keep pairs

        if( n>1 ){
            for( int i = 0; i < n; i++ ){
                if( i>0 ){
                    cin>>x;
                    prefixSub[ i-1 ] = abs(prev-x);  
                    prev = x;
                }else{
                    cin>>prev;
                }
            }
            n--;
        }else{
            prefixSub.resize(n);
            cin>>prefixSub[0];
        }

        SegmentTree st;
        st.init( n );
        st.build( prefixSub );

        int l,r;
        while( q-- ){
            cin>>l>>r;
            if(l==r) cout<<"0 ";
            else{
                r-=2;
                l--;
                cout<<st.query(l,r)<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}