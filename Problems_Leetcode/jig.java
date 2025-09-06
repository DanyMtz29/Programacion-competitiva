import java.util.ArrayList;
import java.util.Scanner;

class Jig {    
    public static class Pair{
        public double posicion;
        public double altura;
        public Pair(double pos, double al){
            this.posicion = pos;
            this.altura = al;
        }
    }
    
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int teta = sc.nextInt();
            double angulo = Math.tan(teta*(Math.PI/180));
            int N = sc.nextInt();
            ArrayList<Pair> arr = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                double pos = sc.nextDouble();
                double alt = sc.nextDouble();
                Pair p = new Pair(pos,alt);
                arr.add(p);
            }
            arr.sort((a,b) -> (int)a.posicion - (int)b.posicion);
            solve(arr,angulo);            
        }
    }
    public static void solve(ArrayList<Pair> arr, double a){
        double suma = 0;
        double prev = arr.get(0).posicion;
        for(Pair par: arr){
            double cat = (par.altura/a);
            if(par.posicion<=prev && (cat+par.posicion) > prev){
                suma -= (prev-par.posicion);
                suma += cat;
                prev = suma;
            }else if(par.posicion > prev){
                suma += cat;
                prev = (par.posicion + cat);
            }
        }
        System.out.println(suma);
    }
}
