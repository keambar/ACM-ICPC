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
const int N = 5000006;
const int Mod = ( int ) 1e9 + 7;

LL A[N], ma[N], mi[N], a, b;
LL ma1[N], mi1[N];
int f[N], n;
int main()
{
    int T, cs = 0;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d %I64d %I64d", &n, &a, &b );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%I64d", &A[i] );
            if( i == 1 ) ma[i] = A[i], mi[i] = A[i];
            else {
                ma[i] = max( ma[i - 1], A[i] );
                mi[i] = min( mi[i - 1], A[i] );
            }
        }
        for( int i = n; i > 0; --i ) {
            if( i == n ) ma1[i] = A[i], mi1[i] = A[i];
            else {
                ma1[i] = max( ma1[i + 1], A[i] );
                mi1[i] = min( mi1[i + 1], A[i] );
            }
        }
        LL ans, tem;
        if( b > 0 ) {
            ans = max( a * A[1] * A[1] + b * ma1[2], a * A[n] * A[n] + b * ma[n - 1] );
        } else {
            ans = max( a * A[1] * A[1] + b * mi1[2], a * A[n] * A[n] + b * mi[n - 1] );
        }
        for( int i = 2; i < n; ++i ) {
            if( b > 0 ) tem = a * A[i] * A[i] + b * max( ma[i - 1], ma1[i + 1] );
            else tem = a * A[i] * A[i] + b * min( mi[i - 1], mi1[i + 1] );
            ans = max( ans, tem );
        }
        printf( "Case #%d: %I64d\n", ++cs, ans );
    }
}
