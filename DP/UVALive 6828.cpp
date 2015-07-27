#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
    int v, c, d, next;
} E[300005];
int head[100005], cnt = 1;
int f[100005][2];
int vis[100005];
int go[100005];
int n, m;

void addE ( int u, int v, int c )
{
    E[++cnt].v = v, E[cnt].c = c, E[cnt].d = 0;
    E[cnt].next = head[u], head[u] = cnt;
    E[++cnt].v = u, E[cnt].c = c, E[cnt].d = 1;
    E[cnt].next = head[v], head[v] = cnt;
}
int dfs ( int u )
{
    go[u] = 1;
    int ok = vis[u];
    int s = 0, m = 0, k = 0;
    for ( int i = head[u]; i; i = E[i].next ) {
        int v = E[i].v, c = E[i].c;
        if ( go[v] ) continue;
        int has = dfs ( v );
        if ( has ) {
            f[u][1] += f[v][1] + c;
            if ( m < ( ( f[v][1] + c ) - ( f[v][0] + c * E[i].d ) ) ) {
                m = ( ( f[v][1] + c ) - ( f[v][0] + c * E[i].d ) );
            }
            ok = has;
        }
    }
    f[u][0] = f[u][1]  - m;
    return ok;
}
void init()
{
    cnt=1;
    memset(f,0,sizeof f);
    memset(vis,0,sizeof vis);
    memset(go,0,sizeof go);
    memset(head,0,sizeof head);
}
int main()
{
    while ( scanf ( "%d %d", &n, &m ) != EOF ) {
        init();
        for ( int i = 1, u, v, w; i < n; ++i ) {
            scanf ( "%d %d %d", &u, &v , &w );
            addE ( u, v, w );
        }
        for ( int i = 1, k; i <= m; ++i ) {
            scanf ( "%d", &k );
            vis[k] = 1;
        }
        dfs ( 1 );
        printf ( "%d\n", f[1][0] );
    }
    return 0;
}
