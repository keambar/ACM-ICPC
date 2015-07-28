#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int N = 511, base = 51;
char s[N][N];
int a[N][N], b[N][N];
int T, n, m;

int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        memset ( a, 0, sizeof a );
        memset ( b, 0, sizeof b );
        scanf ( "%d", &n );
        for ( int i = 0; i < n; ++i ) {
            scanf ( "%s", s[i] );
        }
        int m = strlen ( s[0] ), ans = 0;
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                if ( s[i][j] == 'R' || s[i][j] == 'G' ) {
                    if ( i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] ) ;
                    else {
                        ++ans;
                    }
                    a[i][j] = 1;
                }
            }
        }
        for ( int i = 0; i < n; ++i ) {
            for ( int j = m - 1; j >= 0; --j ) {
                if ( s[i][j] == 'B' || s[i][j] == 'G' ) {
                    if ( i - 1 >= 0 && j + 1 < m && b[i - 1][j + 1] ) ;
                    else {
                        ++ans;
                    }
                    b[i][j] = 1;
                }
            }
        }
        printf ( "%d\n", ans );
    }
    return 0;
}