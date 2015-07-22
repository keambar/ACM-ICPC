#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int N = ( int ) 1e5 + 9;

int w[N];
int f[N][109], G[N][109], p[N][109], q[N][109];
int fat[N], now[N];
int n;
vector<int> E[N];

void make ()
{
    stack<int> a;
    a.push ( 1 );
    fat[1] = 0;
    while ( !a.empty() ) {
        int u = a.top();
        int fa = fat[u];
        for ( ; ++now[u] < E[u].size() ; ++now[u] ) {
            int v = E[u][now[u]];
            if ( v == fa )    continue;
            a.push ( v );
            fat[v] = u;
            fa = u;
            u = v;
        }
        if ( E[u].size() == 1 && fa != 0 ) {
            G[u][1] = 0;
        }
        int t = 1;
        for ( int i = 0; i < E[u].size(); ++i ) {
            int v = E[u][i];
            if ( v == fa ) continue;
            t += min ( p[v][w[u] + 1], q[v][w[u]] );
            for ( int j = 0; j < 108; ++j ) {
                if ( f[v][j + 1] == 0x01010101 ) continue;
                int tem = f[v][j + 1];
                for ( int k = 0; k < E[u].size(); ++k ) {
                    int b = E[u][k];
                    if ( b != v && b != fa ) {
                        tem += min ( p[b][j + 1], q[b][j] );
                    }
                }
                f[u][j] = min ( f[u][j], tem );
            }
        }
        f[u][w[u]] = min ( f[u][w[u]], t );

        G[u][0]=f[u][0];
        for ( int i = 0; i < E[u].size(); ++i ) {
            int v = E[u][i];
            if ( v == fa ) continue;
            for ( int j = 1; j < 109; ++j ) {
                if ( G[v][j - 1] == 0x01010101 ) continue;
                int tem = G[v][j - 1];
                for ( int k = 0; k < E[u].size(); ++k ) {
                    int b = E[u][k];
                    if ( b != v && b != fa ) {
                        tem += min ( p[b][j - 1], q[b][j - 1] );
                    }
                }
                G[u][j] = min ( G[u][j], tem );
            }
        }
        p[u][0] = f[u][0];
        q[u][0] = f[u][0];
        for ( int i = 1; i < 109; ++i ) {
            p[u][i] = min ( p[u][i - 1], f[u][i] );
            q[u][i] = min ( q[u][i - 1], G[u][i] );
        }
        a.pop();
    }
}

inline void init()
{
    for ( int i = 1; i <= n; ++i ) E[i].clear();
    memset ( f, 0x1, sizeof f );
    memset ( G, 0x1, sizeof G );
    memset ( p, 0x1, sizeof p );
    memset ( q, 0x1, sizeof q );
    memset ( now, -1, sizeof now );
}

int main()
{
    while ( scanf ( "%d", &n ) != EOF ) {
        init();
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &w[i] );
        }
        for ( int i = 1, u, v; i < n; ++i ) {
            scanf ( "%d %d", &u, &v );
            E[u].push_back ( v );
            E[v].push_back ( u );
        }
        make();
        int ans = n;
        for ( int i = 0; i < 109; ++i ) {
            ans = min ( ans, f[1][i] );
        }
        printf ( "%d\n", ans );
    }
    return 0;
}
