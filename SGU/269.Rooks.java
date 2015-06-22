import java.util.*;
import java.math.*;
public class Solution {
    public static void main(String[] args){
        Scanner cin=new Scanner(System.in);
        int n=cin.nextInt(),k=cin.nextInt();
        int[] a=new int[300];
        BigInteger[][] dp=new BigInteger[300][300];
        for(int i=1;i<=n;++i){
        	a[i]=cin.nextInt();
        }
        Arrays.sort(a,1,n+1);
        for(int i=0;i<=250;++i)
        	for(int j=0;j<=250;++j)
        		dp[i][j]=BigInteger.ZERO;

        dp[0][0]=BigInteger.ONE;
        for(int i=1;i<=n;++i){
        	dp[i][0]=dp[i-1][0];
        	for(int j=1;j<=i;++j){
        		dp[i][j]=dp[i-1][j].add(dp[i-1][j-1].multiply(BigInteger.valueOf(a[i]-j+1)));
        	}
        }
        System.out.println(dp[n][k]);
    }
}