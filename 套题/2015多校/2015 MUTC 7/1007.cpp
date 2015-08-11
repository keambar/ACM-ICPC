#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[200010][2];
int val[200010];
char s[200010];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++)
    {
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;i<n;i++)
            scanf("%d",val+i);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                if(i==0)
                {
                    dp[0][0]=0;
                    dp[0][1]=val[0];
                }
                else
                {
                    dp[i][0]=max(dp[i-1][0],dp[i-1][1]+val[i]);
                    dp[i][1]=max(dp[i-1][0]+val[i],dp[i-1][1]);
                }
            }
            else
            {
                if(s[i]=='0')
                {
                    if(i==0)
                        dp[i][0]=0;
                    else
                        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+val[i]);
                    dp[i][1]=-2000000000;
                }
                else
                {
                    dp[i][0]=-2000000000;
                    if(i==0)
                        dp[i][1]=val[i];
                    else
                        dp[i][1]=max(dp[i-1][0]+val[i],dp[i-1][1]);
                }
            }
        }
        printf("Case #%d: %d\n",cs,max(dp[n-1][0],dp[n-1][1]));
    }
    return 0;
}