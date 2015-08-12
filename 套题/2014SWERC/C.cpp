#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000005;

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

int main()
{
    while ( scanf ( "%d", &n ) != EOF ) {
        int Max = 0;
        memset ( cnt, 0, sizeof ( cnt ) );
        for ( int i = 0; i < n; ++i ) {
            scanf ( "%d", &num[i] );
            Max = max ( Max, num[i] );
            ++cnt[num[i]];
        }
        int L = 1;
        ++Max;
        while ( L <= ( Max << 1 ) ) L <<= 1;
        for ( int i = 0; i < Max; ++i ) {
            a[i] = C ( cnt[i], 0 );
        }
        for ( int i = Max; i < L; ++i ) {
            a[i] = C ( 0, 0 );
        }
        FFT ( a, L, -1 );
        for ( int i = 0; i < L; ++i ) {
            a[i] = a[i] * a[i];
        }
        FFT ( a, L, 1 );
        for ( int i = 0; i < L; ++i ) {
            res[i] = ( LL ) floor ( a[i].r + 0.5 );
        }
        int m, ans = 0;
        scanf ( "%d", &m );
        for ( int i = 1, x; i <= m; ++i ) {
            scanf ( "%d", &x );
            if ( x <= Max * 2 && ( res[x] || cnt[x] ) ) ++ans;
        }
        printf ( "%d\n", ans );
    }
    return 0;
}
