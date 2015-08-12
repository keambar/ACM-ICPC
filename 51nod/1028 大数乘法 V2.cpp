#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500005;

typedef long long LL;
struct C {
    double r, i;
    C() {}
    C ( double _r, double _i ) : r ( _r ), i ( _i ) {}
    inline C operator + ( const C &a ) const
    {
        return C ( r + a.r, i + a.i );
    }
    inline C operator - ( const C &a ) const
    {
        return C ( r - a.r, i - a.i );
    }
    inline C operator * ( const C &a ) const
    {
        return C ( r * a.r - i * a.i, r * a.i + i * a.r );
    }
} a[N], b[N];

const double pi = acos ( -1.0 );
int n, num[N], cnt[N];
LL res[N], sum[N];

void brc ( C *y, int l )
{
    int i, j, k;
    for ( i = 1, j = l >> 1; i < l - 1; ++i ) {
        if ( i < j ) swap ( y[i], y[j] );
        k = l >> 1;
        while ( j >= k ) {
            j -= k;
            k >>= 1;
        }
        j += k;
    }
}

void FFT ( C *y, int l, int on )
{
    int h, i, j, k;
    C u, t;
    brc ( y, l ); // 得到一个自底向上的序列
    for ( h = 2; h <= l; h <<= 1 ) { // 控制一个O(logn)的外层复杂度
        C wn ( cos ( on * 2 * pi / h ), sin ( on * 2 * pi / h ) );
        for ( j = 0; j < l; j += h ) { // 两个for循环共组成O(n)的复杂度
            C w ( 1, 0 );
            for ( k = j; k < j + h / 2; ++k ) {
                u = y[k];
                t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if ( on == 1 ) {
        for ( i = 0; i < l; ++i ) {
            y[i] = y[i] * C ( 1.0 / l, 0.0 );
        }
    }
}
char s1[N], s2[N];
int main()
{
    while ( scanf ( "%s %s", s1, s2 ) != EOF ) {
        memset(res,0,sizeof res);
        int l1 = strlen ( s1 ), l2 = strlen ( s2 );
        int l3 = l1 + l2 + 1, l = 1;
        while ( l <= l3 ) l <<= 1;
        for ( int i = 0; i < l1; ++i ) {
            a[i] = C ( s1[l1 - 1 - i] - '0', 0 );
        }
        for ( int i = l1; i < l; ++i ) {
            a[i] = C ( 0, 0 );
        }
        for ( int i = 0; i < l2; ++i ) {
            b[i] = C ( s2[l2 - 1 - i] - '0', 0 );
        }
        for ( int i = l2; i < l; ++i ) {
            b[i] = C ( 0, 0 );
        }
        FFT ( a, l, -1 );
        FFT ( b, l, -1 );
        for ( int i = 0; i < l; ++i ) {
            a[i] = a[i] * b[i];
        }
        FFT ( a, l, 1 );
        for ( int i = 0; i < l; ++i ) {
            res[i] = ( LL ) ( a[i].r + 0.5 );
        }
        for ( int i = 0; i < l; ++i ) {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
        while ( res[l3] == 0 && l3 > 0 ) l3--;
        for ( int i = l3; i >= 0; --i ) {
            putchar ( res[i] + '0' );
        }
        putchar(10);
    }
    return 0;
}