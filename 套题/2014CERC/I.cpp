#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
const int N = 100005;
int s[N];
char f[N];

inline int gcd ( int x, int y )
{
    return  y ? gcd ( y, x % y ) : x;
}
int main()
{
    int T, n;
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d", &n );
        int sb = 0, sw = 0;
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d %c", &s[i], &f[i] );
            if ( f[i] == 'W' ) sw += s[i];
            else sb += s[i];
        }
        if ( sw == 0 ) {
            printf ( "%d\n", sb );
            continue;
        }
        if ( sb == 0 ) {
            printf ( "%d\n", sw );
            continue;
        }
        int d = gcd ( sw, sb );
        sw /= d;
        sb /= d;
        int w = 0, b = 0;
        int ans = 0;
        for ( int i = 1; i <= n; i++ ) {
            if ( f[i] == 'W' ) {
                if ( b > 0 && b % sb == 0 ) {
                    int tw = sw * ( b / sb );
                    if ( w < tw && w + s[i] >= tw ) {
                        ++ans;
                        w -= tw;
                        b = 0;
                    }
                }
                w += s[i];
            } else {
                if ( w > 0 && w % sw == 0 ) {
                    int tb = sb * ( w / sw );
                    if ( b < tb && b + s[i] >= tb ) {
                        ++ans;
                        b -= tb;
                        w = 0;
                    }
                }
                b += s[i];
            }
        }
        printf ( "%d\n", ans );
    }
}