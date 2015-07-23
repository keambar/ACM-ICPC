#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 20003;
struct P {
    int x, y, r;
    ll d ( P b )
    {
        ll dx = x - b.x, dy = y - b.y;
        return dx * dx + dy * dy;
    }
} p[N];

bool cmp ( P a, P b )
{
    return a.r > b.r;
}
int n;

inline ll sqr ( ll x )
{
    return x * x;
}

struct Edge {
    int v, next;
} E[N << 1] ;
int head[N], cnt;

void add ( int u, int v )
{
    E[++cnt].v = v, E[cnt].next = head[u];
    head[u] = cnt;
}

int dfs ( int u )
{
    int ret =  0;
    for ( int i = head[u]; i; i = E[i].next ) {
        ret ^= dfs ( E[i].v ) + 1;
    }
    return ret;
}

int main()
{
    int re, ca = 1;
    cin >> re;
    while ( re-- ) {
        memset ( head, 0, sizeof head );
        cnt =  0;
        scanf ( "%d", &n );
        for ( int i = 0; i < n; i++ )
            scanf ( "%d%d%d", &p[i].x, &p[i].y, &p[i].r );
        sort ( p , p + n, cmp );
        int rt = n;
        for ( int i = n - 1; i > 0; i-- ) {
            bool ok = 0;
            for ( int j = i - 1; j >= 0; j-- ) {
                ll a = p[i].d ( p[j] );
                ll b = sqr ( p[j].r - p[i].r );
                if ( a < b ) {
                    ok = 1;
                    add ( j, i );
                    break;
                }
            }
            if ( !ok ) {
                add ( rt, i );
            }
        }
        add ( rt, 0 );
        int ans = dfs ( rt );
        puts ( ans ? "Alice" : "Bob" );
    }
    return 0;
}
