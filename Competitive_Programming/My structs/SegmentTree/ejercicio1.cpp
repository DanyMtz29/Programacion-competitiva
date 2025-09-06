#include<bits/stdc++.h>
using namespace std;

struct segmenteTree{
    int n;
    vector<int> st;
    
    void init(int n){
        this->n = n;
        st.resize(4*n,0);
    }
    
    void build(int start, int ending, int currentNode, vector<int>& vec){
        if(start==ending){
            cout<<"CurrentNode: "<<currentNode<<", value: "<<vec[start]<<endl;
            st[currentNode] = vec[start];
            return;
        }
        int mid = (start+ending)/2;
        build(start,mid,currentNode*2+1,vec);
        build(mid+1,ending,currentNode*2+2,vec);
        st[currentNode] = st[currentNode*2+1]^st[currentNode*2+2];
    }
    
    void build(vector<int>& vec){
        build(0,this->n-1,0,vec);
    }
    
    int query(int start, int ending,int l, int r, int currentNode){
        if(start>r || ending<l) return 0;
        
        if(start>=l && ending<=r) return st[currentNode];
        
        int mid = (start+ending)/2;
        int a = query(start,mid,l,r,currentNode*2+1);
        int b = query(mid+1,ending,l,r,currentNode*2+2);
        return a^b;
    }
    
    int query(int l, int r){
        return query(0,this->n-1,l,r,0);
    }
};

vector<int> solve(int n, vector<int>a, vector<vector<int>> queries){
    segmenteTree st;
    st.init(a.size());
    st.build(a);
    vector<int> res;
    for(vector<int>& vec: queries){
        res.push_back(st.query(vec[0]-1,vec[1]-1));
    }
    return res;
}

int main(){
    int n = 5;
    vector<int> a = {3, 2, 4, 5, 1, 1, 5, 3};
    vector<vector<int>> queries = {{2,4},{5,6},{1,8},{3,3}};//output: 3, 0, 6, 4
    vector<int> res = solve(n,a,queries);
    cout<<"Resultado"<<endl;
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}