#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int N = 100009;

int T, n;
int a[N], pos[N], ans[N], vis[N];
int tl[N << 2], tr[N << 2], val[N << 2];
set<int> s;

inline void rd ( int &xx )
{
    char ch = getchar();
    while ( ch < '0' || ch > '9' ) ch = getchar();
    for ( xx = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        xx = xx * 10 + ( ch - '0' );
}
char o[35];

inline void putnum ( int x )
{
    if ( x == 0 ) {
        putchar ( '0' );
        return;
    }
    int i;
    for ( i = 0; x != 0; i++, x /= 10 ) o[i] = x % 10 + '0' ;
    for ( i--; i >= 0; i-- ) putchar ( o[i] );
}

void build ( int x, int l, int r )
{
    tl[x] = l, tr[x] = r;
    if ( l == r ) {
        val[x] = a[l];
        return ;
    }
    int mid = ( l + r ) >> 1;
    build ( lson, l, mid ), build ( rson, mid + 1, r );
    val[x] = max ( val[lson], val[rson] );
}
void modify ( int x , int l, int r, int key )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        val[x] = key;
        return ;
    }
    int mid = ( tl[x] + tr[x] ) >> 1;
    if ( l <= mid ) modify ( lson, l, r, key );
    if ( r > mid ) modify ( rson, l, r, key );
    val[x] = max ( val[lson], val[rson] );
}

int query ( int x , int l, int r )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        return val[x];
    }
    int mid = ( tl[x] + tr[x] ) >> 1, ans = 0;
    if ( l <= mid ) ans = query ( lson, l, r );
    if ( r > mid ) ans = max ( ans, query ( rson , l, r ) );
    return ans;
}

int main()
{
    rd ( T );
    while ( T-- ) {
        s.clear();
        s.insert ( 0 );
        rd ( n );
        for ( int i = 1; i <= n; ++i ) {
            rd ( a[i] );
            pos[a[i]] = i;
            ans[i] = vis[i] = 0;
        }
        build ( 1, 1, n );
        for ( int i = 1; i <= n; ++i ) {
            if ( ans[i] ) continue;
            int p = pos[i];
            int h = ( * ( --s.upper_bound ( p ) ) ) + 1;
            //int h = ( * ( --upper_bound (s.begin(),s.end(), p ) ) ) + 1;这样写会超时！
            int lm = query ( 1 , h, p );
            if (  lm > a[p + 1] || p == n  || vis[a[p + 1]]  ) {
                //在左边找到可选的数，且为最大
                int k = pos[lm];
                ans[i] = lm;
                vis[a[k]] = 1;
                while ( k < p ) {
                    ans[a[k]] = a[k + 1];
                    ++k;
                }
                s.insert ( p );
            } else if ( p != n && !vis[a[p + 1]] ) {
                //合并右边的区间，单独一个数或者一个半区间
                ans[i] = a[p + 1];
                modify ( 1, p + 1, p + 1, 0 );
            }
        }
        for ( int i = 1; i <= n; ++i ) {
            putnum ( ans[i] );
            if ( i == n ) putchar ( 10 );
            else putchar ( 32 );
        }
    }
    return 0;
}
/*
100
5
5 4 3 2 1
6
1 4 5 6 3 2
4
1 3 2 4
4
3 1 4 2
*/
