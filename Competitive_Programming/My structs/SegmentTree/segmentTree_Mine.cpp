#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    > Struct crate by Daniel Juarez
    > modified on 02/03/2025
*/

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
        st[currentNode] = st[2*currentNode+1] + st[2*currentNode+2];

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
        return q1+q2;
    }

    int query(int l, int r) {
		return query(0,n-1,l,r,0);
	}

    void update(int start, int ending, int currentNode, int index, int val){
        //caso base
        if(start==ending){
            st[currentNode] = val;
            return;
        }
        
        int mid = (start+ending)/2;
        if(index<=mid){//el nodo se encuentra en el arbol izquierdo
            update(start,mid, 2*currentNode+1,index,val);
        }else{//el index a actualizar se encuentra en el arbol derecho
            update(mid+1,ending,2*currentNode+2,index,val);
        }

        //actualizar las sumas donde participa ese indice actualizado
        st[currentNode] = st[2*currentNode+1] + st[2*currentNode+2];

    }
    void update(int index, int val){
        update(0,n-1,0,index,val);
    }

    void show(){
        copy( st.begin(), st.end(), ostream_iterator<int> (cout, "|") );
        cout<<endl;
    }
};

int main(){
    int n;
    while(cin>>n){
        segmentTree *tree = new segmentTree;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        tree->init(n);
        tree->build(arr);
        tree->show();
        delete tree;
    }

    /*vector<int> vec = {2,7,6,4,1,9,10,20};
    segmentTree *tree = new segmentTree;
    //CONTRUIR ARBOL
    tree->init(vec.size());
    tree->build(vec);
    
    //HACER CONSULTAS Y ACTUALIZACIONES
    cout<<"query 0,0: "<<tree->query(0,0)<<endl;
    cout<<tree->query(0,4)<<endl;
    cout<<tree->query(5,7)<<endl;
    cout<<tree->query(0,7)<<endl;
    cout<<tree->query(2,5)<<endl;

    tree->update(2,100);
    cout<<tree->query(1,3)<<endl;
    */
    
    return 0;
}