/*
    括号序列 dp
	注意空串
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
const int N = 1e2 + 2;
const int Mod = ( int ) 1e9 + 7;

int path[N][N];
int dp[N][N];
char s[N];

void out( int l, int r )
{
    if( l > r ) return ;
    if( l == r ) {
        if( s[l] == '(' || s[l] == ')' ) {
            printf( "()" );
        } else {
            printf( "[]" );
        }
    } else if( !~path[l][r] ) {
        putchar( s[l] );
        if( l + 1 < r ) out( l + 1, r - 1 );
        putchar( s[r] );
    } else {
        out( l, path[l][r] );
        out( path[l][r] + 1, r );
    }
}
int main()
{
    memset( dp, 0x3f, sizeof dp );
    memset( path, -1, sizeof path );
    scanf( "%s", s );
    int n = strlen( s );
    for( int i = 0; i < n; ++i ) {
        dp[i][i] = 1;
    }
    for( int i = 1; i < n; ++i ) {
        for( int j = 0; j + i < n; ++j ) {
            int l = j, r = i + j;
            if( ( s[l] == '(' && s[r] == ')' ) || ( s[l] == '[' && s[r] == ']' ) ) {
                if( l + 1 < r )
                    dp[l][r] = dp[l + 1][r - 1];
                else
                    dp[l][r] = 0;
            }
            for( int k = l; k < r; ++k ) {
                if( dp[l][r] > dp[l][k] + dp[k + 1][r] ) {
                    dp[l][r] = dp[l][k] + dp[k + 1][r];
                    path[l][r] = k;
                }
            }
        }
    }
    out( 0, n - 1 );
    putchar(10);
    return 0;
}
