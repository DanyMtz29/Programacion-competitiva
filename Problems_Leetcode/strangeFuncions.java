import java.util.Scanner;

class strangeFunctions {
	
	public static void main(String[] args) {
		Scanner fs = new Scanner(System.in);
		int T = fs.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			long n = fs.nextLong();
			long lcm = 1, ans = 0;
			for (long i = 2; ; i++) {
                System.out.println("I: "+i);
                System.out.println("lcm: "+lcm);
				long before = n / lcm;
                System.out.println("before: "+before);
				lcm = getLcm(lcm, i);
                System.out.println("lcm despues de calculo: "+lcm);
				long after = n / lcm;
                System.out.println("after: "+after);
				ans += (before - after) * i;
                System.out.println("ans: "+ans);
				ans %= mod;
				if (lcm > n) {
					break;
				}
			}
			System.out.println(ans);
		}
        fs.close();
	}
	
	static final int mod = 1_000_000_007;
	static long getLcm(long a, long b) {
		return (a * b) / getGcd(a, b);
	}
	
	static long getGcd(long a, long b) {
		if (b == 0) {
			return a;
		}
		return getGcd(b, a % b);
	}
}