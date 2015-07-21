/*
       Ïß¶ÎÊ÷
*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int MAX = 111111;
int w[MAX], to[MAX];
int tl[MAX << 3], tr[MAX << 3], flag[MAX << 3], sum[MAX << 3][2];
int l, r;
struct Edge {
    int v, ne;
} edge[MAX << 1];

int head[MAX], cnt, num;

void Dfs ( int u )
{
    w[u] = ++num;
    for ( int i = head[u]; i != 0; i = edge[i].ne ) {
        Dfs ( edge[i].v );
    }
    to[u] = num;
}

void addE ( int u, int v )
{
    edge[++cnt].v = v;
    edge[cnt].ne = head[u], head[u] = cnt;
}

void build ( int x, int l, int r )
{
    flag[x] = sum[x][0] = sum[x][1] = 0;
    tl[x] = l, tr[x] = r;
    if ( l == r ) {
        sum[x][0] = 1;
        return ;
    }
    int mid = ( l + r ) >> 1;
    build ( lson, l, mid ), build ( rson, mid + 1, r );
    sum[x][0] += sum[lson][0] + sum[rson][0];
}

void push ( int x )
{
    if ( flag[x] == 0 ) return;
    flag[x] = 0;
    flag[lson] ^= 1;
    swap ( sum[lson][0], sum[lson][1] );
    flag[rson] ^= 1;
    swap ( sum[rson][0], sum[rson][1] );
}
void updata ( int x )
{
    sum[x][0] = sum[lson][0] + sum[rson][0];
    sum[x][1] = sum[lson][1] + sum[rson][1];
}
void modify ( int x )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        flag[x] ^= 1;
        swap ( sum[x][0], sum[x][1] );
        return ;
    }
    push ( x );
    int mid = ( tl[x] + tr[x] ) >> 1;
    if ( l <= mid ) modify ( lson );
    if ( r > mid ) modify ( rson );
    updata ( x );
}

int query ( int x )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        return sum[x][1];
    }
    push ( x );
    int mid = ( tl[x] + tr[x] ) >> 1, ans = 0;
    if ( l <= mid ) ans += query ( lson );
    if ( r > mid ) ans += query ( rson );
    updata ( x );
    return ans;
}

int n, m;

void init()
{
    num = cnt = 0;
    memset ( head, 0, sizeof head );
}
int main()
{
    while ( scanf ( "%d %d", &n, &m ) != EOF ) {
        init();
        for ( int i = 2, v; i <= n; i++ ) {
            scanf ( "%d", &v );
            addE ( v, i );
        }
        Dfs ( 1 );
        scanf ( "%d", &m );
        build ( 1, 1, n );
        char cmd[10];
        for ( int i = 1, u; i <= m; ++i ) {
            scanf ( "%s %d", cmd, &u );
            l = w[u], r = to[u];
            if ( cmd[0] == 'o' ) {
                modify ( 1 );
            } else {
                printf ( "%d\n", query ( 1 ) );
            }
        }
        putchar(10);
    }
}
