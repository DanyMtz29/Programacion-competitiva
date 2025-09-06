#include <bits/stdc++.h>
using namespace std;

bool flag = false;

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
            this-> val = nodeLeft->val + nodeRight->val;

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
            return q1 + q2;
        }
        
    }

    void update(int index, int value){
        if( this->left == index && index == this->right ){
            this->val = value;
            return;
        }

        int mid = (this->left + this->right) / 2;

        if( index <= mid ){
            this->nodeLeft->update( index, value );
        }else{
            this->nodeRight->update( index, value );
        }
        this->val = this->nodeLeft->val + this->nodeRight->val;
        
    }

};

bool check(int mid, int N, segmentTree& st, int target){
    int k = mid+1; // Para determinar el rango de consulta
    
    bool menor = false;

    int j = 0;
    int gcdPrev = -1;

    for(int i=0;i<N;i++){
        if( i+1-j < k) continue;//Si el rango es menor que la mitad, se continua

        int sumMax = st.query( j, i );

        if(sumMax==target) {
            flag = true;
            return true;
        }

        if( sumMax > target ){ 
            menor = true;
        }

        j++;

        if(j == N/2) break;//Si llego a la mitad del arbol el rango, ya se acabo la busqueda en ese rango

    }

    return menor; 
}

void binary(segmentTree& st, int N, int target){
    int l = 0;

    int r = N-1;//Para que abarque todo el segmentTree        

    while(l<=r){
        int mid = (l+r)/2;
        
        bool isEqual = check( mid, N , st , target);
        if( flag ){            
            break;
        }
        if(isEqual){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int N, Q; cin>>N>>Q;
        vector<int> arr(N);
        for(int i=0;i<N;i++){
            cin>>arr[i];
            
        }
        segmentTree st;

        st.init( arr, 0, N-1 );

        for( int i = 0; i < Q; i++ ){
            int accion, target, index, value;
            cin>>accion;
            if( accion == 1 ){
                cin>>target;

                //Implementacion de la busqueda binaria
                binary(st, N, target);

                if(flag){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
                flag = false;               
            }else{
                cin>>index>>value;
                st.update( index-1, value );
                //st.show();
            }   

        }//Fin del for
    }//Fin del while de los casos

    return 0;
}