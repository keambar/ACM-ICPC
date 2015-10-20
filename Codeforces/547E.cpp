/*
先构造后缀数组 
LCP的值是两个位置之间height的最小值
找到满足这个最小值大于串长的左右端点
查询在这个区间里有多少是在l～r后缀之间的位置
再用树状数组统计就好了
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> ii;
const ll mod = 1000000007;
const int N = 501000;
int l[N], r[N], c[N], sl[N], sr[N], n, q, tot, ans[N];
char s[N];
vector<ii> qr[N];
int sa[N], rk[N * 2], p[N * 2];
pair<ii, int> pos[N * 2];
void buildSA ( int tot )
{
    for ( int i = 1; i <= tot; ++i ) rk[i] = p[i];
    for ( int j = 0; j <= ( int ) ( log ( N ) / log ( 2 ) + 1 ); ++j ) {
        for ( int i = 1; i <= tot; ++i )
            pos[i] = mp ( mp ( rk[i], rk[i + ( 1 << j )] ), i );
        sort ( pos + 1, pos + tot + 1 );
        int cnt = 0;
        for ( int i = 1; i <= tot; ++i ) {
            rk[pos[i].se] = cnt;
            cnt += ( pos[i].fi != pos[i + 1].fi );
        }
        if ( cnt == tot ) break;
    }
    for ( int i = 1; i <= tot; ++i ) rk[i]++;
    for ( int i = 1; i <= tot; ++i ) sa[rk[i]] = i;
}
int query( int l, int r, char c, int len )
{
    ++r;
    --l;
    while ( l + 1 < r ) {
        int md = ( l + r ) >> 1;
        if ( p[sa[md] + len - 1] >= c ) r = md;
        else l = md;
    }
    return r;
}
void add( int x, int s )
{
    for ( ; x <= tot; x += x & -x ) c[x] += s;
}
int query( int x )
{
    int s = 0;
    for ( ; x; x -= x & -x ) s += c[x];
    return s;
}
int main()
{

    scanf( "%d%d", &n, &q );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%s", s );
        int len = strlen( s );
        l[i] = tot + 1;
        for( int j = 0; j < len; ++j )
            p[++tot] = s[j] - 'a';
        p[++tot] = 26 + i;
        r[i] = tot;
    }
    buildSA( tot );
    for( int i = 1; i <= n; ++i ) {
        int pl = 1, pr = tot;
        for( int j = l[i]; j < r[i]; ++j ) {
            int ql = query( pl, pr, p[j], j - l[i] + 1 );
            int qr = query( pl, pr, p[j] + 1, j - l[i] + 1 ) - 1;
            pl = ql;
            pr = qr;
        }
        sl[i] = pl, sr[i] = pr;
    }
    for( int i = 1; i <= q; ++i ) {
        int l, r, k;
        scanf( "%d%d%d", &l, &r, &k );
        qr[r].pb( mp( k, i ) ), qr[l - 1].pb( mp( k, -i ) );
    }
    for( int i = 1; i <= n; ++i ) {
        for( int j = l[i]; j < r[i]; ++j ) add( rk[j], 1 );
        for ( auto p : qr[i] ) {
            int id = p.se, w = 1;
            if ( id < 0 ) w = -1, id *= -1;
            ans[id] += w * ( query( sr[p.fi] ) - query( sl[p.fi] - 1 ) );
        }
    }
    for( int i = 1; i <= q; ++i ) {
        printf( "%d\n", ans[i] );
    }
}
