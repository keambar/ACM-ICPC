#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 31111;

vector<int> edge[INF], ans;
int f[INF];
int n, k, tol;
int dfs ( int x , int fa )
{
    int dmax = -INF, dmin = INF, s = 0;
    f[x] = k + 1;
    for ( int i = 0; i < edge[x].size(); ++i ) {
        int v = edge[x][i];
        if ( v == fa ) continue;
        ++s;
        dfs ( v , x );
        dmin = min ( f[v], dmin );
        dmax = max ( f[v], dmax );
    }
    if ( s ) {
        if ( dmin + dmax + 2 <= 2 * k + 1 ) f[x] = dmin + 1;
        else f[x] = dmax + 1;
    }
    if ( f[x] == 2 * k + 1 ) {
        f[x] = 0;
        ++tol;
    }
}

int main()
{
    scanf ( "%d %d", &n, &k );
    for ( int i = 2, x, y; i <= n; ++i ) {
        scanf ( "%d %d", &x, &y );
        edge[x].push_back ( y );
        edge[y].push_back ( x );
    }
    dfs ( 1 , 0 );
    if ( f[1] > k ) ++tol, f[1] = 0;
    printf ( "%d\n", tol );
    for ( int i = 1; i <= n; i++ )
        if ( f[i] == 0 ) printf ( "%d\n", i );
}
/*
14 3
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
7 10
7 11
10 12
11 13
13 14

answer:
2
1
7
*/
