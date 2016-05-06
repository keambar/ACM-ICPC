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
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;

struct edge {
    int v, ne;
} E[N << 1];
int head[N], cnt;
int vis[N], Val[N], Deg[N], sum[N];
LL ans[N];
int n, m, tol;

void addE( int u, int v )
{
    E[++cnt].v = v, E[cnt].ne = head[u];
    head[u] = cnt;
}

void dfs( int u )
{
    ++sum[tol];
    vis[u] = tol;
    ans[tol] += Val[u];
    for( int i = head[u]; i; i = E[i].ne ) {
        int v = E[i].v;
        if( !vis[v] ) {
            dfs( v );
        }
    }
}
int main()
{
    int T;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d %d", &n, &m );
        memset( head, 0, sizeof head );
        memset( Deg, 0, sizeof Deg );
        memset( vis, 0, sizeof vis );
        cnt = 0;
        tol = 1;
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d", &Val[i] );
        }
        for( int i = 1, u, v; i <= m; ++i ) {
            scanf( "%d %d", &u, &v );
            addE( u, v ), addE( v, u );
            ++Deg[u], ++Deg[v];
        }
        queue<int> tem;
        for( int i = 1; i <= n; ++i ) {
            if( Deg[i] < 2 ) {
                vis[i] = 1;
                tem.push( i );
            }
        }
        while( !tem.empty() ) {
            int x = tem.front();
            tem.pop();
            for( int i = head[x]; i; i = E[i].ne ) {
                int v = E[i].v;
                if( vis[v] )  continue ;
                if( --Deg[v] < 2 ) {
                    vis[v] = 1;
                    tem.push( v );
                }
            }
        }
        for( int i = 1; i <= n; ++i ) {
            if( !vis[i] )   {
                ++tol;
                sum[tol] = ans[tol] = 0;
                dfs( i );
            }
        }
        LL res = 0;
        for( int i = 2; i <= tol; ++i ) {
            if( sum[i] & 1 ) {
                res += ans[i];
            }
        }
        printf( "%I64d\n", res );
    }
    return 0;
}