/*
	离线询问，分治求解
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
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;

inline void rd( int &xx )
{
    char ch = getchar();
    while( ch < '0' || ch > '9' ) ch = getchar();
    for( xx = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        xx = xx * 10 + ( ch - '0' );
}
char o[35];
inline void putnum( int x )
{
    if( x == 0 ) {
        puts( "0" );
        return;
    }
    int i;
    for( i = 0; x != 0; i++, x /= 10 ) o[i] = x % 10 + '0' ;
    for( i--; i >= 0; i-- ) putchar( o[i] );
    putchar( 10 );
}

struct node {
    int sta, x, y, k, sum, tmp, id;
    node() {};
    node( int a, int b, int c, int d ): sta( a ), x( b ), y( c ), k( d )
    {
        sum = 0, tmp = 0;
    };
} q[N << 1], q1[N << 1], q2[N << 1];
int cnt, num;

int n;
int a[N], ans[N];

int S[N];
inline void add( int x, int k )
{
    for( ; x <= n; x += x & -x ) S[x] += k;
}

inline int query( int x )
{
    int res = 0;
    for( ; x > 0; x -= x & -x ) res += S[x];
    return res;
}

void Solve( int L, int R, int l, int r )
{
    if( L > R ) return ;
    if( l == r ) {
        for( int i = L; i <= R; ++i ) {
            if( q[i].sta == 3 ) {
                ans[q[i].id] = l;
            }
        }
        return ;
    }
    int mid = ( l + r ) >> 1;
    for( int i = L; i <= R; ++i ) {
        if( q[i].sta == 1 && q[i].y <= mid ) add( q[i].x, 1 );
        if( q[i].sta == 3 ) {
            q[i].tmp = query( q[i].y ) - query( q[i].x - 1 );
        }
    }
    for( int i = L; i <= R; ++i ) {
        if( q[i].sta == 1 && q[i].y <= mid ) add( q[i].x, -1 );
    }
    int l1 = 0, l2 = 0;
    for( int i = L; i <= R; ++i ) {
        if( q[i].sta == 3 ) {
            if( q[i].sum + q[i].tmp < q[i].k ) {
                q[i].sum += q[i].tmp;
                q2[++l2] = q[i];
            } else {
                q1[++l1] = q[i];
            }
        } else {
            if( q[i].y <= mid ) {
                q1[++l1] = q[i];
            } else
                q2[++l2] = q[i];
        }
    }
    for( int i = 1; i <= l1; ++i ) {
        q[L + i - 1] = q1[i];
    }
    for( int i = 1; i <= l2; ++i ) {
        q[L + l1 + i - 1] = q2[i];
    }
    Solve( L, L + l1 - 1, l, mid );
    Solve( L + l1, R, mid + 1, r );
}
int main()
{
    while( scanf( "%d", &n ) != EOF ) {
        cnt = 0, num = 0;
        for( int i = 1; i <= n; ++i ) {
            rd( a[i] );
            q[++cnt] = node( 1, i, a[i], 0 );
        }
        int m;
        scanf( "%d", &m );
        int cmd, x, y, k;
        for( int i = 1; i <= m; ++i ) {
            rd( x ), rd( y ), rd( k );
            ++x, ++y;
            k = ( y - x + 1 - k +1);
            q[++cnt] = node( 3, x, y, k );
            q[cnt].id = ++num;
        }
        Solve( 1, cnt, 1, int( 1e9 ) );
        for( int i = 1; i <= num; ++i ) {
            printf( "%d\n", ans[i] );
        }
    }
}
