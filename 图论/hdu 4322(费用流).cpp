#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int INF = 1100, Maxn = 0x3f3f3f3f;
struct node {
    int u, v, t, c, next;
} edge[INF * INF << 2];
int head[INF], nCnt = 1;

void addEdge( int u, int v, int traffic, int cost )
{
    edge[++nCnt].v = v, edge[nCnt].u = u, edge[nCnt].t = traffic, edge[nCnt].c = cost;
    edge[nCnt].next = head[u], head[u] = nCnt;
    edge[++nCnt].v = u, edge[nCnt].u = v, edge[nCnt].t = 0, edge[nCnt].c = -cost;
    edge[nCnt].next = head[v], head[v] = nCnt;
}
int max_flow, min_cost;
int n, m, SS, ST, S, T, K, sum;
int a[20][20], b[20];
int SPFA()
{
    queue<int> ql;
    int vis[INF] = {0}, dis[INF], pre[INF] = {0};
    ql.push( SS );
    memset( dis, 0x3f, sizeof dis );
    vis[SS] = 1, dis[SS] = 0;
    while( !ql.empty() ) {
        int x = ql.front();
        ql.pop();
        for( int i = head[x]; i != 0; i = edge[i].next ) {
            if( edge[i].t == 0 ) continue;
            int v = edge[i].v, c = edge[i].c;
            if( dis[v] > dis[x] + c ) {
                dis[v] = dis[x] + c;
                pre[v] = i;
                if( !vis[v] )
                    ql.push( v ), vis[v] = 1;
            }
        }
        vis[x] = 0;
    }
    if( dis[ST] == Maxn ) return 0;
    else {
        min_cost += dis[ST];
        int k = pre[ST];
        int cur_flow = Maxn;
        while( k ) {
            if( cur_flow > edge[k].t ) cur_flow = edge[k].t;
            k = pre[edge[k].u];
        }
        max_flow += cur_flow;
        k = pre[ST];
        while( k ) {
            edge[k].t -= cur_flow, edge[k ^ 1].t += cur_flow;
            k = pre[edge[k].u];
        }
        return 1;
    }
}

void build()
{
    memset( head, 0, sizeof head );
    nCnt = 1;
    scanf( "%d %d %d", &n, &m, &K );
    sum = 0;
    for( int i = 1; i <= m; ++i ) {
        scanf( "%d", &b[i] );
        sum += b[i];
    }
    SS = 0, ST = m + n + 1;
    for( int i = 1; i <= n; ++i ) {
        addEdge( SS, i, 1, 0 );
    }
    for( int i = 1; i <= m; ++i ) {
        addEdge( n + i, ST, b[i] / K, -K );
        if( b[i] % K > 1 ) addEdge( n + i, ST, 1, -( b[i] % K ) );
    }
    for( int i = 1; i <= m; ++i ) {
        for( int j = 1; j <= n; ++j ) {
            scanf( "%d", &a[i][j] );
            if( a[i][j] ) {
                addEdge( j, n + i, 1, 0 );
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for( int cs = 1; cs <= T; ++cs ) {
        build();
        max_flow = min_cost = 0;
        while( SPFA() );
        printf( "Case #%d: ", cs );
        if( n - max_flow >= sum + min_cost ) {
            puts( "YES" );
        } else {
            puts( "NO" );
        }
    }
    return 0;
}