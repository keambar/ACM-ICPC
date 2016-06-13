import java.io.*;
import java.util.*;
import java.math.*;

public class Main {	

	public static BigInteger quickPow(int a, int b) {
		BigInteger ans = new BigInteger(1+"");
		BigInteger p = new BigInteger(a+"");
		while(b != 0) {
			if(b % 2 != 0) 
				ans = ans.multiply(p);
			p = p.multiply(p);
			b = b / 2;
		}
		return ans;
	}
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);		
		while(in.hasNext()) {
			int x = in.nextInt();
			int y = in.nextInt();
			Set<BigInteger> set = new TreeSet<BigInteger>();
			for(int a = 2; a <= x; a++) {
				for(int b = 2; b <= y; b++) {
					BigInteger term = quickPow(a, b);
					set.add(term);
				}
			}
			System.out.println(set.size());
		}
	}
}