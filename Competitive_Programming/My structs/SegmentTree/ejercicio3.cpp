#include<bits/stdc++.h>
using namespace std;

struct segmentTree{
    int n;
    vector<int> st;
    void init(int n){
        this->n=n;
        this->st.resize(4*n,0);
    }
    int build(int start, int ending, int currentNode, vector<int>& v){
        if(start==ending){
            st[currentNode] = v[start];
            return 0;
        }
        int mid=(start+ending)/2;
        int b1= build(start,mid,currentNode*2+1,v);
        int b2= build(mid+1,ending,currentNode*2+2,v);
        int m=max(b1,b2);
        if(m%2==0) st[currentNode] = st[currentNode*2+1]|st[currentNode*2+2];
        else st[currentNode] =  st[currentNode*2+1]^st[currentNode*2+2];
        return ++m;
    }
    void build(vector<int>& v){
        build(0,this->n-1, 0, v);
    }
    int update(int start, int ending, int node, int index, int val){
        if(start==ending){
            st[node] =val;
            return 0;
        }
        int mid=(start+ending)/2;
        int m=0;
        if(index<=mid) m=update(start, mid, node*2+1,index,val);
        else m=update(mid+1, ending, node*2+2,index,val);
        
        if(m%2==0) st[node] = st[node*2+1]|st[node*2+2];
        else st[node] = st[node*2+1]^st[node*2+2];
        return ++m;
    }
    void update(int index,int val){
        update(0, this->n-1,0,index,val);
    }
    int top(){
        return st[0];
    }
};

void solve(int n, vector<int>a, vector<vector<int>> queries){
    //vector<int> res(n);
    segmentTree st;
    st.init(a.size());
    st.build(a);
    for(int i=0;i<n;i++){
        st.update(queries[i][0]-1,queries[i][1]);
        //res[i] = st.top();
        cout<<st.top()<<endl;
    }
}

int main(){
    int n, t, l,r;
    vector<vector<int>> queries;
    vector<int> vec;
    cin>>n;
    cin>>t;
    int s = pow(2,n);
    vec.resize(s);
    for(int i=0;i<s;i++) cin>>vec[i];
    
    queries.resize(t);
    for(int i=0;i<t;i++){
        cin>>l;cin>>r;
        queries[i]=vector<int>{l,r};
    }
    solve(t,vec,queries);
    return 0;
}