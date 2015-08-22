/*
	队列+贪心
*/
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
const int Mos = ( int ) 1e9 + 7;
int T, n;
LL C, now, ans;
LL B[N], S[N], d[N];

deque<pair<int, int> > tank;

void travels ( int s )
{
    now -= s;
    while ( s ) {
        int t = min ( s, tank.front().ft );
        s -= t;
        tank.front().ft -= t;
        if ( !tank.front().ft ) {
            tank.pop_front();
        }
    }
}

void fuel ( int k )
{
    while ( !tank.empty() && B[k] < B[tank.back().sd] ) {
        ans -= B[tank.back().sd] * tank.back().ft;
        now -= tank.back().ft;
        tank.pop_back();
    }
    tank.pb ( mp ( C - now, k ) );
    ans += ( C - now ) * B[k];
    now = C;
}

void sell()
{
    while ( !tank.empty() ) {
        int p = tank.back().sd;
        ans -= tank.back().ft * B[p];
        tank.pop_back();
    }
}
int main()
{
    ans = 0;
    scanf ( "%d %I64d", &n, &C );
    for ( int i = 0; i < n; ++i ) {
        scanf ( "%I64d %I64d", &d[i + 1], &B[i] );
    }
    fuel ( now = 0 );
    for ( int i = 1; i <= n; ++i ) {
        travels ( d[i] );
        if ( i != n ) fuel ( i );
    }
    sell();
    printf ( "%I64d\n", ans );
}
