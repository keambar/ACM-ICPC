#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;

inline LL f( LL x )
{
    LL b , t , c , m , r;
    b = x & -x;
    t = x + b;
    c = t ^ x;
    m = ( c >> 2 ) / b;
    r = t | m;
    return r;
}
int s( int x )
{
    int res = 0;
    while( x ) {
        if( x & 1 ) ++res;
        x >>= 1;
    }
    return res;
}
int main()
{
    int T, cs = 0;
    scanf( "%d", &T );
    while( T-- ) {
        int D, S1, S2;
        scanf( "%d %d %d", &D, &S1, &S2 );
        int t = s( D );
        if( S1 == 0 ) S1 = 1;
        if( S2 > 32 ) S2 = 32;
        LL ans = f( D );
        LL tmp = D;
        for( int i = t - 1; i >= S1; --i ) {
            tmp -= tmp & -tmp;
            LL x = tmp;
            while( x < D ) {
                x = f( x );
            }
            ans = min( ans, x );
        }
        tmp = D;
        for( int i = t + 1; i <= S2; ++i ) {
            tmp = tmp | ( tmp + 1 );
            LL x = tmp;
            while( x < D ) {
                x = f( x );
            }
            ans = min( ans, x );
        }
        printf( "Case #%d: %I64d\n", ++cs, ans );
    }
}
