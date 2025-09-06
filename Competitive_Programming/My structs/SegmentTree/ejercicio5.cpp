#include<bits/stdc++.h>
using namespace std;

#define forn(ii,n) for(int ii=0;ii<n;ii++)

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct segmentTree{
    int n;
    vector<int> st;
    
    void init(int _n){
        n = _n;
        st.resize(4*n,0);
    }
    void build(int start, int ending, int node, vector<int>& v){
        if(start==ending){
            st[node] = v[start];
            return;
        }
        int mid = (start+ending)/2;
        build(start,mid,node*2+1,v);
        build(mid+1,ending,node*2+2,v);
        st[node] = gcd(st[node*2+1],st[node*2+2]);
    }

    int query(int start, int ending, int node, int l, int r){
        if(r<start || l>ending) return 0;
        if(start>=l && ending<=r) return st[node];
        int mid = (start+ending)/2;
        int q1 = query(start,mid,node*2+1,l,r);
        int q2 = query(mid+1,ending,node*2+2,l,r);
        return gcd(q1,q2);
    }

    void upd(int start, int ending, int node, int idx, int val){
        if(start==ending){
            st[node]=val;
        }
        int mid= (start+ending)/2;
        if(idx<=mid){
            upd(start,mid,node*2+1,idx,val);
        }else{
            upd(mid+1,ending,node*2+2,idx,val);
        }
        st[node] = gcd(st[node*2+1],st[node*2+2]);
    }
};

bool isEqual(vector<int>& a){
    for(int i=0;i<a.size()-1;i++){
        if(a[i]!=a[i+1]) return false;
    }
    return true;
}

int solve(int n, vector<int>a){
    if(isEqual(a)) return 0;
    int sz = n;
    vector<int> sol(sz);
    segmentTree st;
    st.init(sz);
    st.build(0,sz-1,0,a);
    int cont = 0;

    while(true){
        vector<int> b(sz);
        cont++;
        for(int i=0;i<sz;i++){
            int newVal;
            if(i==sz-1){
                newVal = gcd(a[0],a[i]);
            }else{
                newVal = st.query(0,sz-1,0,i,i+1);
            }
            b[i] = newVal;
        }
        a=b;
        if(isEqual(b)) break;
        st.build(0,sz-1,0,b);
    }
    return cont;
}

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        forn(ii,n) cin>>a[ii];
        cout<<solve(n,a)<<endl;
    }
    return 0;
}