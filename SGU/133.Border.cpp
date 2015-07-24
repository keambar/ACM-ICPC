#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int num;
struct node
{
    int a,b;
}op[16010];
bool cmp(node x,node y)
{
    if(x.a!=y.a)
        return x.a>y.a;
    return x.b<y.b;
}
void init()
{
    int i;
    scanf("%d",&num);
    for(i=0;i<num;i++)
        scanf("%d%d",&op[i].a,&op[i].b);
}
void work()
{
    int i,j,sum=0;
    sort(op,op+num,cmp);
    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if(op[i].a>op[j].a&&op[i].b<op[j].b)
            {
                sum++;
                break;
            }
        }
    }
    printf("%d",sum);
}
int main(){
    init();
    work();
}