#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 105;
int n, m, r, c;
int T, time, sx, sy, now;
int xx[N*N], yy[N*N];
int res[N][N], ans[N*N];
int a[N][N], tot[2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct drop {
    int x, y;
    int dx, dy;
} d[2][N*N];

void init()
{
    memset ( a, 0, sizeof a );
    memset ( ans, 0, sizeof ans );
    tot[0] = 4;
    now = 0;
}

void solve ( int time )
{
    tot[now ^ 1] = 0;
    for ( int i = 0; i < tot[now]; i++ ) {
        drop t = d[now][i];
        t.x += t.dx;
        t.y += t.dy;
        if ( t.x < 1 || t.x > r || t.y < 1 || t.y > c ) continue;
        if ( a[t.x][t.y] ) {
            a[t.x][t.y]++;
        } else {
            d[now ^ 1][tot[now ^ 1]++] = drop {t.x, t.y, t.dx, t.dy};
        }
    }
    for ( int i = 0; i < n; i++ ) {
        int x = xx[i], y = yy[i];
        if ( a[x][y] > 4 ) {
            ans[i] = time;
            a[x][y] = 0;
            for ( int j = 0; j < 4; j++ ) {
                d[now ^ 1][tot[now ^ 1]++] = drop {x, y, dx[j], dy[j]};
            }
        }
    }
    now ^= 1;
}
int main()
{
    while ( scanf ( "%d%d%d%d", &r, &c, &n, &time ) != EOF ) {
        init();
        for ( int i = 0, siz; i < n; i++ ) {
            scanf ( "%d%d%d", &xx[i], &yy[i], &siz );
            a[xx[i]][yy[i]] = siz;
            res[xx[i]][yy[i]] = i;
        }
        scanf ( "%d%d", &sx, &sy );
        for ( int i = 0; i < 4; i++ ) {
            d[0][i].x = sx;
            d[0][i].y = sy;
            d[0][i].dx = dx[i];
            d[0][i].dy = dy[i];
        }
        for ( int i = 1; i <= time; i++ ) {
            solve ( i );
        }
        for ( int i = 0; i < n; i++ ) {
            if ( ans[i] ) {
                printf ( "0 %d\n", ans[i] );
            } else {
                printf ( "1 %d\n", a[xx[i]][yy[i]] );
            }
        }
    }
    return 0;
}
