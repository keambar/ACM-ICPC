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
const int N = 100005;
const int Mod = ( int ) 1e9 + 7;

int a[N], n, L;

int f[N], t[N], pd[N];
int S[N];
void modify ( int x, int k )
{
    for ( x; x <= N; x += x & -x )
        S[x] = max ( S[x], k );
}

int getnum ( int x )
{
    int ans = 0;
    for ( x; x > 0; x -= x & -x )
        ans = max ( ans, S[x] );
    return ans;
}
int main()
{
    int T, cs = 0;
    scanf( "%d", &T );
    while( T-- ) {
        memset( S, 0, sizeof S );
        vector<int> b;
        scanf ( "%d %d", &n , &L );
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", a + i );
            b.push_back ( a[i] );
        }
        sort ( b.begin(), b.end() );
        b.erase ( unique ( b.begin(), b.end() ), b.end() );
        for ( int i = 1; i <= n; ++i ) {
            a[i] = lower_bound ( b.begin(), b.end(), a[i] ) - b.begin() + 1;
        }
        vector<int> ast;
        vector<int> ::iterator it;
        for ( int i = 1; i <= n; ++i ) {
            it = lower_bound ( all ( ast ), a[i] );
            t[i] = it - ast.begin() + 1;
            if ( it == ast.end() ) ast.pb ( a[i] );
            else *it = min ( *it, a[i] );
        }
        ast.clear();
        for ( int i = n; i > 0; --i ) {
            it = lower_bound ( all ( ast ), -a[i] );
            f[i] = it - ast.begin() + 1;
            if ( it == ast.end() ) ast.pb ( -a[i] );
            else *it = min ( *it, -a[i] );
        }
        int ans = 0;
        for( int i = 1; i <= ( n - L ); ++i ) {
            ans = max( ans, t[i] );
        }
        for( int i = L + 1; i <= n; ++i ) {
            ans = max( ans, f[i] );
        }
        for( int i = 2; i + L <= n; ++i ) {
            modify(a[i-1],t[i-1]);
            int p = i + L;
            ans = max( ans, getnum( a[p] ) + f[p] );
        }
        printf( "Case #%d: %d\n", ++cs, ans );
    }
}
