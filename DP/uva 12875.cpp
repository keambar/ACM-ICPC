#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200;
long long dp[N][N];
int a[N][N], b[N][N];
int T, n, m;
int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d %d", &n, &m );
        memset ( dp, 0, sizeof ( dp ) );
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                scanf ( "%d", &a[i][j] );
            }
        }
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                scanf ( "%d", &b[i][j] );
            }
        }

        long long ret = 0;
        for ( int i = 0; i < n; i++ ) {
            dp[i][0] = a[i][0];
        }
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                for ( int k = 0; k < n; k++ ) {
                    dp[k][i + 1] = max ( dp[k][i + 1], dp[j][i] + a[k][i + 1] - b[j][k] );
                }
            }
        }
        for ( int i = 0; i < n; i++ ) {
            ret = max ( ret, dp[i][m - 1] );
        }
        cout << ret << endl;
    }
    return 0;
}
