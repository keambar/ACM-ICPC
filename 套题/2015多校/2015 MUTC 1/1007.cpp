#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#define ll long long
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;

const int N = 100009;
const int INF = 31110;
struct ed {
    int u, v, w, next, ok;
} E[N << 1];
int head[N], cnt;

struct node {
    int v, c, next;
} edge[N << 1];
int  pHead[INF], SS, ST, nCnt;

int dis[2][INF];
int pd[INF];
int n, m;

void addE ( int u, int v, int w )
{
    E[++cnt].v = v, E[cnt].w = w, E[cnt].ok = 0, E[cnt].u = u;
    E[cnt].next = head[u], head[u] = cnt;
}

void init()
{
    cnt = 0;
    nCnt = 0;
    memset ( head, 0, sizeof head );
    memset ( pHead, 0, sizeof pHead );
    memset ( dis, -1, sizeof dis );
    memset ( pd, 0, sizeof pd );
}

void spfa ( int k, int s )
{
    queue<int> q;
    int vis[INF] = {};
    q.push ( s );
    vis[s] = 1;
    dis[k][s] = 0;
    while ( !q.empty() ) {
        int u = q.front();
        q.pop();
        for ( int i = head[u]; i; i = E[i].next ) {
            int v = E[i].v, w = E[i].w;
            if ( dis[k][u] + w < dis[k][v] || dis[k][v] == -1 ) {
                dis[k][v] = dis[k][u] + w;
                if ( !vis[v] ) vis[v] = 1, q.push ( v );
            }
        }
        vis[u] = 0;
    }
}

void addEdge ( int u, int v, int c )
{
    edge[++nCnt].v = v,edge[nCnt].c = c, edge[nCnt].next = pHead[u];
    pHead[u] = nCnt;
    edge[++nCnt].v = u,
    edge[nCnt].c = 0, edge[nCnt].next = pHead[v];
    pHead[v] = nCnt;
}
int SAP ( int pStart, int pEnd, int N )
{
    int numh[INF], h[INF], curEdge[INF], pre[INF];
    int cur_flow, flow_ans = 0, u, neck, i, tmp;
    ms ( h, 0 );
    ms ( numh, 0 );
    ms ( pre, -1 );
    for ( i = 0; i <= N; i++ ) curEdge[i] = pHead[i];
    numh[0] = N;
    u = pStart;
    while ( h[pStart] <= N ) {
        if ( u == pEnd ) {
            cur_flow = 1e9;
            for ( i = pStart; i != pEnd; i = edge[curEdge[i]].v )
                if ( cur_flow > edge[curEdge[i]].c ) neck = i, cur_flow = edge[curEdge[i]].c;
            for ( i = pStart; i != pEnd; i = edge[curEdge[i]].v ) {
                tmp = curEdge[i];
                edge[tmp].c -= cur_flow, edge[tmp ^ 1].c += cur_flow;
            }
            flow_ans += cur_flow;
            u = neck;
        }
        for ( i = curEdge[u]; i != 0; i = edge[i].next )
            if ( edge[i].c && h[u] == h[edge[i].v] + 1 )     break;

        if ( i != 0 ) {
            curEdge[u] = i, pre[edge[i].v] = u;
            u = edge[i].v;
        } else {
            if ( 0 == --numh[h[u]] ) continue;
            curEdge[u] = pHead[u];
            for ( tmp = N, i = pHead[u]; i != 0; i = edge[i].next )
                if ( edge[i].c )  tmp = min ( tmp, h[edge[i].v] );
            h[u] = tmp + 1;
            ++numh[h[u]];
            if ( u != pStart ) u = pre[u];
        }
    }
    return flow_ans;
}

int make()
{
    for ( int i = 1; i <= cnt; ++i ) {
        if ( E[i].ok == 0 ) continue;
        int u = E[i].u, v = E[i].v;
        addEdge ( u, v, 1 );
    }
    printf ( "%d ", SAP ( 1, n, n ) );
    return 0;
}

int main()
{
    while ( scanf ( "%d %d", &n, &m ) != EOF ) {
        init();
        for ( int i = 1, u, v, w; i <= m; ++i ) {
            scanf ( "%d %d %d", &u, &v, &w );
            addE ( u, v, w ), addE ( v, u, w );
        }
        spfa ( 0, 1 );
        spfa ( 1, n );
        for ( int i = 1; i <= n; ++i ) {
            if ( dis[0][i] + dis[1][i] == dis[0][n] ) {
                pd[i] = 1;
            }
        }
        for ( int i = 1; i <= cnt; ++i ) {
            int u = E[i].u, v = E[i].v, w = E[i].w;
            if ( dis[0][u] + w == dis[0][v] && pd[v]) {
                E[i].ok = 1;
            }
        }
        make();
        queue<int> q;
        int vis[INF] = {}, diss[INF];
        ms ( diss, -1 );
        q.push ( 1 );
        vis[1] = 1;
        diss[1] = 0;
        while ( !q.empty() ) {
            int u = q.front();
            q.pop();
            for ( int i = pHead[u]; i; i = edge[i].next ) {
                int v = edge[i].v;
                if ( diss[u] + 1 < diss[v] || diss[v] == -1 ) {
                    diss[v] = diss[u] + 1;
                    if ( !vis[v] ) vis[v] = 1, q.push ( v );
                }
            }
            vis[u] = 0;
        }
        printf ( "%d\n", m - diss[n] );
    }
    return 0;
}
