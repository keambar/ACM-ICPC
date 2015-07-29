#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#define ll long long
using namespace std;

const int N = 100009;
struct node {
    int l, r, p;
    node ( int l = 0, int r = 0, int p = 0 ) : l ( l ), r ( r ), p ( p ) {}
    bool operator < ( const node &a ) const
    {
        if ( r != a.r ) return r < a.r;
        if ( l != a.l ) return l > a.l;
        return p < a.p;
    }
} a[N], tem[N];
int dp[N], s[N];
int n,m;

void modify ( int x, int k )
{
    for ( x; x <= m; x += x & -x )
        s[x] = max ( s[x], k );
}

int getnum ( int x )
{
    int ans = 0;
    for ( x; x > 0; x -= x & -x )
        ans = max ( ans, s[x] );
    return ans;
}

void  sclear ( int x )
{
    for ( x; x <= m; x += x & -x )
        s[x] = 0;
}
void solve ( int l, int r )
{
    if ( l == r ) {
        dp[a[l].p] = max ( dp[a[l].p], 1 );
        return ;
    }
    int mid = ( l + r ) >> 1;
    solve ( mid + 1, r );
    for ( int i = l; i <= r; ++i ) {
        tem[i] = node ( a[i].l, a[i].r, a[i].p );
    }
    sort ( tem + l, tem + mid + 1 );
    sort ( tem + mid + 1, tem + r + 1 );
    for ( int i = mid, j = r; i >= l; --i ) {
        while ( j > mid && tem[j].r >= tem[i].r ) {
            modify ( tem[j].l, dp[tem[j].p] );
            --j;
        }
        dp[tem[i].p] = max ( dp[tem[i].p], getnum ( tem[i].l ) + 1 );
    }
    for ( int i = mid + 1; i <= r; ++i ) {
        sclear ( tem[i].l );
    }
    solve ( l, mid );
}

int main()
{
    while ( scanf ( "%d", &n ) != EOF ) {
        vector<int> b;
        for ( int i = 1; i <= n; ++i ) dp[i] = 1;
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &a[i].l );
            a[i].p=i;
            b.push_back ( a[i].l );
        }
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &a[i].r );
            b.push_back ( a[i].r );
        }
        sort ( b.begin(), b.end() );
        b.erase ( unique ( b.begin(), b.end() ), b.end() );
        for ( int i = 1; i <= n; ++i ) {
            a[i].l = lower_bound ( b.begin(), b.end(), a[i].l ) - b.begin() + 1;
            a[i].r = lower_bound ( b.begin(), b.end(), a[i].r ) - b.begin() + 1;
        }
        m=b.size()+10;
        solve ( 1, n );
        int ans = 0;
        for ( int i = 1; i <= n; ++i ) {
            ans = max ( ans, dp[i] );
        }
        printf ( "%d\n", ans );
        int x = 0x7fffffff, y = -0x7fffffff;
        for ( int i = 1; i <= n&&ans; ++i ) {
            if ( dp[i] == ans && a[i].l <= x && a[i].r >= y ) {
                printf ( "%d", i );
                x = a[i].l, y = a[i].r;
                if ( --ans != 0 ) putchar ( 32 );
                else putchar ( 10 );
            }
        }
    }
    return 0;
}
/*
10
23   456 12 455 21 54 1    465 21  4
154 31   45 1     4   31 45 69   44  100
*/
