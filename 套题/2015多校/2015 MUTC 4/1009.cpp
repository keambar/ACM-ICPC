#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int N = 1009;
typedef pair<int, int> ii;
int T, n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char s[N][N], ans[N + N];;
int vis[N][N];
vector<ii> ST[N + N];
int near;
void bfs ( )
{
    queue<ii> q;
    q.push ( make_pair ( 0, 0 ) );
    vis[0][0] = 1;
    while ( !q.empty() ) {
        ii tem = q.front();
        int x = tem.first, y = tem.second;
        ST[x + y].push_back ( tem );
        near = max ( near, x + y );
        q.pop();
        for ( int k = 0; k < 4; ++k ) {
            int i = x + dx[k], j = y + dy[k];
            if ( i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ) continue;
            if ( s[i][j] == '0' ) {
                if ( !vis[i][j] ) {
                    vis[i][j] = 1;
                    q.push ( make_pair ( i, j ) );
                }
            }
        }
    }
}
void bfs2()
{
    queue<ii> q;
    for ( int i = 0; i < ST[near].size(); ++i ) {
        q.push ( make_pair ( ST[near][i].first, ST[near][i].second ) );
    }
    while ( !q.empty() ) {
        ii tem = q.front();
        int x = tem.first, y = tem.second;
        q.pop();
        if ( s[x][y] != ans[x + y] ) continue;
        for ( int k = 0; k < 2; ++k ) {
            int i = x + dx[k], j = y + dy[k];
            if ( i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ) continue;
            if ( s[i][j] == '0' ) {
                ans[i + j] = '0';
            }
            if ( !vis[i][j] ) {
                vis[i][j] = 1;
                q.push ( make_pair ( i, j ) );
            }
        }
    }
}
int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        memset ( vis, 0, sizeof vis );
        scanf ( "%d %d", &n, &m );
        near = 0;
        for ( int i = 0; i < n + m; ++i ) ST[i].clear();
        for ( int i = 0; i < n; ++i ) {
            scanf ( "%s", s[i] );
        }
        bfs ( );
        int h = ST[near][0].first + ST[near][0].second;
        for ( int i = 1; i < n + m; ++i ) ans[i] = '1';
        ans[h] = s[ST[near][0].first][ST[near][0].second];
        memset ( vis, 0, sizeof vis );
        bfs2();
        while ( ans[h] == '0' && h < ( n + m - 2 ) ) ++h;
        while ( h <= n + m - 2 ) {
            putchar ( ans[h] );
            ++h;
        }
        putchar ( 10 );
    }
    return 0;
}
