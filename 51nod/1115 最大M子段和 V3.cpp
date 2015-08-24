/*
	ͬv2.
*/
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
const int N = 2000005;
const int Mod = ( int ) 1e9 + 7;

LL s[N];
int cnt;

inline LL ABS( LL x )
{
    return x > 0 ? x : -x;
}

set<pair<LL, int> > a;
int n, m, now;
int pr[N], ne[N];

inline void Erase( int x )
{
    int l = pr[x], r = ne[x];
    ne[l] = r, pr[r] = l;
}
int main()
{
    //freopen( "txt.in", "r", stdin );
    // freopen( "txt.out", "w", stdout );
    scanf( "%d %d", &n, &m );
    LL tem = 0, ans = 0;
    for( int i = 1, x; i <= n; ++i ) {
        scanf( "%d", &x );
        if( ( tem < 0 && x > 0 ) || ( tem > 0 && x < 0 ) ) {
            now += tem > 0;
            s[++cnt] = tem;
            a.insert( mp( ABS( tem ), cnt ) );
            tem = 0;
        }
        tem += x;
        ans += x > 0 ? x : 0;
    }
    if( ( tem >= 0 && s[1] > 0 ) || ( tem <= 0 && s[1] < 0 ) ) {
        a.erase(mp(ABS(s[1]),1));
        s[1] += tem;
        a.insert(mp(ABS(s[1]),1));
    } else {
        now += tem > 0;
        s[++cnt] = tem;
        a.insert( mp( ABS( tem ), cnt ) );
    }

    for( int i = 1; i <= cnt; ++i ) {
        pr[i] = i - 1, ne[i] = i + 1;
    }
    pr[1] = cnt, ne[cnt] = 1;


    for( ; now > m; --now ) {
        int x = ( *a.begin() ).se;
        a.erase( mp( ABS( s[x] ), x ) );
        a.erase( mp( ABS( s[pr[x]] ), pr[x] ) ), a.erase( mp( ABS( s[ne[x]] ), ne[x] ) );
        ans -= ABS( s[x] );
        if( pr[x] != 0 && ne[x] != 0 ) {
            s[x] = s[x] + s[pr[x]] + s[ne[x]];
            s[pr[x]] = 0, s[ne[x]] = 0;
            Erase( pr[x] );
            Erase( ne[x] );
            a.insert( mp( ABS( s[x] ), x ) );
        } else {
            Erase( pr[x] ), Erase( ne[x] ), Erase( x );
        }
    }
    printf( "%I64d\n", ans );
    return 0;
}
