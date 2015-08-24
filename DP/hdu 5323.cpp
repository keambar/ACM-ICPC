#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;
char st[2000][20];
char k[20];
int dp[20][20];
int len1, len2;
void make( int pos )
{
    int i, j, dp1, dp2, dp3;
    len1 = strlen( st[pos] );
    len2 = strlen( k );
    for( i = 0; i <= len1; i++ )
        dp[i][0] = i;
    for( j = 0; j <= len2; j++ )
        dp[0][j] = j;
    for( i = 0; i < len1; i++ )
        for( j = 0; j < len2; j++ ) {
            dp1 = dp[i][j + 1] + 1;
            dp2 = dp[i + 1][j] + 1;
            dp3 = dp[i][j];
            if( st[pos][i] != k[j] )
                dp3++;
            dp[i + 1][j + 1] = min( dp1, min( dp2, dp3 ) );
        }
}

int main()
{
    int T;
    scanf( "%d", &T );
    int n, m, cs = 0;
    while( T-- ) {
        printf( "Case #%d:\n", ++cs );
        scanf( "%d %d", &n, &m );
        for( int i = 1, x, y; i <= n; ++i ) {
            scanf( "%s", st[i] );
        }
        for( int i = 1, t; i <= m; ++i ) {
            scanf( "%s %d", k, &t );
            int ans = 0;
            for( int j = 1; j <= n; ++j ) {
                make( j );
                if( dp[len1][len2] <= t ) ++ans;
            }
            printf( "%d\n", ans );
        }
    }
}