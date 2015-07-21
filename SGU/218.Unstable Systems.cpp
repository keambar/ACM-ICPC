#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int N = 501;
int link[N], vis[N];
int G[N][N],ans[N];
int n, mid;
bool DFS ( int x )
{
    for ( int i = 1; i <= n; i++ )
        if ( G[x][i] <= mid && !vis[i] ) {
            vis[i] = 1;
            if ( link[i] == -1 || DFS ( link[i] ) ) {
                link[i] = x;
                return 1;
            }
        }
    return 0;
}
bool check()
{
    int ans = 0;
    memset ( link, -1, sizeof link );
    for ( int i = 1; i <= n; i++ ) {
        memset ( vis, 0, sizeof vis );
        if ( DFS ( i ) ) ans++;
    }
    return ans == n;
}
int main()
{
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= n; ++j ) {
            scanf ( "%d", &G[i][j] );
        }
    }
    int l = -int(1e6), r = int ( 1e6 );
    while ( l <= r ) {
        mid = ( l + r ) >> 1;
        if ( check () ) r = mid - 1;
        else
            l = mid + 1;
    }
    printf ( "%d\n", r + 1 );
    mid = r + 1;
    check();
    for ( int i = 1; i <= n; ++i ) {
        ans[link[i]]=i;
    }
    for ( int i = 1; i <= n; ++i ) {
        printf ( "%d %d\n", i, ans[i] );
    }
}
/*
3
100 1 100
100 100 1
1 100 100
*/
