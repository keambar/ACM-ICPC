#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int N = 11111;
typedef pair<int, int> ii;
vector<int> E[N];
vector<ii> h, qus;
int vis[N], ans[N];
int n, m, T, q;
int mdeep, k, sum;

int dfs ( int u, int fa, int deep )
{
    if ( !vis[u] ) {
        vis[u] = 1;
        ++sum;
    }
    if ( mdeep < deep ) {
        mdeep = deep;
        k = u;
    }
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i];
        if ( v == fa ) continue;
        dfs ( v, u, deep + 1 );
    }
}
void make ( int u )
{
    mdeep = k = sum = 0;
    dfs ( u, 0, 1 );
    dfs ( k, 0, 1 );
    h.push_back ( make_pair ( mdeep, sum ) );
}
void init()
{
    h.clear();
    qus.clear();
    for ( int i = 1; i <= n; ++i ) E[i].clear();
    memset ( vis, 0, sizeof vis );
}

int main()
{
    scanf ( "%d", &T );
    for ( int cas = 1; cas <= T; ++cas ) {
        scanf ( "%d %d", &n, &m );
        init();
        for ( int i = 1, u, v; i <= m; ++i ) {
            scanf ( "%d %d", &u, &v );
            E[u].push_back ( v );
            E[v].push_back ( u );
        }
        for ( int i = 1; i <= n; ++i ) {
            if ( !vis[i] ) {
                make ( i );
            }
        }

        scanf ( "%d", &q );
        for ( int i = 1; i <= q; ++i ) {
            scanf ( "%d", &k );
            qus.push_back ( make_pair ( k, i ) );
        }
        sort ( qus.begin(), qus.end() );
        sort ( h.begin(), h.end() );
        for ( int i = 0, j = h.size() - 1; i < qus.size(); ++i ) {
            while ( j >= 0 && h[j].second < qus[i].first ) --j;
            if ( j >= 0 ) ans[qus[i].second] = 2 * qus[i].first - min ( qus[i].first, h[j].first ) - 1;
            else ans[qus[i].second] = -1;
        }
        printf("Case %d:\n",cas);
        for ( int i = 1; i <= q; ++i ) {
            if ( ans[i] == -1 ) puts ( "impossible" );
            else printf ( "%d\n", ans[i] );
        }
    }
    return 0;
}
