/*
    记忆化搜索
    dp[p][i][j][k] 记录前p个积木堆成i堆，最后一堆
    的最上面一个积木的摆放方式为k时的最大高度和
*/
#include <algorithm>
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
const int N = 102;
const int Mod = ( int ) 1e9 + 7;

int n, m;
int A[N][3];
int dp[N][N][N][3];
int t[3][3] = {0, 1, 2,   0, 2, 1,    1, 2, 0};
int main()
{
    scanf( "%d %d", &n, &m );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d %d %d", &A[i][0], &A[i][1], &A[i][2] );
        for( int j = 1; j <= 2; ++j ) {
            if( A[i][0] > A[i][j] ) swap( A[i][0], A[i][j] );
        }
        if( A[i][1] > A[i][2] ) swap( A[i][1], A[i][2] );
    }

    memset( dp, -1, sizeof dp );
    dp[0][0][0][0] = 0;
    for( int p = 1; p <= n; ++p ) {//sum
        for( int s = 0; s < 3; ++s ) {
            int a = t[s][0], b = t[s][1];
            for( int i = 0; i <= min( m, p ); ++i ) { //i heap
                for( int j = 0; j <= min( n, p ); ++j ) { //top index
                    for( int k = 0; k < 3; ++k ) {//top face
                        if( dp[p - 1][i][j][k] == -1 ) continue ;
                        dp[p][i][j][k] = max( dp[p][i][j][k], dp[p - 1][i][j][k] );
                        int c = t[k][0], d = t[k][1];
                        if( A[p][a] <= A[j][c] && A[p][b] <= A[j][d] ) {
                            dp[p][i][p][s] = max( dp[p][i][p][s], dp[p - 1][i][j][k] + A[p][t[s][2]] );
                        }
                        dp[p][i + 1][p][s] = max( dp[p][i + 1][p][s], dp[p - 1][i][j][k] + A[p][t[s][2]] );
                    }
                }
            }
        }
    }
    int ans = 0;
    for( int i = 1; i <= n; ++i ) {
        for( int k = 0; k < 3; ++k ) {
            ans = max( ans, dp[n][m][i][k] );
        }
    }
    printf( "%d\n", ans );
    return 0;
}
