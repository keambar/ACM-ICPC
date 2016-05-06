#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int N = 16;
const int Mod = ( int ) 1e9 + 7;

int dp[N][10][10][10][10];
int s[N][N], g[N][N], t[N][N];
int n;

inline int Sum( int x1, int y1, int x2, int y2 )
{
    int tem = s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1 - 1][y1 - 1];
    return tem * tem;
}
int cut( int k, int x1, int y1, int x2, int y2 )
{
    if( ~dp[k][x1][y1][x2][y2] ) return dp[k][x1][y1][x2][y2];
    if( k == 1 ) {
        return dp[k][x1][y1][x2][y2] = Sum( x1, y1, x2, y2 );
    }
    int tem = 0x7ffffff;
    for( int a = x1; a < x2; ++a ) {
        tem = min( min( cut( k - 1, x1, y1, a, y2 ) + Sum( a + 1, y1, x2, y2 ),
                        cut( k - 1, a + 1, y1, x2, y2 ) + Sum( x1, y1, a, y2 ) ), tem );
    }
    for( int b = y1; b < y2; ++b ) {
        tem = min( min( cut( k - 1, x1, y1, x2, b ) + Sum( x1, b + 1, x2, y2 ),
                        cut( k - 1, x1, b + 1, x2, y2 ) + Sum( x1, y1, x2, b ) ), tem );

    }
    return dp[k][x1][y1][x2][y2] = tem;
}

int main()
{
    scanf( "%d", &n );
    memset( dp, -1, sizeof dp );
    double S = 0;
    for( int i = 1; i <= 8; ++i ) {
        for( int j = 1; j <= 8; ++j ) {
            scanf( "%d", &g[i][j] );
            S += g[i][j] * 1.;
            t[i][j] = t[i - 1][j] + g[i][j];
            s[i][j] = s[i][j - 1] + t[i][j];
        }
    }
    S /= n;
    double ans = sqrt( cut( n, 1, 1, 8, 8 ) * 1. / n - S * S );
    printf( "%.3f\n", ans );
}

