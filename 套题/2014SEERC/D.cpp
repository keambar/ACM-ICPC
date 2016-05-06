#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int x, y, n, k;
bool f[1000006];
int main()
{
    scanf ( "%d %d", &x, &y );
    int d = 2 * ( x + y ) - 4;
    f[1] = 1;
    for ( int i = 2; i <= d / 4; i++ ) {
        if ( d % i == 0 ) {
            int tem = x % i;
            if ( tem == 0 || tem == 1 ) {
                tem = ( y - !tem ) % i;
                if ( tem == 0 || tem == 1 ) {
                    tem = ( x - !tem ) % i;
                    if ( tem == 0 || tem == 1 ) {
                        tem = ( y - 1 - !tem ) % i;
                        if ( tem == 0 ) f[i] = 1;
                    }
                }
            }
            tem = y % i;
            if ( tem == 0 || tem == 1 ) {
                tem = ( x - !tem ) % i;
                if ( tem == 0 || tem == 1 ) {
                    tem = ( y - !tem ) % i;
                    if ( tem == 0 || tem == 1 ) {
                        tem = ( x - 1 - !tem ) % i;
                        if ( tem == 0 ) f[i] = 1;
                    }
                }
            }
        }
    }
    scanf ( "%d", &n );
    while ( n-- ) {
        scanf ( "%d", &k );
        if ( f[k] ) puts ( "YES" );
        else puts ( "NO" );
    }
}