/*
	贪心。分成若干段正负相隔的序列。贪心合并相邻的3段。
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

struct cmp {
    bool operator()( const int &A, const int & B )
    {
        return s[A] < s[B];
    }
};
multiset<int, cmp> a, b;
int n, m;
int pr[N], ne[N];
inline void Erase( int x )
{
    if( x == 0 ) return ;
    int l = pr[x], r = ne[x];
    if( l != 0 )    ne[l] = r;
    if( r != 0 )   pr[r] = l;
}
int main()
{
    scanf( "%d %d", &n, &m );
    LL tmp = 0;
    for( int i = 1, x; i <= n; ++i ) {
        scanf( "%d", &x );
        if( ( tmp >= 0 && x >= 0 ) || ( tmp <= 0 && x < 0 ) ) {
            tmp += x;
        } else {
            if( tmp > 0 ) {
                s[++cnt] = tmp;
                a.insert( cnt );
            } else {
                s[++cnt] = tmp;
                b.insert( cnt );
            }
            tmp = x;
        }
    }
    if( tmp > 0 ) {
        s[++cnt] = tmp;
        a.insert( cnt );
    } else {
        s[++cnt] = tmp;
        b.insert( cnt );
    }
    LL ans = 0;
    for( auto &i : a ) {
        ans += s[i];
    }
    for( int i = 1; i <= cnt; ++i ) {
        pr[i] = i - 1, ne[i] = i + 1;
    }
    ne[cnt] = 0;
    if( s[1] < 0 ) {
        b.erase( 1 );
        Erase( 1 );
    }
    if( s[cnt] < 0 ) {
        b.erase( cnt );
        Erase( cnt );
    }

    for( int now = SZ( a ); now > m ; --now ) {
        if( b.empty() || s[*a.begin()] < -s[*b.rbegin()] ) {
            ans -= s[*a.begin()];
            int x = *a.begin();
            a.erase( a.begin() );
            b.erase( pr[x] ), b.erase( ne[x] );
            if( pr[x] != 0 && ne[x] != 0 ) {
                LL tem = s[pr[x]] + s[ne[x]] + s[x];
                s[++cnt] = tem;
                b.insert( cnt );
                pr[cnt] = pr[pr[x]];
                ne[pr[pr[x]]] = cnt;
                ne[cnt] = ne[ne[x]];
                pr[ne[ne[x]]] = cnt;
            } else {
                Erase( pr[x] ), Erase( ne[x] ), Erase( x );
            }
        } else {
            ans += s[*b.rbegin()];
            int x = *b.rbegin();
            b.erase( *b.rbegin() );
            a.erase( pr[x] ), a.erase( ne[x] );
            if( pr[x] != 0 && ne[x] != 0 ) {
                LL tem = s[pr[x]] + s[ne[x]] + s[x];
                s[++cnt] = tem;
                a.insert( cnt );
                pr[cnt] = pr[pr[x]];
                ne[pr[pr[x]]] = cnt;
                ne[cnt] = ne[ne[x]];
                pr[ne[ne[x]]] = cnt;
            } else {
                Erase( pr[x] ), Erase( ne[x] ), Erase( x );
            }
        }
    }
    printf( "%I64d\n", ans );
    return 0;
}
