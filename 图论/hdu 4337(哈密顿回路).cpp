#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define pb push_back
#define sz(a)  (int)(a).size()

const int INF = 500;
bool edge[INF][INF];
typedef vector<int> vi;
vi ans;
//求哈密顿回路O(n^2)
void Hamilton( vi& ans, bool edge[INF][INF], int n )
{
    int s = 1, tol = 2, t, i, j;
    bool vis[INF] = {0};
    for( i = 1; i <= n; i++ ) if( edge[s][i] ) break;
    t = i;
    vis[s] = vis[t] = 1;
    ans.pb( s );
    ans.pb( t );
    while( 1 ) {
        //头尾拓展
        while( 1 ) {
            for( i = 1; i <= n; i++ ) {
                if( edge[t][i] && !vis[i] ) {
                    vis[i] = 1;
                    t = i;
                    ans.pb( i );
                    break;
                }
            }
            if( i > n ) break;
        }
        reverse( ans.begin(), ans.end() );
        swap( s, t );
        while( 1 ) {
            for( i = 1; i <= n; i++ ) {
                if( edge[t][i] && !vis[i] ) {
                    vis[i] = 1;
                    t = i;
                    ans.pb( i );
                    break;
                }
            }
            if( i > n ) break;
        }
        //如果S和T不相连
        if( !edge[s][t] ) {
            for( i = 1; i < sz( ans ) - 2; i++ )
                if( edge[ans[i]][t] && edge[ans[i + 1]][s] ) break;
            reverse( ans.begin() + i + 1, ans.end() );
            t = * ( ans.end() - 1 );
        }
        tol = sz( ans );
        if( tol == n ) return;
        //如果还有点未加入ans
        for( j = 1; j <= n; j++ ) {
            if( vis[j] ) continue;
            //找到与这个点相连的点
            for( i = 1; i < tol - 1; i++ ) if( edge[ans[i]][j] ) break;
            if( edge[ans[i]][j] ) break;
        }
        s = ans[i - 1], t = j;
        reverse( ans.begin(), ans.begin() + i );
        reverse( ans.begin() + i, ans.end() );
        ans.pb( j ), vis[j] = 1;
    }
}
int n, m;
int main()
{
    while( scanf( "%d %d", &n, &m ) != EOF ) {
        int x, y;
        memset(edge,0,sizeof edge);
        for( int i = 1; i <= m; i++ ) {
            scanf( "%d %d", &x, &y );
            edge[y][x] = edge[x][y] = 1;
        }
        ans.clear();
        Hamilton( ans, edge, n );
        printf( "%d", ans[0] );
        for( int i = 1; i < sz( ans ); i++ )
            printf( " %d", ans[i] );
        putchar( 10 );
    }
}