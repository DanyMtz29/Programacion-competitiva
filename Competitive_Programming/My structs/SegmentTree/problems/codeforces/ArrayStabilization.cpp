//https://codeforces.com/problemset/problem/1547/F
#include <bits/stdc++.h>
using namespace std;

struct segmentTree{

    int left, right, val;
    segmentTree *nodeLeft  = nullptr;
    segmentTree *nodeRight  = nullptr;

    void init(vector<int>& arr, int start, int ending ){
        this->left = start;
        this->right = ending;

        if( left != right){
            int mid = ( left + right ) / 2;

            if( left<=mid ){
                nodeLeft = new segmentTree;
                nodeLeft->init( arr, left, mid );
            }

            if( right >= mid+1 ){
                nodeRight = new segmentTree;
                nodeRight->init( arr, mid+1, right );
            }
            this-> val = gcd( nodeLeft->val, nodeRight->val );

        }else{
            this->val = arr[this->left];
        }
    }

    int query( int start, int end ){
        if( start < 0 || end < 0) return 0; 

        if( start == this->left && end == this->right){
            return this->val;
        }

        int mid = ( this->left + this->right ) / 2;

        if( start >= mid+1 ){

            return this->nodeRight->query( start, end );
        } else if( end <= mid ){

            return this->nodeLeft->query( start, end );
        } else{

            int q1 = this->nodeLeft->query( start, mid );
            int q2 = this->nodeRight->query( mid+1, end );
            return gcd( q1, q2 );
        }
        
    }

    int gcd( int a, int b ){
        return ( b==0 )? a : gcd( b, a%b ); 
    }

};

bool check(int mid, int N, segmentTree& st){
    int k = mid+1;
    
    int j = 0;
    int gcdPrev = -1;

    for(int i=0;i<N;i++){
        if( i+1-j < k) continue;

        int GCD = st.query( j, i );

        if( gcdPrev == -1 ){ 
            gcdPrev = GCD;
            j++;
        }else{
            if(gcdPrev != GCD){
                return false;
            }
            j++;
        }

        if(j == N/2) break;

    }

    return true; 
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int N; cin>>N;
        vector<int> arr(N*2);
        for(int i=0;i<N;i++){
            cin>>arr[i];
            arr[i+N] = arr[i];
        }

        segmentTree st;

        N*=2; 

        st.init( arr, 0, N-1 );

        int l = 0;

        int r = N-1;

        int ans = N-1;
        while(l<=r){
            int mid = (l+r)/2;
            
            bool isEqual = check( mid, N , st );

            if(isEqual){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}