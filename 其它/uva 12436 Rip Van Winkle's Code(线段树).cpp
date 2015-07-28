#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define LL long long
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int N = 251111;
LL s[N << 3], d[N << 3], sum[N << 3], flag2[N << 3], flag[N << 3], val[N << 3];
LL tl[N << 3], tr[N << 3], len[N << 3];
LL l, r, key;

void build ( int x, int l, int r )
{
    tl[x] = l, tr[x] = r, len[x] = r - l + 1;
    s[x] = d[x] = sum[x] = flag[x] = 0;
    if ( l == r ) {
        return ;
    }
    int mid = ( l + r ) >> 1;
    build ( lson, l, mid ), build ( rson, mid + 1, r );
}

void push ( int x )
{
    if ( flag[x] ) {
        s[lson] = d[lson] = 0;
        s[rson] = d[rson] = 0;
        flag[lson] = flag[rson] = flag[x];
        val[lson] = val[rson] = val[x];
        sum[lson] = val[lson] * len[lson];
        sum[rson] = val[rson] * len[rson];
        flag[x] = val[x] = 0;
    }
    if ( flag2[x] ) {
        flag2[lson] = flag2[rson] = 1;
        s[lson] += s[x], s[rson] += s[x] + len[lson] * d[x];
        d[lson] += d[x], d[rson] += d[x];
        sum[lson] += ( s[x] + s[x] + ( len[lson] - 1 ) * d[x] ) * len[lson] / 2;
        sum[rson] += ( s[x] + d[x] * len[lson] + s[x] + ( len[x] - 1 ) * d[x] ) * len[rson] / 2;
        s[x] = 0, d[x] = 0;
        flag2[x] = 0;
    }
}

void updata ( int x )
{
    sum[x] = sum[lson] + sum[rson];
}

void modifyA ( int x )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        flag2[x] = 1;
        s[x] += tl[x] - l + 1, d[x] += 1;
        sum[x] += ( ( tl[x] - l + 1 ) + ( tr[x] - l + 1 ) ) * len[x] / 2;
        return ;
    }
    push ( x );
    int mid = ( tl[x] + tr[x] ) >> 1;
    if ( l <= mid ) modifyA ( lson );
    if ( r > mid ) modifyA ( rson );
    updata ( x );
}

void modifyB ( int x )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        flag2[x] = 1;
        s[x] += r - tl[x] + 1 , d[x] -= 1;
        sum[x] += ( ( r - tl[x] + 1 ) + ( r - tr[x] + 1 ) ) * len[x] / 2;
        return ;
    }
    push ( x );
    int mid = ( tl[x] + tr[x] ) >> 1;
    if ( l <= mid ) modifyB ( lson );
    if ( r > mid ) modifyB ( rson );
    updata ( x );
}

void modifyC ( int x )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        flag[x] = 1;
        val[x] = key;
        sum[x] = key * len[x];
        s[x] = d[x] = 0;
        return ;
    }
    push ( x );
    int mid = ( tl[x] + tr[x] ) >> 1;
    if ( l <= mid ) modifyC ( lson );
    if ( r > mid ) modifyC ( rson );
    updata ( x );
}

LL query ( int x  )
{
    push ( x );
    if ( tl[x] >= l && tr[x] <= r ) {
        return sum[x];
    }
    int mid = ( tl[x] + tr[x] ) >> 1;
    LL ans = 0;
    if ( l <= mid ) ans += query ( lson );
    if ( r > mid ) ans += query ( rson );
    updata ( x );
    return ans;
}

int n, m;
int main()
{
    build ( 1, 1, N );
    scanf ( "%d", &n );
    char cmd[10];
    for ( int i = 1; i <= n; ++i ) {
        scanf ( "%s", cmd );
        if ( cmd[0] == 'A' ) {
            scanf ( "%lld %lld", &l, &r );
            modifyA ( 1 );
        } else if ( cmd[0] == 'B' ) {
            scanf ( "%lld %lld", &l, &r );
            modifyB ( 1 );
        } else if ( cmd[0] == 'C' ) {
            scanf ( "%lld %lld %lld", &l, &r, &key );
            modifyC ( 1 );
        } else if ( cmd[0] == 'S' ) {
            scanf ( "%lld %lld", &l, &r );
            printf ( "%lld\n", query ( 1 ) );
        }
    }
    return 0;
}
/*
1000
S 2 3
A 7 15
B 4 5
B 15 16
C 2 10 3
B 14 15
A 10 18
S 4 4
A 3 16
B 6 14
B 4 7
S 8 11
A 1 4
B 2 3
S 1 3
C 3 4 -2
S 2 4
B 1 3
S 2 4
A 1 4
B 2 3
S 1 3
C 3 4 -2
S 2 4
B 1 3
S 2 4

ansewer:
0
3
6
16
3
6
21
9
12
*/
