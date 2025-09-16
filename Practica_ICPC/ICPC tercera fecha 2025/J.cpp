#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define pb push_back
#define F first
#define S second
#define e "\n"
#define IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

//Constantes
const int MOD=1e9+7;

//Estructuras

struct segmentTree{
    //segment tree vector
    vector<int> st;
    int n; //Size

    void init(int n){
        this->n = n;//tamanio del vector que manejaremos
        st.resize(4*n,0);//tamanio total del segment tree
    }

    void build(int start, int ending, int currentNode, vector<int>& vec){//private
        //Caso de Nodo hoja
        if(start == ending){
            st[currentNode] = vec[start];
            return;
        }

        int mid = (start+ending)/2;//Dividir el segment
        //SubArbol izquierdo
        build(start,mid, 2*currentNode + 1, vec);

        //SubArbol derecho
        build(mid+1, ending, 2*currentNode+2,vec);

        //Actualiza el currentNode con la suma maxima
        st[currentNode] = st[2*currentNode+1] ^ st[2*currentNode+2];

    }
    void build(vector<int>& vec){//public
        build(0,this->n-1,0,vec);
    }

    int query(int start, int ending, int l, int r, int currentNode){
        //no hay superposicion de segmentos
        if(start>r || ending<l) return 0;

        //superposicion completa
        if(start >= l && ending<=r) return st[currentNode];

        //caso parcial
        int mid = (start+ending)/2;

        int q1 = query(start,mid, l,r,2*currentNode+1);
        int q2 = query(mid+1,ending,l,r,2*currentNode+2);
        return q1^q2;
    }

    int query(int l, int r) {
		return query(0,n-1,l,r,0);
	}

    void update(int start, int ending, int currentNode, int index, int val){
        //caso base
        if(start==ending){
            st[currentNode]+=val;
            return;
        }
        
        int mid = (start+ending)/2;
        if(index<=mid){//el nodo se encuentra en el arbol izquierdo
            update(start,mid, 2*currentNode+1,index,val);
        }else{//el index a actualizar se encuentra en el arbol derecho
            update(mid+1,ending,2*currentNode+2,index,val);
        }

        //actualizar las sumas donde participa ese indice actualizado
        st[currentNode] = st[2*currentNode+1] ^ st[2*currentNode+2];

    }
    void update(int index, int val){
        update(0,n-1,0,index,val);
    }
};

//Variables

void solve(){
    int n,m;
    cin>>n>>m;
    vi arr(n);
    forN(n,arr);

    segmentTree st;
    st.init(n);
    st.build(arr);

    while(m--){
        char c; cin>>c;
        if(c == 'P'){
            int l,r;
            cin>>l>>r;
            l--;r--;
            int ans =st.query(l,r);
            cout<<(ans==0?"JUAN":"FRANK")<<"\n";
        }else{
            int k,x;
            cin>>k>>x;
            k--;
            st.update(k,x);
            
        }
    }
}

int32_t main(){
    IO;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}