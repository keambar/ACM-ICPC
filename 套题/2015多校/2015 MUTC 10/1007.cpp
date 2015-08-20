#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 400005
#define inf 1000000000

using namespace std;
struct query {
    int x, y, k, s, tp, cur;
} q[maxn], q1[maxn], q2[maxn];
int a[maxn], ans[maxn], tmp[maxn], t[maxn];
int n, m, num, cnt;

inline void rd( int &xx )
{
    char ch = getchar();
    while( ch < '0' || ch > '9' ) {
        ch = getchar();
    }
    for( xx = 0; ch >= '0' && ch <= '9'; ch = getchar() ) {
        xx = xx * 10 + ( ch - '0' );
    }
}
char o[35];

inline void putnum( int x )
{
    if( x == 0 ) {
        putchar( '0' );
        return;
    }
    int i;
    for( i = 0; x != 0; i++, x /= 10 ) {
        o[i] = x % 10 + '0' ;
    }
    for( i--; i >= 0; i-- ) {
        putchar( o[i] );
    }
    putchar( 10 );
}
void add( int x, int y )
{
    for( int i = x; i <= n; i += ( i & -i ) ) {
        t[i] += y;
    }
}

int ask( int x )
{
    int tmp = 0;
    for( int i = x; i > 0; i -= ( i & -i ) ) {
        tmp += t[i];
    }
    return tmp;
}

void divide( int head, int tail, int l, int r )
{
    //cout<<head<<' '<<tail<<' '<<l<<' '<<r<<endl;
    if( head > tail ) {
        return ;
    }
    if( l == r ) {
        for( int i = head; i <= tail; i++ )
            if( q[i].tp == 3 ) {
                ans[q[i].s] = l;    //,cout<<l<<endl;
            }
        return ;
    }
    int mid = ( l + r ) >> 1;
    for( int i = head; i <= tail; i++ ) {
        if( q[i].tp == 1 && q[i].y <= mid ) {
            add( q[i].x, 1 );
        } else
            if( q[i].tp == 2 && q[i].y <= mid ) {
                add( q[i].x, -1 );
            } else
                if( q[i].tp == 3 ) {
                    tmp[i] = ask( q[i].y ) - ask( q[i].x - 1 );
                }
    }
    for( int i = head; i <= tail; i++ ) {
        if( q[i].tp == 1 && q[i].y <= mid ) {
            add( q[i].x, -1 );
        } else
            if( q[i].tp == 2 && q[i].y <= mid ) {
                add( q[i].x, 1 );
            }
    }
    int l1 = 0, l2 = 0;
    for( int i = head; i <= tail; i++ )
        if( q[i].tp == 3 ) {
            if( q[i].cur + tmp[i] > q[i].k - 1 ) { //q[i].cur+tmp[i]表示累积了多少个数
                q1[++l1] = q[i];
            } else {
                q[i].cur += tmp[i];
                q2[++l2] = q[i];
            }
        } else {
            if( q[i].y <= mid ) {
                q1[++l1] = q[i];
            } else {
                q2[++l2] = q[i];
            }
        }
    for( int i = 1; i <= l1; i++ ) {
        q[head + i - 1] = q1[i];
    }
    for( int i = 1; i <= l2; i++ ) {
        q[head + l1 + i - 1] = q2[i];
    }
    divide( head, head + l1 - 1, l, mid );
    divide( head + l1, tail, mid + 1, r );
}

int main()
{
    while( ~scanf( "%d", &n ) ) {
        memset( t, 0, sizeof t );
        memset( ans, 0, sizeof ans );
        memset( tmp, 0, sizeof tmp );
        memset( q, 0, sizeof q );
        memset( q1, 0, sizeof q1 );
        memset( q2, 0, sizeof q2 );
        cnt = 0, num = 0;
        for( int i = 1; i <= n; i++ ) {
            rd( a[i] );
            q[++num].x = i;
            q[num].y = a[i];
            q[num].tp = 1;
            q[num].s = 0;
        }
        int cmd;
        int x, y, z;
        rd( m );
        for( int i = 1; i <= m; i++ ) {
            rd( cmd );
            if( cmd == 2 ) {
                rd( x ), rd( y ), rd( z );
                q[++num].x = x, q[num].y = y, q[num].k = z;
                q[num].tp = 3;
                q[num].s = ++cnt;
            } else {
                rd( x ), rd( y );
                q[++num].x = x;
                q[num].y = a[x];
                q[num].tp = 2;
                q[num].s = 0;
                q[++num].x = x;
                q[num].y = y;
                q[num].tp = 1;
                q[num].s = 0;
                a[x] = y;
            }
        }
        divide( 1, num, 0, inf );
        for( int i = 1; i <= cnt; i++ ) {
            putnum( ans[i] );
        }
    }
    return 0;
}