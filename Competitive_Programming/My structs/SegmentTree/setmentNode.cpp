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
/*
            cout<<"L: "<<this->left<<endl;
            cout<<"R: "<<this->right<<endl;
            int g = gcd( nodeLeft->val, nodeRight->val );
            cout<<"Valor: "<<g<<endl;
            cout<<endl;
            this->val = g;
*/
            this-> val = gcd( nodeLeft->val, nodeRight->val );

        }else{
           /* cout<<"L: "<<this->left<<endl;
            cout<<"R: "<<this->right<<endl;
            cout<<"Valor: "<<arr[this->left]<<endl;
            cout<<endl;
            */
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

    void show(){
    }

};

bool check(int mid, int N, segmentTree& st){
    int k = mid+1; // Para determinar el rango de consulta
    
    int j = 0;
    int gcdPrev = -1;

    for(int i=0;i<N;i++){
        if( i+1-j < k) continue;//Si el rango es menor que la mitad, se continua

        //cout<<"j: "<<j<<endl;
        //cout<<"i: "<<i<<endl;

        int GCD = st.query( j, i );//Consulta el GCD del rango

        //cout<<"GCD: "<<GCD<<endl;

        if( gcdPrev == -1 ){ //Si todavia no se ha calculado un GCD
            gcdPrev = GCD;
            j++;
        }else{
            if(gcdPrev != GCD){//Indica que en ese punto del arbol, los gcd son diferentes, por lo tanto, hay que buscar en otro punto
                return false;
            }
            j++;
        }

        if(j == N/2) break;//Si llego a la mitad del arbol el rango, ya se acabo la busqueda en ese rango

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
        vector<int> arr(N*2);
        for(int i=0;i<N;i++){
            cin>>arr[i];
            arr[i+N] = arr[i];
        }
/*
        cout<<"Vector"<<endl;
        copy( arr.begin(), arr.end(), ostream_iterator<int> (cout, "|") );
        cout<<endl;
*/
        segmentTree st;

        N*=2; 

        st.init( arr, 0, N-1 );

        //Implementacion de la busqueda binaria
        int l = 0;

        int r = N-1;//Para que abarque todo el segmentTree        

        int ans = N-1;


        while(l<=r){
            int mid = (l+r)/2;
            
            bool isEqual = check( mid, N , st );

            //cout<<"Mid: "<<mid<<endl;

            if(isEqual){//Si todos los gcd son iguales, hay una solucion
                ans = mid;
                r = mid-1;// Para comprobar si en un rango mas bajo los gcd son iguales tambien, significa que son menos movimientos
            }else{
                l = mid+1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}