/*
    将原序列预处理成若干块，记录前一个相同块的位置。
    dp[i][j][k]存从第i块到第j块，j后面长度为k与j同色的合并消除的最大得分
*/
#include <iostream>
#include <cstring>
#include <cstdio>
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

int color[202], le[202];
int head[202], pr[202];
int dp[202][202][202];
int n;

int make( int l, int r, int k )
{
    if( l > r ) return 0;
    if( dp[l][r][k] > 0 ) return dp[l][r][k];
    dp[l][r][k] = make( l, r - 1, 0 ) + ( le[r] + k ) * ( le[r] + k ) ;
    for( int x = pr[r]; x >= l; x = pr[x] ) {
        dp[l][r][k] = max( dp[l][r][k] , make( l, x, le[r] + k ) + make( x + 1, r - 1, 0 ) );
    }
    return dp[l][r][k];
}

int main()
{
    int T, cs = 0;
    scanf( "%d", &T );
    while( T-- ) {
        memset( dp, 0, sizeof dp );
        memset( head, 0, sizeof head );
        memset( le, 0, sizeof le );
        scanf( "%d", &n );
        int t = 0;
        for( int i = 1, x; i <= n; ++i ) {
            scanf( "%d", &x );
            if( x != color[t] ) {
                color[++t] = x;
                pr[t] = head[x];
                head[x] = t;
            }
            ++le[t];
        }
        printf( "Case %d: %d\n", ++cs, make( 1, t, 0 ) );
    }
}
