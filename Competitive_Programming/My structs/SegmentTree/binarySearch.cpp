#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

        //Actualiza el currentNode con la gcd de los nodos hijos
        st[currentNode] = gcd( st[2*currentNode+1], st[2*currentNode+2] );
        

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

        if( r<=mid ){
            return query(start, mid, l, r, 2*currentNode+1);
        }else if( l>=mid+1 ){
            return query(mid+1, ending, l, r, 2*currentNode+2);
        }else{
            int q1 = query(start,mid, l,r,2*currentNode+1);
            int q2 = query(mid+1,ending,l,r,2*currentNode+2);
            return gcd( q1, q2 );
        }
    }

    int query(int l, int r) {
		return query(0,n-1,l,r,0);
	}

    int gcd(int a, int b){
        if(b==0) return a;
        else return gcd(b, a%b);
    }

    void show(){
        copy( st.begin(), st.end(), ostream_iterator<int> (cout, "|") );
    }
};

int main2(){
    vector<int> vec = {2,7,6,4,1,9,10,20};
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

    //tree->update(2,100);
    cout<<tree->query(1,3)<<endl;

    
    return 0;
}

bool check(int mid, int N, segmentTree& st){
    int k = mid+1; // Para determinar el rango de consulta
    
    int j = 0;
    int gcdPrev = -1;
    for(int i=0;i<N;i++){
        if( i+1-j < k) continue;//Si el rango es menor que la mitad, se continua

        int GCD = st.query( j, i );//Consulta el GCD del rango

        if(mid == 3){
            cout<<"j :"<<j<<endl;
            cout<<"i :"<<i<<endl;
            cout<<"prev :"<<gcdPrev<<endl;
            cout<<"gcd :"<<GCD<<endl;
        }

        if( gcdPrev == -1 ){ //Si todavia no se ha calculado un GCD
            gcdPrev = GCD;
            j++;
        }else{
            if(gcdPrev != GCD){//Indica que en ese punto del arbol, los gcd son diferentes, por lo tanto, hay que buscar en otro punto
                return false;
            }
            j++;
        }

        if(j == (N/2)-1) break;//Si llego a la mitad del arbol el rango, ya se acabo la busqueda en ese rango

    }

    return true; //Significando que todos los gcd son iguales
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int N; cin>>N;
        vector<int> arr(N);
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }

        segmentTree st;
        st.init(N);
        st.build(arr);

        //Implementacion de la busqueda binaria
        int l = 0;
        int r = N*2-1;//Para que abarque todo el segmentTree        

        int ans = N-1;

        st.show();

        while(l<=r){
            int mid = (l+r)/2;
            
            bool isEqual = check(mid,N*2, st);

            cout<<"Mitad: "<<mid<<endl;

            if(isEqual){//Si todos los gcd son iguales, hay una solucion
                ans = mid;
                cout<<"Correcta: "<<mid<<endl;
                r = mid-1;// Para comprobar si en un rango mas bajo los gcd son iguales tambien, significa que son menos movimientos
            }else{
                l = mid+1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}