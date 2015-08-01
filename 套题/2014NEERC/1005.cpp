#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int MAXN = 110;
const int MAXN_2 = 50010;

int e[MAXN][3], e2[MAXN_2][3];
int sta[MAXN], sta2[MAXN_2];
int vis[MAXN][MAXN_2];
int tot, cnt, n;

void new_copy()
{
    for ( int i = 1; i <= n; ++i ) { //建立完全映射FSM
        sta2[i + cnt] = ( sta[i] + 1 ) % 3;
        e2[i + cnt][sta[i]] = e[i][sta2[i + cnt]] + cnt;
    }
}

void Solve ( int st )
{
    int u = st, v = 1;
    tot++;
    while ( 1 ) {
        if ( vis[u][v] == tot ) break; //检测到环
        vis[u][v] = tot;
        int nxt_u = e[u][sta2[v]];
        int &nxt_v = e2[v][sta[u]];
        if ( nxt_v == 0 ) { //没有后继点
            new_copy();
            e2[v][sta[u]] = nxt_u + cnt; //进入另外造的必胜copy后指向对应的点
            cnt += n;
        }
        u = nxt_u;
        v = nxt_v;
    }
}

int main()
{
    freopen ( "epic.in", "r", stdin );
    freopen ( "epic.out", "w", stdout );
    char s[10];
    char Ch[4] = "RPS";
    int a, b, c;
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i ) {
        scanf ( "%s%d%d%d", s, &a, &b, &c );
        sta[i] = s[0] == 'R' ? 0 : ( s[0] == 'P' ? 1 : 2 );
        e[i][0] = a;
        e[i][1] = b;
        e[i][2] = c;
    }
    for ( int i = 1; i <= n; ++i ) Solve ( i );
    printf ( "%d\n", cnt );
    for ( int i = 1; i <= cnt; ++i ) {
        printf ( "%c %d %d %d\n", Ch[sta2[i]],
                 max ( 1, e2[i][0] ), max ( 1, e2[i][1] ), max ( 1, e2[i][2] ) );
    }
    return 0;
}