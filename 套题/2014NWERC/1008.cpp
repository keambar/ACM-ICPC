#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <set>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int N = 10004;
const int INF = 0x7fffffff;
vector<int> E[N];
int f[N][2],now;
int n, m;

void dfs(int u,int fa)
{
    f[u][0]=++now;
    f[u][1]=f[fa][0];
    for(int i=0;i<E[u].size();++i){
        int v=E[u][i];
        if(v==fa) continue;
        dfs(v,u);
        swap(f[u][0],f[u][1]);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=2,u,v;i<=n;++i){
        scanf("%d %d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i){
        printf("%d %d\n",f[i][0],f[i][1]);
    }
    return 0;
}