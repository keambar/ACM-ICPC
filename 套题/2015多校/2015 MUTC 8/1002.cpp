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
const int N = 10005;
const int Mod = ( int ) 1e9 + 7;
typedef pair<LL, LL> ii;

LL a[N], pos[N];
LL T, n, q, bk, m;
LL pl, pr;
vector<ii> f[N], p[N];
LL ans[N], res;

inline LL gcd ( LL x, LL y )
{
    return y ? gcd ( y, x % y ) : x;
}

inline void Ptt()
{
    ii tem;
    for ( int i = 1; i <= n; ++i ) {
        for ( auto &s : f[i - 1] ) {
            tem = s;
            tem.ft = gcd ( tem.ft, a[i] );
            if ( f[i].empty() || tem.ft != f[i].back().ft ) {
                f[i].pb ( tem );
            }
        }
        if ( f[i].empty() || a[i] != f[i].back().ft ) {
            f[i].pb ( mp ( a[i], i ) );
        }
    }
    for ( int i = n; i > 0; --i ) {
        for ( auto &s : p[i + 1] ) {
            tem = s;
            tem.ft = gcd ( tem.ft, a[i] );
            if ( p[i].empty() || tem.ft != p[i].back().ft ) {
                p[i].pb ( tem );
            }
        }
        if ( p[i].empty() || a[i] != p[i].back().ft ) {
            p[i].pb ( mp ( a[i], i ) );
        }
    }
}
inline void update1 ( int k, int sta )
{
    int it = f[k].size() - 1, r = k;
    while ( f[k][it].sd > pl ) {
        res += ( r - f[k][it].sd + 1 ) * f[k][it].ft * sta;
        r = f[k][it].sd - 1;
        --it;
    }
    res += sta * ( r - pl + 1 ) * f[k][it].ft;
}

inline void update2 ( int k, int sta )
{
    int it = p[k].size() - 1, l = k;
    while ( p[k][it].sd < pr ) {
        res += ( p[k][it].sd - l + 1 ) * p[k][it].ft * sta;
        l = p[k][it].sd + 1;
        --it;
    }
    res += sta * ( pr - l + 1 ) * p[k][it].ft;
}
struct node {
    int ft, sd, p;
} qus[N];

inline bool cmp ( node a, node b )
{
    if ( pos[a.ft] == pos[b.ft] )   return a.sd < b.sd;
    return pos[a.ft] < pos[b.ft];
}

int main()
{
    scanf ( "%I64d", &T );
    while ( T-- ) {
        scanf ( "%I64d", &n );
        bk = int ( sqrt ( 1.*n ) + 0.5 );
        for ( int i = 1; i <= n; ++i ) {
            f[i].clear(), p[i].clear();
            scanf ( "%I64d", &a[i] );
            pos[i] = ( i - 1 ) / bk + 1;
        }
        Ptt();
        scanf ( "%I64d", &q );
        for ( int i = 1, u, v; i <= q; ++i ) {
            scanf ( "%I64d %I64d", &qus[i].ft, &qus[i].sd );
            qus[i].p = i;
        }
        sort ( qus + 1, qus + 1 + q, cmp );
        pl = 1, pr = 0;
        res = 0;
        for ( int i = 1; i <= q; ++i ) {
            node t = qus[i];
            while ( pr < t.sd ) {
                update1 ( ++pr, 1 );
            }
            while ( pr > t.sd ) {
                update1 ( pr--, -1 );
            }
            while ( pl < t.ft ) {
                update2 ( pl++, -1 );
            }
            while ( pl > t.ft ) {
                update2 ( --pl, 1 );
            }
            ans[t.p] = res;
        }
        for ( int i = 1; i <= q; ++i ) {
            printf ( "%I64d\n", ans[i] );
        }
    }
}
