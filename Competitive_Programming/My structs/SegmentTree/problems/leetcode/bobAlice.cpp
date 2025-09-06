//https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/
#include <bits/stdc++.h>

#define vec vector<int>

using namespace std;

struct SegmentTree{
    int n;
    vector<int> st;

    void init(int tam){
        this->n = tam;
        st.resize(4*n,0);
    }

    void build( int s, int e, int currentNode, vec& arr ){
        if( s == e ){
            st[currentNode] = s;
            return;
        }

        int mid = ( s + e ) / 2;

        build( s, mid, currentNode*2+1, arr );
        build( mid+1, e, currentNode*2+2, arr );

        if( arr[st[currentNode*2+1]] > arr[st[currentNode*2+2]]){
            st[currentNode] = st[currentNode*2+1];
        }else{
            st[currentNode] = st[currentNode*2+2];
        }
        
    }

    int query(int s, int e, int l, int r, int currentNode, vec& arr){
        if( s > r || e < l ) return -1;

        if( s >= l && e <= r ) return st[currentNode];

        int mid = ( s + e ) / 2;

        int q1 = query( s, mid, l, r, currentNode*2+1, arr );
        int q2 = query( mid+1, e, l, r, currentNode*2+2, arr );

        if( q1==-1 ) return q2;
        if( q2==-1 ) return q1;

        if( arr[q2] > arr[q1]){
            return q2;
        }else{
            return q1;
        }
    }

    int query(int l, int r, vec& arr){
        return query( 0, this->n-1, l, r, 0 , arr);
    }

    void build( vec& arr){
        return build( 0,n-1, 0, arr );
    }

};

vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    
    int sz = heights.size();
    SegmentTree st;
    st.init( sz );
    st.build( heights );

    vec ans( queries.size() );
    int i=0;

    for(vec& q: queries){
        int alice = min( q[0], q[1] );
        int bob = max( q[0], q[1] );


        if( alice==bob || heights[bob] > heights[alice] ){
            ans[i++] = bob;
            continue;
        }

        int find = max( heights[alice], heights[bob] );

        int l = bob;
        int r = sz-1;

        int res = INT_MAX;

        while( l<=r ){
            int mid = ( l+r ) / 2;
            int index = st.query( l, mid , heights );
            
            if( heights[index] > find ){
                res = min( res, index );
                r = mid-1;
            }else{
                l = mid+1; 
            }
        }

        if( res == INT_MAX) ans[i++] = -1;
        else ans[i++] = res;
    }

    return ans;
}

int main(){
    //vec heights = {6,4,8,5,2,7};
    vec heights = {5,3,8,2,6,1,4,6};
    vector< vec > queries ={{0,7},{3,5}, {5,2}, {3,0}, {1,6}};

    vector<int> ans = leftmostBuildingQueries( heights, queries );
    cout<<"Answer"<<endl;
    copy( ans.begin(), ans.end(), ostream_iterator<int> (cout, "|") );

    return 0;
}