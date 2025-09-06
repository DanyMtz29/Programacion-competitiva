#include<bits/stdc++.h>
using namespace std;

struct segmentTree{
    int n;
    vector<int> st;
    
    void init(int n){
        this->n = n;
        st.resize(4*n,0);
    }
    
    void build(int start, int ending, int currentNode, vector<int>& vec){
        if(start==ending){
            st[currentNode] = vec[start];
            return;
        }
        int mid = (start+ending)/2;
        build(start,mid,currentNode*2+1,vec);
        build(mid+1,ending,currentNode*2+2,vec);
        st[currentNode] = min(st[currentNode*2+1],st[currentNode*2+2]);
    }
    
    void build(vector<int>& v){
        build(0,this->n-1,0,v);
    }
    
    int query(int start, int ending, int l, int r, int currentNode){
        if(start>r || ending<l) return 0;
        if(start>=l && ending<=r) return st[currentNode];
        int mid = (start+ending)/2;
        int a = query(start,mid,l,r,currentNode*2+1);
        int b = query(mid+1,ending,l,r,currentNode*2+2);
        st[currentNode] = min(st[currentNode*2+1],st[currentNode*2+2]);
    }
    int query(int l, int r){
        return query(0,this->n-1,l,r,0);
    }
    
    void update(int start, int ending, int currentNode, int index, int val){
        if(start==ending){
            st[currentNode] = val;
            return;
        }
        int mid = (start+ending)/2;
        if(index<=mid){
            update(start,mid,currentNode*2+1,index,val);
        }else{
            update(mid+1,ending,currentNode*2+2,index,val);
        }
        st[currentNode] = min(st[currentNode*2+1],st[currentNode*2+2]);
    }
    void update(int index, int val){
        update(0,this->n-1,0,index,val);
    }
};

vector<int> solve(int n, vector<int>arr, vector<vector<int>> queries){
    vector<int> res;
    segmentTree st;
    st.init(n);
    st.build(arr);
    for(vector<int>& vec: queries){
        if(vec[0]==1){
            st.update(vec[1]-1,vec[2]);
        }else{
            
        }
    }
    return res;
}