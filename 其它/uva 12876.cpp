#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200;
int T, n, m, x;
int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d %d", &n, &m );
        int a = 0, b = 0;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                scanf ( "%d", &x );
                if ( x == -1 )    continue;
                if ( ( i + j ) & 1 )
                    a += x;
                else
                    b += x;
            }
        }
        printf ( "%d\n", abs ( a - b ) );
    }
    return 0;
}