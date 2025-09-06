/*
    La idea de resolverlo fue usar un fenwick tree. 
    En el que se basa por eventos en consultas offline.

    Ejemplo:
    8 4
    3 2 4 5 1 1 5 3
    2 4 2 4
    5 6 2 9
    1 8 1 5
    3 3 4 4

    Primero se guardan todos los datos, tanto del array y las queries. El array lo guardamos de la siguiente manera:
    (Siguiendo el ejemplo del problema)
    Array guardado: 
    {[3, 0], [2, 1], [4, 2], [5, 3], [1, 4], [1, 5], [5, 6], [3, 7]}
    Es un arreglo de pair<int,int>, donde el first es xi y el second i. Para ordenarlos por xi creciente y poder
    insertar en el fenwick en orden para hacer la consulta

    Despues, las queries se guardan de la siguiente forma, en un arreglo de eventos (queries)

    [ v: c-1 o d, idx: id de la consulta, a: corresponde a 'a', b: corresponde a 'b', sign: signo para ver si se añade o se quita ]

    Dos por cada consulta, es decir, un evento para la query 1 con v = c-1 y otro evento para la query 1 con v = d. Los dos con 
    los mismos datos, solo varia v y el signo. El signo negativo (-1) para v = c-1 y el signo positivo (+1) para v = d;

    Esto debido a la logica. Siguiendo con el ejemplo, cuando lleguemos a v = 1, que corresponde a la consulta 1 y 2, pero 
    concentrandonos en la consulta 2, ya que es el rango 5-6. En el rango 5-6 se encuentran los dos 1's, Entonces en el fenwick
    tendriamos los siguiente:
    0 0 0 0 1 2 2 2
    Cuando hagamos la consulta, como v = 1, corresponde a c-1 de la consulta 2, entonces se hace una resta para no contar
    esos elementos ya que esos son menores que 2 (del rango 2-9), para cuando haga la consulta del 9, va a volver a checar y preguntar
    en ese rango, cuantos son menores que 9, en el caso hay 2, pero como esos 1's, son menores que 2, no los tenemos que valer, asi que
    se cancelan con la consulta de cuando llegue al 9, ya que haria 2 positivo - 2 negativo, da como respuesta un cero.

    Asi para cada evento, se van a ir insertando todos los elementos menores a mi v, para no valerlos, hasta que despues me tope
    con mi v positivo y ahora poder hacer mi consulta valida, ya restando los menores.

*/

#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int,int>
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define ppi pair<pair<int,int>,int>
#define pb push_back
#define F first
#define S second
const int MOD=1e9+7;
using namespace std;

// 1 based index
struct Fenwick
{
    vi ft;
    int n;

    void init(int _n){
        this->n = _n;
        this->ft.resize(_n + 1,0);
    }

    void add(int i, int val)
    {
        for (i++; i <= n; i += (i & (-i))) // MODIFICAR SI VA HASTA N
            ft[i] += val;
    }

    int query(int i)
    {
        int ans = 0;
        for (i++; i; i -= (i & (-i)))
            ans += ft[i];
        return ans;
    }

    int rangeQuery(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    void show()
    {
        cout << "FENWICK TREE" << endl;
        for (int i = 0; i < n - 1; i++)
            cout << this->query(i) << " ";
        cout << "\n";
    }
};

struct event{
    int v,idx,sign, a,b;

    bool operator<(event& e)const{
        return this->v<e.v;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;

        vector<pi> arr(n);
        for( int i = 0; i < n; i++ ){
            int x;
            cin>>x;
            arr[i] = make_pair(x,i);
        }

        sort( all(arr) );

        Fenwick ft;
        ft.init(n);

        vector<event> events(q*2);

        for( int i = 0 ; i < q*2 ; i+=2 ){
            int a,b,c,d;
            cin>>a>>b>>c>>d;

            events[i].a = a;
            events[i].b = b;
            events[i].sign = -1;
            events[i].v = c-1;
            events[i].idx = i/2;
            
            events[i+1].a = a;
            events[i+1].b = b;
            events[i+1].sign = 1;
            events[i+1].v = d;
            events[i+1].idx = i/2;
        }

        sort( all(events) );
           

        int j = 0;
        vi res(q,0);
        for( int i = 0 ; i < q*2; i++ ){
            int currV = events[i].v;
            while( j < n && arr[j].F <= currV ){
                ft.add(arr[j].S, 1);
                j++;
            }
            int getAns = ( ft.rangeQuery(events[i].a-1,events[i].b-1) * events[i].sign);
            res[events[i].idx] += getAns;
        }
        
        for( int x: res )
            cout<<x<<"\n";
        
    }
    return 0;
}