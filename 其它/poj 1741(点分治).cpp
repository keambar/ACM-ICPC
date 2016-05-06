#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 10004;

vector<int> E[N], C[N], tem;
int siz[N], dis[N], mx[N], vis[N], Siz;
int n, m, k;
int root, ans;

void Root ( int u, int fa )
{
    siz[u] = 1;
    mx[u] = 0;
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i];
        if ( v != fa && !vis[v] ) {
            Root ( v, u );
            siz[u] += siz[v];
            mx[u] = max ( mx[u], siz[v] );
        }
    }
    mx[u] = max ( mx[u], Siz - siz[u] );
    if ( mx[u] < mx[root]  ) root = u;
}

void Dis ( int u, int fa  )
{
    tem.push_back ( dis[u] );
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i], c = C[u][i];
        if ( v != fa && !vis[v] ) {
            dis[v] = dis[u] + c;
            Dis ( v, u );
        }
    }
}

int Calc ( int u, int w )
{
    dis[u] = w;
    tem.clear(), Dis ( u, 0 );
    sort ( tem.begin(), tem.end() );
    int ret = 0;
    for ( int i = 0, j = tem.size() - 1; i < j; ) {
        if ( tem[i] + tem[j] <= k && i < j )  ret += ( j - i ), ++i;
        else --j;
    }
    return ret;
}
void make ( int u )
{
    vis[u] = 1;
    ans += Calc ( u, 0 );
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i], c = C[u][i];
        if ( vis[v] ) continue;
        ans -= Calc ( v, c );
        Siz = siz[u];
        Root ( v , root = 0 );
        make ( root );
    }
}

inline void init()
{
    ans = 0;
    for ( int i = 1; i <= n; ++i ) {
        E[i].clear(), C[i].clear();
        siz[i] = 0, vis[i] = 0;
    }
    mx[0] = N;
}

int main()
{
    while ( scanf ( "%d %d", &n, &k ) , n && k ) {
        init();
        for ( int i = 1, u, v, c; i < n; ++i ) {
            scanf ( "%d %d %d", &u, &v, &c );
            E[u].push_back ( v ), C[u].push_back ( c );
            E[v].push_back ( u ), C[v].push_back ( c );
        }
        Siz = n;
        Root ( 1, 0 );
        make ( root );
        printf ( "%d\n", ans );
    }
}
/*
5 4
1 2 1
2 3 2
3 4 3
4 5 2
0 0
ans:5
*/
