#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <set>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int N = 2009;
const int INF = 0x7fffffff;
int n, m;
int a[N], s[N];
int f[N][30];
int main()
{
    while ( scanf ( "%d %d", &n, &m ) != EOF ) {
        memset ( s, 0, sizeof s );
        memset ( f, 0x7, sizeof f );
        ++m;
        for ( int i = 1; i <= n; i++ ) {
            scanf ( "%d", &a[i] );
            s[i] = s[i - 1] + a[i];
        }
        f[0][0] = 0;
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = 1; j <= m; ++j ) {
                for ( int k = 0; k < i; ++k ) {
                    int pay = s[i] - s[k], tem = pay % 10;
                    pay -= tem;
                    if ( tem >= 5 )  pay += 10;
                    f[i][j] = min ( f[i][j], f[k][j - 1] + pay );
                }
            }
        }
        int ans = INF;
        for ( int i = 1; i <= m; i++ ) {
            ans = min ( ans, f[n][i] );
        }
        printf ( "%d\n", ans );
    }
    return 0;
}