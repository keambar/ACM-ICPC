#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;

const int N = 1000009;
int T, n;
LL a[N];
int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d", &n );
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%I64d", &a[i] );
        }
        int ans = ( n == 1 ? 1 : 2 );
        for ( int k = 1, t = 1; k < n; ++k ) {
            if ( a[k + 1] - a[k] == a[k] - a[k - 1] ) ans = max ( ans, ++t );
            else t = 2;
        }
        for ( int k = 2, t = 2; k < n; ++k ) {
            if ( a[k + 1] * a[k - 1] == a[k] * a[k] ) ans = max ( ans, ++t );
            else t = 2;
        }
        printf ( "%d\n", ans );
    }
    return 0;
}
