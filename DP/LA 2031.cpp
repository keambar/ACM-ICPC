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

int dp[2][5][5];
int c[5][5] = {
    0, 2, 2, 2, 2 ,
    0, 1, 3, 4, 3,
    0, 3, 1, 3, 4 ,
    0, 4, 3, 1, 3 ,
    0, 3, 4, 3, 1 ,
};
int main()
{
    int x;
    while( scanf( "%d", &x ), x ) {
        memset( dp, -1, sizeof dp );
        int roll = 0;
        dp[roll][x][0] = dp[roll][0][x] = 2;
        int k;
        while( scanf( "%d", &k ), k ) {
            for( int i = 0; i < 5; ++i ) {
                if( dp[roll][i][x] == -1 ) continue ;
                if( ( i != k ) && ( dp[roll ^ 1][i][k] == -1 || dp[roll ^ 1][i][k] > dp[roll][i][x] + c[x][k] ) ) {
                    dp[roll ^ 1][k][i] = dp[roll ^ 1][i][k] = dp[roll][i][x] + c[x][k];
                }
                if( ( x != k ) && ( dp[roll ^ 1][x][k] == -1 || dp[roll ^ 1][x][k] > dp[roll][x][i] + c[i][k] ) ) {
                    dp[roll ^ 1][x][k] = dp[roll ^ 1][k][x] = dp[roll][x][i] + c[i][k];
                }
            }
            x = k;
            memset( dp[roll], -1, sizeof dp[roll] );
            roll ^= 1;
        }
        int ans = 0x7fffffff;
        for( int i = 0; i < 5; ++i ) {
            if( ~dp[roll][i][x] && i != x )
                ans = min( ans, dp[roll][i][x] );
        }
        printf( "%d\n", ans );
    }
}
