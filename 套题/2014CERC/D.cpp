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
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
struct Cr
{
    int x,y,r;
}cr[1010];
int dis2(Cr a,Cr b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool isok(Cr a,Cr b)
{
    int d1=dis2(a,b),d2=(a.r+b.r)*(a.r+b.r);
    return d1<=d2;
}
int dir[1010];
int sp[1010][2];
void gao(int id,int jd)
{
    dir[jd]=(dir[id]^1);
    int a=sp[id][0],b=sp[id][1];
    a*=cr[id].r;
    b*=cr[jd].r;
    int c=gcd(a,b);
    sp[jd][0]=a/c;
    sp[jd][1]=b/c;
}
vector<int>bx;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&cr[i].x,&cr[i].y,&cr[i].r);
        memset(dir,-1,sizeof(dir));
        dir[0]=1;
        sp[0][0]=1;
        sp[0][1]=1;
        bx.clear();
        bx.push_back(0);
        for(int i=0;i<bx.size();i++)
        {
            int id=bx[i];
            for(int j=0;j<n;j++)
                if(dir[j]==-1&&isok(cr[id],cr[j]))
                {
                    gao(id,j);
                    bx.push_back(j);
                }
        }
        for(int i=0;i<n;i++)
            if(dir[i]==-1)
                puts("not moving");
            else
            {
                if(sp[i][1]==1)
                    printf("%d ",sp[i][0]);
                else
                    printf("%d/%d ",sp[i][0],sp[i][1]);
                if(dir[i]==1)
                    puts("clockwise");
                else
                    puts("counterclockwise");
            }
    }
    return 0;
}