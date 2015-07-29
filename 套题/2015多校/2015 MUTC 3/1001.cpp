#include <bits/stdc++.h>
#define LL long long
#define lson x<<1
#define rson x<<1|1
using namespace std;
const int N = 100009;
const LL INF = ( 1LL << 60 );
int tl[N << 3], tr[N << 3];
LL s[N << 3][2][2], ns[N << 3][2][2];
LL a[N];
int T, n, m;
int l, r, key;

void updata ( int x )
{
    for ( int i = 0; i < 2; ++i )
        for ( int j = 0; j < 2; ++j ) {
            s[x][i][j] = max ( s[lson][i][j], s[rson][i][j] );
            s[x][i][j] = max ( s[x][i][j], s[lson][i][0] + s[rson][1][j] );
            s[x][i][j] = max ( s[x][i][j], s[lson][i][1] + s[rson][0][j] );
        }
}

void updata2 ( int x )
{
    for ( int i = 0; i < 2; ++i )
        for ( int j = 0; j < 2; ++j ) {
            ns[x][i][j] = max ( ns[lson][i][j], ns[rson][i][j] );
            ns[x][i][j] = max ( ns[x][i][j], ns[lson][i][0] + ns[rson][1][j] );
            ns[x][i][j] = max ( ns[x][i][j], ns[lson][i][1] + ns[rson][0][j] );
        }
}

void push ( int x )
{
    ns[lson][0][0] = -INF, ns[lson][0][1] = -INF;
    ns[lson][1][0] = -INF, ns[lson][1][1] = -INF;
    ns[rson][0][0] = -INF, ns[rson][0][1] = -INF;
    ns[rson][1][0] = -INF, ns[rson][1][1] = -INF;
}
void build ( int x, int l, int r )
{
    tl[x] = l, tr[x] = r;
    s[x][0][0] = -INF, s[x][0][1] = -INF;
    s[x][1][0] = -INF, s[x][1][1] = -INF;
    if ( l == r ) {
        int sta = l % 2;
        s[x][sta][sta] = max ( s[x][sta][sta], a[l] );
        return ;
    }
    int mid = ( l + r ) >> 1;
    build ( lson, l, mid ), build ( rson, mid + 1, r );
    updata(x);
}

void modify ( int x )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        int sta = l % 2;
        s[x][sta][sta] = key;
        return ;
    }
    int mid = ( tl[x] + tr[x] ) >> 1;
    if ( l <= mid ) modify ( lson );
    if ( r > mid ) modify ( rson );
    updata ( x );
}

void query ( int x )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        ns[x][0][0] = s[x][0][0];
        ns[x][0][1] = s[x][0][1];
        ns[x][1][0] = s[x][1][0];
        ns[x][1][1] = s[x][1][1];
        return;
    }
    push ( x );
    int mid = ( tl[x] + tr[x] ) >> 1;
    if ( l <= mid ) query ( lson );
    if ( r > mid )  query ( rson );
    updata2 ( x );
}

int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d %d", &n , &m );
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%I64d", &a[i] );
        }
        memset ( s, 0, sizeof s );
        build ( 1, 1, n );
        for ( int i = 1, cmd; i <= m; ++i ) {
            scanf ( "%d %d %d", &cmd, &l, &r );
            if ( cmd == 0 ) {
                query ( 1 );
                LL tem1 = max ( ns[1][0][0], ns[1][0][1] );
                LL tem2 = max ( ns[1][1][0], ns[1][1][1] );
                LL ans = max ( tem1, tem2 );
                printf ( "%I64d\n",ans  );
            } else {
                key = r, r = l;
                modify ( 1 );
            }
        }
    }
    return 0;
}
/*
100
3 100
-100 -100 -100
0 1 1
*/
