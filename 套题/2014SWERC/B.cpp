#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;
const int  N = 10005;
struct Edge {
    int u, v, c, ne;
} E[N * 60];
int head[N], cnt;
void addE ( int u, int v, int c )
{
    E[++cnt].v = v, E[cnt].c = c;
    E[cnt].u = u;
    E[cnt].ne = head[u];
    head[u] = cnt;
}
int dis[2][N], vis[N];
void SPFA ( int x, int k )
{
    queue<int> q;
    q.push ( x );
    dis[k][x] = 0;
    while ( !q.empty() ) {
        int u = q.front();
        q.pop();
        for ( int i = head[u]; i; i = E[i].ne ) {
            int v = E[i].v, c = E[i].c;
            if ( dis[k][v] == -1 || dis[k][v] > dis[k][u] + c ) {
                dis[k][v] = dis[k][u] + c;
                if ( !vis[v] ) {
                    q.push ( v );
                    vis[v] = 1;
                }
            }
        }
        vis[u] = 0;
    }
}
int n, m;

int main()
{
    while ( scanf ( "%d %d", &n, &m ) != EOF ) {
        memset(head,0,sizeof head);
        cnt=0;
        for ( int i = 1, u, v, c; i <= m; ++i ) {
            scanf ( "%d %d %d" , &u, &v, &c );
            addE ( u, v, c );
            addE ( v, u, c );
        }
        memset ( dis, -1, sizeof dis );
        SPFA ( 0, 0 ), SPFA ( n - 1, 1 );
        int ans = 0;
        for ( int i = 1; i <= cnt; ++i ) {
            int u = E[i].u, v = E[i].v, c = E[i].c;
            if ( dis[0][u] + dis[1][v] + c == dis[1][0] ) {
                ans += c;
            }
        }
        printf ( "%d\n", ans * 2 );
    }
}
