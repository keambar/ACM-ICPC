import java.util.*;
import java.math.*;
public class Solution {
    public static void main(String[] args){
        Scanner cin=new Scanner(System.in);
        int n=cin.nextInt();
        BigInteger[] a=new BigInteger[1009];
        for(int i=1;i<=n;++i){
        	a[i]=cin.nextBigInteger();
        }
        Arrays.sort(a,1,n+1);
        for(int i=1;i<=n;++i){
        	for(int j=i+1;j<n;++j){
        		if(a[i].add(a[j]).compareTo(a[j+1])==1){
        			System.out.println(a[i]+" " + a[j]+ " "+ a[j+1]);
        			System.exit(0);
        		}
        	}
        }
        System.out.println("0 0 0");
    }
}
