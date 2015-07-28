#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int INF = 50009;


int E[INF], cnt;

int sum[INF], vis[INF];
int n;


int dfs ( int u )
{
    int tol = 1;
    vis[u] = 1;
    if ( E[u] != 0 && !vis[E[u]] ) {
        tol += dfs ( E[u] );
    }
    vis[u] = 0;
    return sum[u] = tol;
}

int main()
{
    int T;
    scanf ( "%d", &T );
    for ( int t = 1; t <= T; ++t ) {
        memset ( E, 0, sizeof E );
        memset ( sum, 0, sizeof sum );
        cnt = 0;
        scanf ( "%d", &n );
        for ( int i = 1, u, v; i <= n; ++i ) {
            scanf ( "%d %d", &u, &v );
            E[u] = v;
        }
        int ans = 0, m = 0;
        for ( int i = 1; i <= n; ++i ) {
            if ( !sum[i] ) {
                int k = dfs ( i );
                if ( k > m ) {
                    m = k;
                    ans = i;
                }
            }
        }
        printf ( "Case %d: %d\n", t, ans );
    }
}
