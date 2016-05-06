#include <iostream>
#include <cstring>
#include <cstdio>
#define LL long long
using namespace std;
int T, n, m;
int s[20][20], ans[100005];

inline void rd ( int &xx )
{
    char ch = getchar();
    while ( ch < '0' || ch > '9' ) ch = getchar();
    for ( xx = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        xx = xx * 10 + ( ch - '0' );
}
char o[35];
inline void putnum ( int x )
{
    if ( x == 0 ) {
        puts("0");
        return;
    }
    int i;
    for ( i = 0; x != 0; i++, x /= 10 ) o[i] = x % 10 + '0' ;
    for ( i--; i >= 0; i-- ) putchar ( o[i] );
    putchar ( 10 );
}
int main()
{
    rd ( T );
    while ( T-- ) {
        memset ( s, 0, sizeof s );
        memset ( ans, 0, sizeof ans );
        rd ( n ), rd ( m );
        int a, b;
        for ( int i = 1; i <= n; ++i ) {
            rd ( a ), rd ( b );
            ++s[b][a - 1];
        }
        for ( int i = 1; i <= 16; ++i ) {
            for ( int j = 16; j >= 0; --j )
                s[i][j] += s[i][j + 1];
        }
        for ( int i = 0; i < m; ++i ) {
            int t = 0;
            for ( int j = 1; j <= 16; ++j ) {
                int k = i % j;
                t += s[j][k];
            }
            ++ans[t];
        }
        for ( int i = 0; i <= n; ++i ) {
            putnum ( ans[i] );
        }
    }
}