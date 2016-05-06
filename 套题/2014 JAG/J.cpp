#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define LL long long
#define sz( a ) int( a.size() )
#define all( a ) a.begin(), a.end()
#define sd second
#define ft first
const int INF = 0x3f3f3f3f;
const int N = 202;
bool G[N][N], GG[N][N];
int dp[N][10005], vis[N];
int pi[N], ti[N], ci[N];
int n, m, T, ans;
//“多重背包”通用模板
const int MAX_V = 10004;
//v、n、w：当前所处理的这类物品的体积、个数、价值
//V：背包体积， MAX_V：背包的体积上限值
//f[i]：体积为i的背包装前几种物品，能达到的价值上限。
inline void pack ( int f[], int V, int v, int n, int w )
{
    if ( n == 0 || v == 0 ) return;
    if ( n == 1 ) {             //01背包
        for ( int i = V; i >= v; --i )
            if ( f[i] < f[i - v] + w ) f[i] = f[i - v] + w;
        return;
    }
    if ( n * v >= V - v + 1 ) { //完全背包(n >= V / v)
        for ( int i = v; i <= V; ++i )
            if ( f[i] < f[i - v] + w ) f[i] = f[i - v] + w;
        return;
    }

    int va[MAX_V], vb[MAX_V];   //va/vb: 主/辅助队列
    for ( int j = 0; j < v; ++j ) {   //多重背包
        int *pb = va, *pe = va - 1;     //pb/pe分别指向队列首/末元素
        int *qb = vb, *qe = vb - 1;     //qb/qe分别指向辅助队列首/末元素
        for ( int k = j, i = 0; k <= V; k += v, ++i ) {
            if ( pe  == pb + n ) {     //若队列大小达到指定值，第一个元素X出队。
                if ( *pb == *qb ) ++qb; //若辅助队列第一个元素等于X，该元素也出队。
                ++pb;
            }
            int tt = f[k] - i * w;
            *++pe = tt;                  //元素X进队
            //删除辅助队列所有小于X的元素，qb到qe单调递减，也可以用二分法
            while ( qe >= qb && *qe < tt ) --qe;
            *++qe = tt;              //元素X也存放入辅助队列
            f[k] = *qb + i * w;      //辅助队列首元素恒为指定队列所有元素的最大值
        }
    }
}

struct node {
    int u, v, ne;
} E[N*N];
int dfn[N], num[N], sta[N], Tops, tem[N], Topt, scc;

vector<int> a[N];
void dfs ( int k, int t )
{
    sta[++Tops] = tem[++Topt] = k;
    dfn[k] = ++t;
    for ( int i = 1; i <= n; ++i ) {
        if ( G[k][i] == 0 ) continue;
        int v = i;
        if ( !dfn[v] ) dfs ( v, t );
        else if ( num[v] == 0 )
            while ( dfn[sta[Tops]] > dfn[v] ) Tops--;
    }
    if ( sta[Tops] == k ) {
        Tops--, scc++;
        do
            num[tem[Topt]] = scc;
        while ( tem[Topt--] != k );
    }
}
void Garbow ( int n )
{
    memset ( dfn, 0, sizeof dfn );
    memset ( num, 0, sizeof num );
    Tops = Topt = scc = 0;
    for ( int i = 1; i <= n; i++ )
        if ( !num[i] ) dfs ( i, 0 );
}

void make ( int x )
{
    vis[x] = 1;
    for ( int i = 1; i <= scc; ++i ) {
        if ( vis[i] || !GG[x][i] ) continue;
        make ( i );
    }
    for ( int i = 1; i <= scc; ++i ) {
        if ( !GG[x][i] ) continue;
        for ( int j = 0; j <= T; ++j ) {
            dp[x][j] = max ( dp[x][j], dp[i][j] );
        }
    }
    for ( int i = 0; i < sz ( a[x] ); ++i ) {
        int k = a[x][i];
        pack ( dp[x], T, ti[k], ci[k], pi[k] );
    }
    ans = max ( ans, dp[x][T] );
}
int main()
{
    while ( scanf ( "%d %d %d", &n, &m, &T ) != EOF ) {
        if ( n == 0 && m == 0 && T == 0 ) break;
        memset ( dp, 0, sizeof dp );
        memset ( G, 0, sizeof G );
        memset ( GG, 0, sizeof GG );
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d %d %d", &pi[i], &ti[i], &ci[i] );
            a[i].clear();
        }
        for ( int i = 1, u, v; i <= m; ++i ) {
            scanf ( "%d %d", &u, &v );
            G[u][v] = 1;
        }
        Garbow ( n );
        for ( int i = 1; i <= n; ++i ) {
            a[num[i]].pb ( i );
        }
        for ( int i = 1; i <= scc; ++i ) {
            for ( int j = 1; j <= n; ++j ) {
                if ( num[j] != i ) continue;
                for ( int k = 1; k <= n; ++k ) {
                    if ( num[k] == i || G[j][k] == 0 ) continue;
                    GG[i][num[k]] = 1;
                }
            }
        }

        for ( int i = 1; i <= scc; ++i ) {
            if ( sz ( a[i] ) == 1 && G[a[i][0]][a[i][0]] == 0 ) {
                ci[a[i][0]] = 1;
            }
        }
        ans = 0;
        memset ( vis, 0, sizeof vis );
        for ( int i = 1; i <= scc; ++i ) {
            if(!vis[i])
            make ( i );
        }
        printf ( "%d\n", ans );
    }
    return 0 ;
}
