import java.lang.*;
import java.math.BigInteger;
import java.util.*;

class Solution{

    public static void solve(BigInteger a, BigInteger b){
        BigInteger y,x;
        x = a.subtract(b);
        x = x.divide(BigInteger.valueOf(2));
        y = x.add(b);
        System.out.println(y);
        System.out.println(x);
    }

    public static void main(String args[]){
        int t=10;
        Scanner sc = new Scanner(System.in);
        while(t>0){
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            solve(a,b);
            t--;
        }
    }
}