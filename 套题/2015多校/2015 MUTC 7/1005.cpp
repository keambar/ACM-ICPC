#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int n, m;
char s[1234567];
int main()
{
    int cs = 0;
    while ( scanf ( "%d %d", &n, &m ) ) {
        if ( m == -1 ) return 0;
        printf ( "Case #%d: ", ++cs );
        int sum[2] = {};
        int tem = 0, len = 0, roll = 0;
        while ( n ) {
            s[++len] = n % 10;
            tem += n % 10;
            n /= 10;
        }
        for ( int i = len; i > 0; --i ) {
            sum[roll] += s[i];
            roll ^= 1;
        }
        while ( m-- ) {
            int t = tem;
            len = 0;
            while ( t ) {
                s[++len] = t % 10;
                tem += t % 10;
                t /= 10;
            }
            for ( int i = len; i > 0; --i ) {
                sum[roll] += s[i];
                roll ^= 1;
            }
        }
        tem = abs ( sum[0] - sum[1] );
        if ( tem % 11 ==0) puts ( "Yes" );
        else puts ( "No" );
    }
    return 0;
}
