#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 100009;

struct node {
    int u, v, ne;
} E[INF << 2];
int head[INF], cnt;

void addedge ( int u, int v )
{
    E[++cnt].u = u, E[cnt].v = v;
    E[cnt].ne = head[u];
    head[u] = cnt;
}

int link[INF], vis[INF];
int n, m;
bool DFS ( int x )
{
    if ( vis[x] ) return 0;
    vis[x] = 1;
    for ( int i = head[x]; i ; i = E[i].ne ) {
        int v = E[i].v;
        if ( link[v] == -1 || DFS ( link[v] ) ) {
            link[v] = x;
            return 1;
        }
    }
    return 0;
}
int make()
{
    int ans = 0;
    memset ( link, -1, sizeof link );
    for ( int i = 0; i < n; i++ ) {
        memset ( vis, 0, sizeof vis );
        if ( DFS ( i ) ) ans++;
    }
    return ans;
}
int main()
{
    scanf ( "%d %d", &n, &m );
    for ( int i = 1, u, v; i <= m; ++i ) {
        scanf ( "%d %d", &u, &v );
        addedge ( u, v );
    }
    int tem = make();
    if ( make() == n ) puts ( "YES" );
    else puts ( "NO" );
}