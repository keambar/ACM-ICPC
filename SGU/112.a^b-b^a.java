import java.util.;
import java.math.;
public class Solution {
    public static void main(String[] args){
        Scanner cin=new Scanner(System.in);
        int a=cin.nextInt(),b=cin.nextInt();
        BigInteger s,t;
        s=BigInteger.valueOf(a).pow(b);
        t=BigInteger.valueOf(b).pow(a);
        System.out.print(s.subtract(t));        
    }
}