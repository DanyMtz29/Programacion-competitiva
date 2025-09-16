/*    La idea de resolverlo.
    El problema te pide dos movimientos, dejar x milanesas o moverte a x mesa.
    Entonces, por cada movimiento esta a 1/2 probabilidad de que ocurra.
    Entonces, eso altera desde el inicio todo, que tal si empezamos desde atras.
    por que?, porque cuando se comienza de la ultima instruccion, es "o me voy a x mesa
    o dejo x milanesa", si elijo moverme a la mesa x, en si no agregare nada, porque 
    despues de la ultima instruccion, no hay milanesas que haya dejado. Y si dedido dejar
    x milanesas en esa instruccion, dejaria x milanesas para la mesa de donde vengo,
    de cual mesa?, no se, solo se que dejare x milanesas, con la probabilidad de 1/2 de 
    que ocurra, 

    Sabiendo eso, entonces empezamos desde el final el recorrido y vamos guardando el total
    de milanesas que podriamos recoger si venimos de una mesa que no sabemos.

    Por ejemplo, con el caso de 4 mesas y 4 instrucciones:
    4 4 
    1 2 3 4
    nuestro arreglo de milanesas dejadas en cada instruccion = [ 0, 0, 0, 0 ]
    entonces, si empezamos de 4, tenemos:
        puedo dejar 4 milanesas, con probabilidad de 1/2 agregando todavia lo de la siguiente instruccion. (no hay)
        y lo divido entre 2, por que?, porque todavia seria la probabilidad de que ocurra que yo me vaya a esa mesa
        = (4*1/2+0)/2 = 2/2
    Sigue con 3, tenemos:
        puedo dejar 3 milanesas con 1/2 de probab. agregando todavia lo de la sig instruccion (2/2)
        = ( 3 * 1/2 + 2/2 )/2 = 5/4
    Sigue con 2, tenemos:
        puedo dejar 2 milanesas con 1/2 de probab. agregando todavia lo de la sig instruccion (5/4)
        = (2 * 1/2 + 5/4)/2 = 9/8
    Sigue con 1, tenemos:
        puedo dejar 1 milanesa con 1/2 de probab. agregando todavia lo de la sig instruccion (9/8)
        = (1 * 1/2 + 9/8)/2 = 13/16

    Despues, a la mesa 1, se le agrega todo lo posible que puede obtener si se queda ahi siempre.
    Por ejemplo, para la instruccion 1, hay una probabilidad de 1/2 * 1, para la instruccion 2, hay 
    una probabilidad de 1/4 * 2, para la instruccion 3, hay una probabilidad de 1/8 * 3, y asi sucesivamente
    para cada x de cada instruccion.

    Por ultimo, a cada mesa se le suma lo que se haya esperado de milanesas por cada instruccion
    Por ejemplo, siguiendo las instrucciones y el arreglo de milanesas dejadas
    instruccion 1
        me muevo a la mesa 1, entonces a la mesa 1 le sumo lo que tengo en el arreglo en ese indice
    instruccion 2
        me muevo a la mesa 2, entonces a la mesa 2 le sumo lo que tengo en el arreglo en ese indice
    instruccion 3
        me muevo a la mesa 3, entonces a la mesa 3 le sumo lo que tengo en el arreglo en ese indice
    instruccion 4
        me muevo a la mesa 4, entonces a la mesa 4 le sumo lo que tengo en el arreglo en ese indice

    y eso es toda la solucion.
*/

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

//Variables
int n,m;
vector<int> a;

int subm(int a, int b){
    return ((a-b) % MOD + MOD)%MOD;
}

int mulm(int a, int b){
    return (a*b)%MOD;
}

int summ(int a, int b){
    return (a+b)%MOD;
}

int pwr(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res*=a,res%=MOD;
        a*=a,a%=MOD;
        b>>=1;
    }
    return res;
}

int inv(int x){
    return pwr(x,MOD-2);
}

void solve(){
    //Reading variables
    cin>>n>>m;
    a.resize(m);

    //Reading the array
    forN(m,a);

    vector<int> ans(n+1);
    //We start at table 1, if we stay at this one, we get all chicken milanesas from the following tables.
    int allMilanesas = 0;
    for( int i = 0 ; i < m ; i++ ){
        int pot2 = pwr(2,(i+1));
        allMilanesas = summ(allMilanesas, mulm( a[i], inv(pot2) ));
    }

    //cout<<"AllMIlanesas: "<<allMilanesas<<"\n";
    ans[1] = allMilanesas;

    vector<int> expectedMilanesas(m);
    expectedMilanesas[m-1] = 0;

    int inv2 = inv(2);
    for( int i = m-2 ; i>=0 ; i-- ){
        int expected = mulm(a[i+1], inv2);
        int val = summ(expectedMilanesas[i+1],expected);
        val = mulm(val,inv2);
        expectedMilanesas[i] = val;
    }

    for( int i = 0 ; i < m ; i++ ){
        int table = a[i];
        ans[table] = summ(ans[table],expectedMilanesas[i]);
    }

    for( int i = 1 ; i<=n;i++ )
        cout<<ans[i]<<"\n";
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