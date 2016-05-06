#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 500005;
long long n, m;
int To[N][2], Sta[N], Deg[N];
long long Sum[N];
int main()
{
    while ( cin >> n >> m ) {
        char st[5];
        memset ( Deg, 0, sizeof Deg );
        memset ( Sum, 0, sizeof Sum );
        for ( int i = 1, x, y; i <= m; ++i ) {
            scanf ( "%s %d %d", st, &x, &y );
            Sta[i] = ( st[0] == 'R' );
            To[i][0] = x, ++Deg[x];
            To[i][1] = y, ++Deg[y];
        }
        vector<int> dfn;
        for ( int i = 1; i <= m; ++i ) {
            if ( Deg[i] == 0 )
                dfn.push_back ( i );
        }
        for ( int i = 0; i < dfn.size(); ++i ) {
            int u = dfn[i];
            int x = To[u][0], y = To[u][1];
            if ( --Deg[x] == 0 ) dfn.push_back ( x );
            if ( --Deg[y] == 0 ) dfn.push_back ( y );
        }
        Sum[1] = n;
        for ( int i = 0; i < dfn.size(); ++i ) {
            int u = dfn[i];
            int x = To[u][0], y = To[u][1];
            Sum[x] += Sum[u] / 2, Sum[y] += Sum[u] / 2;
            Sum[To[u][Sta[u]]] += Sum[u] & 1;
            Sta[u] ^= Sum[u] & 1;
        }
        for ( int i = 1; i <= m; ++i ) {
            putchar ( Sta[i] ? 'R' : 'L' );
        }
        putchar ( 10 );
    }
}
