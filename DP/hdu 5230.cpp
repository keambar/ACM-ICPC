#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 123456;
const int MOD = 998244353;

int ans[N];
int dp[2][N];

int main()
{
    int CS;

    int roll = 1;
    dp[1][1] = 1;

    for( int i = 1; i <= 450; ++i ) {
        for( int j = 1; j <= 100000; ++j ) {
            if( dp[roll][j] != 0 ) {
                dp[roll][j + i] = ( dp[roll][j + i] + dp[roll][j] ) % MOD;
                dp[roll^1][j + i+1] = ( dp[roll^1][j + i+1] + dp[roll][j] ) % MOD;
            }

            ans[j] = ( ans[j] + dp[roll][j] ) % MOD;
            dp[roll][j]=0;
        }
        roll ^= 1;
    }

    for( int i = 1; i <= 100000; ++i ) {
        ans[i] = ( ans[i - 1] + ans[i] ) % MOD;
    }

    scanf( "%d", &CS );

    for( int i = 1; i <= CS; ++i ) {
        int c, n, l, r;
        scanf( "%d %d %d %d", &n, &c, &l, &r );
        l -= c, r -= c, --n;
        int out = ans[r];

        if( l > 0 ) out = ( out + MOD - ans[l - 1] ) % MOD;
        else out++;

        printf( "%d\n", out );
    }
}
