/*
	匈牙利算法+贪心
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

int G[209][209];
int link[209], vis[209];
int n;
struct node {
    int h, w;
} a[209];
bool cmp( node a, node b )
{
    return a.h * a.w > b.h * b.w;
}

bool DFS ( int x )
{
    for ( int i = 1; i <= n; i++ )
        if ( G[x][i] && !vis[i] ) {
            vis[i] = 1;
            if ( link[i] == -1 || DFS ( link[i] ) ) {
                link[i] = x;
                return 1;
            }
        }
    return 0;
}

int main()
{
    scanf( "%d", &n );
    int ans = 0;
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d %d", &a[i].h, &a[i].w );
        ans += a[i].w * a[i].h;
    }
    sort( a + 1, a + 1 + n, cmp );
    memset ( link, -1, sizeof link );
    for( int i = 1; i <= n; ++i ) {
        for( int j = i + 1; j <= n; ++j ) {
            if( a[i].h >= a[j].h && a[i].w >= a[j].w ) {
                G[j][i] = 1;
            }
        }
    }
    for ( int i = 1; i <= n; i++ ) {
        memset ( vis, 0, sizeof vis );
        if ( DFS ( i ) ) {
            ans -= a[i].h * a[i].w;
        }
    }
    printf( "%d\n", ans );
}
