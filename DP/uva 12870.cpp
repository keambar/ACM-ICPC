#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#define LL long long
using namespace std;
const int N = 130;
int T, n, m;
int s[N][N];
int f[N][N][N], p[N][N][N];
int maxs[N], mins[N];

int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d %d", &n, &m );
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = 1; j <= m; ++j ) {
                scanf ( "%d", &s[i][j] );
            }
        }
        for ( int i = 0; i <= n; ++i ) {
            for ( int j = 0; j <= m; ++j ) {
                for ( int k = 0; k <= 102; ++k ) {
                    f[i][j][k] = 0x3f3f3f3f;
                    p[i][j][k] = 0;
                }
            }
        }
        for ( int i = 1; i <= min ( n, m ); ++i ) {
            mins[i] = 0x3f3f3f3f;
            maxs[i] = 0;
        }
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = 1; j <= m; ++j ) {
                f[i][j][1] = min ( f[i][j][1], s[i][j] );
                p[i][j][1] = max ( p[i][j][1], s[i][j] );
                for ( int k = 1; k <= min ( i, j ); ++k ) {
                    if ( i > 1 ) f[i][j][k] = min ( f[i - 1][j][k], f[i][j][k] );
                    if ( j > 1 ) f[i][j][k] = min ( f[i][j - 1][k], f[i][j][k] );
                    if ( i > 1 && j > 1 )  f[i][j][k] = min ( f[i][j][k],  f[i - 1][j - 1][k - 1] + s[i][j] ) ;

                    if ( i > 1 ) p[i][j][k] = max ( p[i - 1][j][k], p[i][j][k] );
                    if ( j > 1 ) p[i][j][k] = max ( p[i][j - 1][k], p[i][j][k] );
                    if ( i > 1 && j > 1 )  p[i][j][k] = max ( p[i][j][k], p[i - 1][j - 1][k - 1] + s[i][j] );
                }

                for ( int k = 1; k <= min ( i, j ); ++k ) {
                    mins[k] = min ( mins[k], f[i][j][k] );
                    maxs[k] = max ( maxs[k], p[i][j][k] );
                }
            }
        }

        int ans = 0, len = min ( n, m ) / 2;

        for ( int i = 1; i <= len; ++i ) {
            ans = max ( ans, maxs[i] - mins[i * 2] );
        }
        printf ( "%d\n", ans );
    }
}