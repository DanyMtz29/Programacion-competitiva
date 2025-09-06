#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)

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
    
    void update(int start, int ending, int currentNode, int index){
        if(start==ending){
            st[currentNode]++;
            return;
        }
        int mid = (start+ending)/2;
        if(index<=mid){
            update(start,mid,currentNode*2+1,index);
        }else{
            update(mid+1,ending,currentNode*2+2,index);
        }
        st[currentNode] = st[currentNode*2+1]+st[currentNode*2+2];
    }
    void update(int index){
        update(0,this->n-1,0,index);
    }
    void show(){
        forn(i,n) {
            cout<<st[i]<<",";
        }
        cout<<"\n"<<endl;
    }
};

void show(int* a, int aa){
    for(int i=0;i<aa;i++){
        cout<<a[i]<<",";
    }
    cout<<"\n"<<endl;
}

void show(vector<long long>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<",";
    }
    cout<<"\n"<<endl;
}

int main() {
	//scanf("%d%lld", &n, &T);
    int n = 5;
    int T= 4;
	//forn(i, n)
		//scanf("%d", &a[i]);

    int a[n] = {5,-1,3,4,-1};

    cout<<"Arreglo a"<<endl;
    show(a,n);


	vector<long long> sums(1, 0ll);
	long long pr = 0;
	forn(i, n){
		pr += a[i];
		sums.push_back(pr);
	}
	
    cout<<"Vector de sumas"<<endl;
    show(sums);

	sort(sums.begin(), sums.end());
    cout<<"Vector de sumas ordenado"<<endl;
    show(sums);
	sums.resize(unique(sums.begin(), sums.end()) - sums.begin());
	
	long long ans = 0;
	pr = 0;
    //ES UNA BUSQUEDA BINARIA ESTO
    int update = lower_bound(sums.begin(), sums.end(), 0ll) - sums.begin();
    segmentTree st;
    st.init(n);
    
	//upd(update);
    st.update(0);
    cout<<"Mostrando el segment tree hasta el momento"<<endl;
    st.show();

	forn(i, n){
        cout<<"Valor de i: "<<i<<endl;
		pr += a[i];
		cout<<"\nPr: "<<pr<<endl;
        cout<<"Pr - T: "<<(pr-T)<<endl;
		int npos = upper_bound(sums.begin(), sums.end(), pr - T) - sums.begin();
        cout<<"\nNPos: "<<npos<<endl;
        int sumaAns = st.query(0,npos-1);
        cout<<"\nSuma Ans: "<<sumaAns<<endl;
		ans += (i + 1 - sumaAns);
        cout<<"ans: "<<ans<<endl;
		
		int k = lower_bound(sums.begin(), sums.end(), pr) - sums.begin();
        cout<<"K: "<<k<<endl;
		st.update(k);
        cout<<"Arreglo F"<<endl;
        //show(f,15);
	}
	
	printf("%lld\n", ans);
	return 0;
}