#include<stdio.h>
int gcd(int x, int y) {
    return x%y==0?y:gcd(y,x%y);
}
int main()
{
    int n,i,ans=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++) 
     if(gcd(i,n)==1) ans++;
    printf("%d\n",ans);
    return 0;
}