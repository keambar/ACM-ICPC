#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define LL long long
#define sz( a ) int( a.size() )
#define all( a ) a.begin(), a.end()
#define sd second
#define ft first
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;
int T, n;
LL C, now, ans, Sp;
LL B[N], S[N][30], d[N];
LL use[N], Sell[N];

deque<pair<int, int> > tank;

void ST()
{
    for ( int i = n; i > 0; --i ) {
        for ( int j = 1; i + ( 1 << j ) - 1 <= n; ++j ) {
            S[i][j] = max ( S[i][j - 1], S[i + ( 1 << j - 1 )][j - 1] );
        }
    }
}

LL get ( int l, int r )
{
    int tmp = int ( log ( r - l + 1 ) / log ( 2 ) );
    return max ( S[l][tmp], S[r - ( 1 << tmp ) + 1][tmp] );
}

void travels ( int s )
{
    now -= s;
    while ( s ) {
        int t = min ( s, tank.front().ft );
        s -= t;
        tank.front().ft -= t;
        use[tank.front().sd] += t;
        if ( !tank.front().ft ) {
            tank.pop_front();
        }
    }
}

void fuel ( int k )
{
    while ( !tank.empty() && B[k] <= B[tank.back().sd] ) {
        LL Sp = get ( tank.back().sd + 1, k );
        ans -= max ( B[tank.back().sd], Sp )  * tank.back().ft;
        now -= tank.back().ft;
        tank.pop_back();
    }
    LL Sp = 0;
    if ( !tank.empty() ) Sp = get ( tank.front().sd + 1, k );
    while ( !tank.empty() && B[k] < Sp ) {
        ans -= Sp * tank.front().ft;
        now -= tank.front().ft;
        tank.pop_front();
        if ( !tank.empty() ) Sp = get ( tank.front().sd + 1, k );
    }
    tank.pb ( mp ( C - now, k ) );
    ans += ( C - now ) * B[k];
    now = C;
}

void sell()
{
    while ( !tank.empty() ) {
        int p = tank.back().sd;
        LL Sp = get ( p + 1, n );
        ans -= max ( B[p], Sp ) * tank.back().ft;
        tank.pop_back();
    }
    now = 0;
}
int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        ans = 0;
        scanf ( "%d %I64d", &n, &C );
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%I64d", &d[i] );
        }
        for ( int i = 0; i <= n; ++i ) {
            scanf ( "%I64d %I64d", &B[i], &S[i][0] );
        }
        for ( int i = n; i > 0; --i ) {
            d[i] -= d[i - 1];
        }
        ST();
        fuel ( now = 0 );
        for ( int i = 1; i <= n; ++i ) {
            travels ( d[i] );
            if ( i != n ) fuel ( i );
        }
        sell();
        printf ( "%I64d\n", ans );
    }
}
