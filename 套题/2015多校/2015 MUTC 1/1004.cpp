#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
const int N = ( int ) 5e4 + 9;
const LL MOD = ( int ) 1e9 + 7;
const int base = 21000;
int a[209];
LL dp[2][N], sp[N];
int n, T;
int main()
{
    //freopen ( "1004.in", "r", stdin );
    scanf ( "%d", &T );
    while ( T-- ) {
        memset ( dp, 0, sizeof dp );
        scanf ( "%d", &n );
        int ss = 0;
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &a[i] );
            ss += a[i];
        }
        ss >>= 1;
        int roll = 0, s = 0;
        dp[roll][base] = 1;
        for ( int i = 1; i <= n; ++i ) {
            roll ^= 1;
            s += a[i];
            memset ( dp[roll], 0, sizeof dp[roll] );
            memset ( sp, 0, sizeof sp );
            int t = a[i], len = min ( s, ss );
            for ( int j = base - len; j <= base + len + 200; ++j ) {
                sp[j] = ( dp[roll ^ 1][j] + sp[j - 2] ) % MOD;
            }
            for ( int j = 0; j <= t; ++j ) {
                dp[roll][base - len] = ( dp[roll][base - len] + ( dp[roll ^ 1][base - len + j] * ( ( t - j ) / 2 + 1 ) ) % MOD ) % MOD;
            }
            for ( int j = base - len + 1; j <= base; ++j ) {
                int l = j, r = j + t, tr = j - t - 1;
                if ( t & 1 ) {
                    dp[roll][j] = ( MOD + dp[roll][j - 1] + ( MOD + sp[r] - sp[l - 1] ) % MOD
                                    - ( sp[l - 2] - sp[tr - 2] + MOD ) % MOD
                                  ) % MOD;
                } else {
                    dp[roll][j] = ( MOD + dp[roll][j - 1] + ( MOD + sp[r] - sp[l - 2] ) % MOD
                                    - ( sp[l - 1] - sp[tr - 2] + MOD ) % MOD
                                  ) % MOD;
                }
            }
            for ( int j = 1; j <= len; ++j ) {
                dp[roll][base + j] = dp[roll][base - j];
            }
        }
        printf ( "%d\n", dp[roll][base] );
    }
}
/*
1
10
1 4 5 6 8 6 4 2 3 1
790647728
*/
