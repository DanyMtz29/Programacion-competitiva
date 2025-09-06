#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;

int n;
long long T;
int a[N];
int f[N];

void upd(int x){
	for (int i = x; i < N; i |= i + 1)
		++f[i];
}

int get(int x){
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		res += f[i];
	return res;
}

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
    n = 5;
    T= 4;
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
	upd(update);

    cout<<"Arreglo F"<<endl;
    show(f,15);

	forn(i, n){
        cout<<"Valor de i: "<<i<<endl;
		pr += a[i];
		cout<<"\nPr: "<<pr<<endl;
        cout<<"Pr - T: "<<(pr-T)<<endl;
		int npos = upper_bound(sums.begin(), sums.end(), pr - T) - sums.begin();
        cout<<"\nNPos: "<<npos<<endl;
        int sumaAns = get(npos-1);
        cout<<"\nSuma Ans: "<<sumaAns<<endl;
		ans += (i + 1 - sumaAns);
        cout<<"ans: "<<ans<<endl;
		
		int k = lower_bound(sums.begin(), sums.end(), pr) - sums.begin();
        cout<<"\nK: "<<k<<endl;
		upd(k);
        cout<<"Arreglo F"<<endl;
        show(f,15);
	}
	
	printf("%lld\n", ans);
	return 0;
}