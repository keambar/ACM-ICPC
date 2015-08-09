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
char s[20][20];
bool vis[30],fb[30];
int hash[30],a[30];
int bx[20][20],r,c;
int create()
{
    memset(fb,0,sizeof(fb));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<r;i++)
    {
        int m=strlen(s[i]);
        for(int j=0;j<m;j++)
        {
            vis[s[i][j]-'A']=1;
            if(j==0)
                fb[s[i][j]-'A']=1;
        }
    }
    int cnt=0;
    for(int i=0;i<26;i++)
        if(vis[i])
        {
            hash[i]=++cnt;
            a[hash[i]]=i;
        }
    for(int i=0;i<r;i++)
    {
        int m=strlen(s[i]);
        for(int j=1;j<=c;j++)
        {
            int k=m-j;
            if(k>=0)
                bx[i][c-j]=hash[s[i][k]-'A'];
            else
                bx[i][c-j]=0;
        }
    }
    return cnt;
}
int p[20];
bool isok()
{
    int n=r-1,m=c-1;
    int sg=0,sum;
    for(int i=m;i>-1;i--)
    {
        sum=sg;
        for(int j=0;j<n;j++)
            if(bx[j][i]!=0)
                sum+=p[bx[j][i]-1];
        sg=sum/10;
        if(sum%10!=p[bx[n][i]-1])
            return 0;
        if(i==0&&sg!=0)
            return 0;
    }
    return 1;
}
int ans;
void work(int n)
{
    bool zo=0;
    if(p[0]==0)
        zo=1;
    do
    {
        bool flag=0;
        if(zo)
        {
            for(int i=0;i<n;i++)
                if(p[i]==0&&fb[a[i+1]])
                {
                    flag=1;
                    break;
                }
        }
        if(!flag&&isok())
            ans++;
    }while(next_permutation(p,p+n));
}
void dfs(int st,int pos,int n)
{
    if(pos==n)
    {
        work(n);
        return;
    }
    for(int i=st;i<10;i++)
    {
        if(10-i<n-pos)
            return;
        p[pos]=i;
        dfs(i+1,pos+1,n);
    }
}
int main()
{
    scanf("%d",&r);
    for(int i=0;i<r;i++)
        scanf("%s",s+i);
    c=strlen(s[r-1]);
    int m=create();
    ans=0;
    dfs(0,0,m);
    printf("%d",ans);
}