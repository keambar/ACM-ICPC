#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ULL;
ULL dp[50] = {};
ULL a[] = {0, 1, 3, 5, 9, 11, 15, 19};
ULL g ( long long n )
{
    if ( n < 8 ) return a[n];
    long long i, j;
    for ( i = 1, j = 1; 8 * i < n; i <<= 1, j++ );
    return dp[j] + 2 * g ( n - 4 * i );
}
int main()
{
    dp[1] = 9, dp[2] = 27;
    for ( int i = 3; i < 50; i++ )
        dp[i] = dp[i - 1] * 3;
    long long L, R;
    while ( cin >> L >> R ) {
        if ( L == 0 && R == 0 )
            break;
        ULL ans = g ( R + 1 ) - g ( L );
        cout << ans << endl;
    }
    return 0;
}