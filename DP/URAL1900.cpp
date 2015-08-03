#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std;
const int N = 555;
const int INF = int ( 1e9 );

int dp[N][N], pr[N][N];
int s[N][N], g[N][N];
int n, k;

void out ( int r, int st )
{
    if ( st == 0 ) return;
    out ( pr[r][st], st - 1 );
    printf ( "%d", r - 1 );
    if ( st == k ) puts ( "" );
    else putchar ( ' ' );
}

int main()
{
    while ( scanf ( "%d%d", &n, &k ) != EOF ) {
        memset ( s, 0, sizeof s );
        for ( int i = 1; i < n; ++i ) {
            for ( int j = i + 1; j <= n; ++j ) {
                scanf ( "%d", &s[i][j] );
                s[i][j] += s[i][j - 1];
            }
        }
        for ( int i = 1; i < n; ++i ) {
            for ( int j = i + 1; j <= n; ++j ) {
                g[i][j] = 0;
                for ( int t = i; t < j; ++t ) {
                    g[i][j] += s[t][n] - s[t][j - 1];
                }
            }
        }
        memset ( dp, -1, sizeof dp );
        dp[1][0] = 0;
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = i + 1; j <= n; ++j ) {
                for ( int t = 1; t <= min ( i, k ); ++ t ) {
                    if ( dp[j][t] < dp[i][t - 1] + g[i][j] )
                        dp[j][t] = dp[i][t - 1] + g[i][j], pr[j][t] = i;
                }
            }
        }
        int ans = -1, id;
        for ( int i = k + 1; i <= n; i ++ ) {
            if ( dp[i][k] > ans ) {
                ans = dp[i][k];
                id = i;
            }
        }
        printf ( "%d\n", ans );
        out ( id, k );
    }
    return 0;
}

