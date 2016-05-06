#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 60005;
int s[1000][1000], sum[1000];
int add[1000], a[N], pos[N], p[1000];
int tem1[1000], tem2[1000], tol1, tol2;
int n, m, q, bk, mx, last;

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
        putchar ( '0' );
        return;
    }
    int i;
    for ( i = 0; x != 0; i++, x /= 10 ) o[i] = x % 10 + '0' ;
    for ( i--; i >= 0; i-- ) putchar ( o[i] );
    putchar ( 10 );
}

inline bool cmp ( int x, int y )
{
    return a[x] < a[y];
}

inline void Merge ( int k , int l, int r )
{
    tol1 = 0, tol2 = 0;
    for ( int i = 0; i < sum[k]; ++i ) {
        if ( s[k][i] >= l && s[k][i] <= r )
            tem1[tol1++] = s[k][i];
        else tem2[tol2++] = s[k][i];
    }
    merge ( tem1 , tem1 + tol1 , tem2 , tem2  + tol2, s[k] , cmp );
    a[0] = last + 1 - add[k];
    p[k] = lower_bound ( s[k], s[k] + sum[k], 0, cmp ) - s[k];
}

inline void modify ( int l, int r )
{
    int k = pos[l], t = pos[r];
    if ( k == t ) {
        for ( int i = l; i <= r; ++i ) {
            ++a[i];
        }
        Merge ( k , l, r );
        return ;
    }

    for ( int i = k + ( pos[l - 1] == k ); i <= t - ( pos[r + 1] == t ) ; ++i ) {
        ++add[i];
        a[0] = last + 1 - add[i];
        p[i] = lower_bound ( s[i], s[i] + p[i], 0, cmp ) - s[i];
    }

    if ( pos[l - 1] == k ) {
        for ( int i = l; pos[i] == k; ++i ) {
            ++a[i];
        }
        Merge ( k , l, r );
    }

    if ( pos[r + 1] == t ) {
        for ( int i = r; pos[i] == t; --i ) {
            ++a[i];
        }
        Merge ( t , l, r );
    }
}

inline bool check ( int x )
{
    int ret = 0;
    for ( int i = 1; i <= m; ++i ) {
        a[0] = x - add[i];
        ret += lower_bound ( s[i], s[i] + sum[i], 0, cmp ) - s[i];
    }
    return ret <= n / 2;
}

inline bool cacl ( )
{
    int ret = 0;
    for ( int i = 1; i <= m; ++i ) {
        ret += p[i];
    }
    return ret <= n / 2;
}

int main()
{
    while ( scanf ( "%d %d", &n, &q ) != EOF ) {
        if ( n == 0 && q == 0 ) continue;
        bk = ceil ( sqrt ( 1.*n ) + 0.005 );
        m = ( n - 1 ) / bk + 1;
        for ( int i = 1; i <= m; ++i ) {
            sum[i] = add[i] = 0;
        }
        mx = 0;
        for ( int i = 1; i <= n; ++i ) {
            rd ( a[i] );
            mx = max ( a[i], mx );
            pos[i] = ( i - 1 ) / bk + 1;
            s[pos[i]][sum[pos[i]]++] = i;
        }
        for ( int i = 1; i <= m; ++i ) {
            sort ( s[i], s[i] + sum[i] , cmp );
        }
        int l = 1, r = mx;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            if ( check ( mid ) ) l = mid + 1;
            else r = mid - 1;
        }
        last = l - 1;
        for ( int i = 1; i <= m; ++i ) {
            a[0] = last + 1;
            p[i] = lower_bound ( s[i], s[i] + sum[i], 0, cmp ) - s[i];
        }
        for ( int i = 1; i <= q; ++i ) {
            rd ( l ), rd ( r );
            modify ( l, r );
            if ( cacl ( )  ) {
                ++last;
                for ( int i = 1; i <= m; ++i ) {
                    a[0] = last + 1 - add[i];
                    p[i] = lower_bound ( s[i]+p[i], s[i] + sum[i], 0, cmp ) - s[i];
                }
            }
            putnum ( last );
        }
    }
}
