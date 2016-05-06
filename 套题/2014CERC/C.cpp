#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
bool isok(int n,int x)
{
    if(x%n!=0)
        return 0;
    x/=n;
    return x+1>n&&(x+1-n)%2==0;
}
int work(int x)
{
    int ans=x;
    for(int i=2;i*i<=x;i++)
    {
        if(isok(i,x))
            return ans=i;
        if(isok(x/i,x))
            ans=x/i;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x;
        scanf("%d",&x);
        int n=work(x*2);
        if(n==x*2)
            puts("IMPOSSIBLE");
        else
        {
            int a=(2*x/n+1-n)/2;
            printf("%d = ",x);
            for(int i=0;i<n;i++)
            {
                if(i)
                    printf(" + ");
                printf("%d",a+i);
            }
            puts("");
        }
    }
}