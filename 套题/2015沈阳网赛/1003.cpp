/*
    hdu 5452
    思路:由于每次都要删除恰好一个树边，那么这个图的割成的两个部分应该各包含了一颗子树。
    对割出以节点x为根的子树来说，代价是这颗子树所有向树外连的边。
    于是，只要求出每个点的子树先外连的边的条数sum[]就行了。
    每次加入一条非树边（u，v），将对u,v的路径上的除了公共祖先的所有点的sum加一，根节点需要特判
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int N = 20004;
const int Mod = ( int ) 1e9 + 7;

struct node {
    int v, ne;
} E[N << 1];
int head[N], cnt;
void add( int u, int v )
{
    E[++cnt].v = v, E[cnt].ne = head[u];
    head[u] = cnt;
}

int fat[N], dfn[N], ti;
int sum[N];
int n, m;

void dfs( int u, int from )
{
    dfn[u] = ++ti;
    fat[u] = from;
    for( int i = head[u]; i; i = E[i].ne ) {
        int v = E[i].v;
        if( v == from ) continue ;
        dfs( v, u );
    }
}

void make( int u, int v )
{
    if( dfn[u] < dfn[v] ) swap( u, v );
    if( dfn[v] == 1 ) ++sum[1];
    while( dfn[u] > dfn[v] ) {
        ++sum[u];
        u = fat[u];
    }
    while( dfn[v] > dfn[u] ) {
        ++sum[v];
        v = fat[v];
    }
}
int main()
{
    int T, cs = 0;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d %d" , &n, &m );
        memset( sum, 0, sizeof sum );
        memset( head, 0, sizeof head );
        cnt = ti = 0;
        for( int i = 1, u, v; i < n; ++i ) {
            scanf( "%d %d", &u, &v );
            add( u, v ), add( v, u );
        }
        dfs( 1, 0 );
        for( int i = n, u, v; i <= m; ++i ) {
            scanf( "%d %d", &u, &v );
            make( u, v );
        }
        int ans = m;
        for( int i = 1; i <= n; ++i ) {
            ans = min( ans, sum[i] );
        }
        printf( "Case #%d: %d\n", ++cs, ans + 1 );
    }
    return 0;
}
