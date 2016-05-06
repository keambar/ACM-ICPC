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
int main()
{
    int T;
    scanf( "%d", &T );
    int n, m, cs = 0;
    while( T-- ) {
        vector<int> a, b;
        scanf( "%d %d", &n, &m );
        for( int i = 1, x, y; i <= n; ++i ) {
            scanf( "%d %d", &x, &y );
            a.pb( x ), b.pb( y );
        }
        sort( all( a ) ), sort( all( b ) );
        printf( "Case #%d:\n", ++cs );
        for( int i = 1, t; i <= m; ++i ) {
            scanf( "%d", &t );
            int t1 = upper_bound( all( a ) , t ) - a.begin();
            int t2 = lower_bound( all( b ) , t ) - b.begin();
            printf( "%d\n", t1 - t2 );
        }
    }
}