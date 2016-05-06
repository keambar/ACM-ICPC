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
typedef long long ll;
const ll mod=1000000007;
ll fac[110];
int a[110][110];
bool vis[110];
bool ik(int n,int r)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(a[r][i]>n||a[r][i]<1||vis[a[r][i]])
            return 0;
        vis[a[r][i]]=1;
    }
    return 1;
}
bool isok(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        int r=m,t=i;
        while(1)
        {
            t=a[r][t];
            if(r==1&&t!=i)
                return 0;
            r--;
            if(r==0)
                return 1;
        }
    }
}
int main()
{
    fac[0]=1;
    for(int i=1;i<=100;i++)
        fac[i]=fac[i-1]*i%mod;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ll ans=1;
        bool flag=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a[i][1]);
            if(a[i][1]==-1)
            {
                if(flag)
                    ans=ans*fac[n]%mod;
                flag=1;
                continue;
            }
            for(int j=2;j<=n;j++)
                scanf("%d",&a[i][j]);
            if(!ik(n,i))
                ans=0;
        }
        if(ans==1&&!flag&&!isok(n,m))
            ans=0;
        cout<<ans<<endl;
    }
}