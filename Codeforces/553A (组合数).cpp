#include <bits/stdc++.h>
#define LL long long
using namespace std;
const long long  MOD = 1000000007;
LL n, x, tol;
LL ans = 1;
LL dp[1009][1009];

int main()
{
    dp[0][1] = 1;

    for( int i = 1; i <= 1000; ++i ) {
        LL tem = 0;
        for( int j = 1; j <= 1000; ++j ) {
            tem = ( tem + dp[i - 1][j] ) % MOD;
            dp[i][j] = tem  % MOD;
        }
    }
    for( int i = 1; i <= 1000; ++i ) {
        for( int j = 1; j <= 1000; ++j ) {
            dp[i][j] = ( dp[i][j] + dp[i][j - 1] )  % MOD;
        }
    }
    cin >> n;
    for( int i = 1; i <= n; ++i ) {
        cin >> x;
        if( x > 1 ) ans = ans * dp[x - 1][tol + 1] % MOD;
        tol += x;
    }
    cout << ans << endl;
}
