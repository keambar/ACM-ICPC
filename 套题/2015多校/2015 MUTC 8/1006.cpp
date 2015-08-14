#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define LL long long
#define sz( a ) int( a.size() )
#define all( a ) a.begin(), a.end()
#define sd second
#define ft first
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;

struct node {
    int u, v, ne;
} edge[N << 1];
int head[N], cnt;
int fa[N], dis[N];

void addedge ( int a, int b )
{
    edge[++cnt] = ( node ) {
        a, b, head[a]
    };
    head[a] = cnt;
}

void init()
{
    memset ( fa, 0, sizeof ( fa ) );
    memset ( head, -1, sizeof ( head ) );
    cnt = 0;
    fa[1] = -1;
    dis[1] = 0;
}

void expand ( int u )
{
    for ( int i = head[u]; i != -1; i = edge[i].ne ) {
        int v = edge[i].v;
        if ( !fa[v] )
            fa[v] = u;
    }
}

int main()
{
    int T, n, m, a, b;
    int s, l, r;
    scanf ( "%d", &T );
    while ( T-- ) {
        init();
        scanf ( "%d%d", &n, &m );
        for ( int i = 0; i < m; i++ ) {
            scanf ( "%d%d", &a, &b );
            addedge ( a, b );
        }

        s = 1;
        l = 1, r = n;
        while ( l <= r ) {
            if ( fa[l] ) {
                expand ( l );
                dis[l++] = s++;
            }
            if ( fa[r] ) {
                expand ( r );
                dis[r--] = s++;
            }
        }
        for ( int i = 1; i <= cnt; i++ ) {
            a = edge[i].u;
            b = edge[i].v;
            if ( fa[b] != a )
                printf ( "%d\n", n );
            else
                printf ( "%d\n", dis[b] - dis[a] );
        }
    }
    return 0;
}
