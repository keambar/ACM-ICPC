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
bool hang[110],lie[110];
int pic[110][110];
vector<int>num[2][110][110];
vector<int>ans;
bool seek(int n)
{
    bool res=0;
    for(int i=0;i<n;i++)
        if(!hang[i])
        {
            int flag=0;
            for(int j=0;j<n;j++)
                if(!lie[j])
                {
                    if(flag==0)
                        flag=pic[i][j];
                    else if(pic[i][j]!=flag)
                    {
                        flag=-1;
                        break;
                    }
                }
            if(flag>0)
            {
                if(num[0][i][flag].size())
                {
                    res=1;
                    ans.push_back(num[0][i][flag].back());
                    num[0][i][flag].pop_back();
                    hang[i]=1;
                }
            }
        }
    for(int i=0;i<n;i++)
        if(!lie[i])
        {
            int flag=0;
            for(int j=0;j<n;j++)
                if(!hang[j])
                {
                    if(flag==0)
                        flag=pic[j][i];
                    else if(pic[j][i]!=flag)
                    {
                        flag=-1;
                        break;
                    }
                }
            if(flag>0)
            {
                res=1;
                if(num[1][i][flag].size())
                {
                    ans.push_back(num[1][i][flag].back());
                    num[1][i][flag].pop_back();
                    lie[i]=1;
                }
            }
        }
    return res;
}
char s[10];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&pic[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&pic[i][j]);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%s%d%d",s,&x,&y);
            if(s[0]=='H')
                num[0][x-1][y].push_back(i);
            else
                num[1][x-1][y].push_back(i);
        }
        ans.clear();
        memset(hang,0,sizeof(hang));
        memset(lie,0,sizeof(lie));
        while(seek(n));
        for(int i=0;i<n;i++)
            for(int j=1;j<=n;j++)
                for(int k=0;k<2;k++)
                    while(num[k][i][j].size())
                    {
                        ans.push_back(num[k][i][j].back());
                        num[k][i][j].pop_back();
                    }
        for(int i=m-1;i>-1;i--)
        {
            printf("%d",ans[i]);
            if(i)
                putchar(' ');
        }
        puts("");
    }
}