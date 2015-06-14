#include <bits/stdc++.h>

using namespace std;

const int N = 213456;

int n;
typedef pair<int , int > ii;
set<ii> E[2][N];
bool ans[N];
int color[2][N];

inline void Del( int u, int v, int p , int k )
{
    if( !~color[k][u] ) color[k][u] = 0;
    ans[p] = color[k][u];
    E[k ^ 1][v].erase( make_pair( u, p ) );
    color[k ^ 1][v] = color[k][u] ^ 1;
}

void dfs( int x , int k )
{
    if( E[k][x].size() == 0 ) return ;
    ii tem = *E[k][x].begin();
    E[k][x].erase( E[k][x].begin() );
    Del( x, tem.first, tem.second, k );
    dfs( tem.first , k ^ 1 );
}
int main()
{
    memset( color, -1, sizeof color );
    scanf( "%d", &n );

    for( int i = 1, u, v; i <= n; ++i ) {
        scanf( "%d %d", &u, &v );
        E[0][u].insert( make_pair( v, i ) );
        E[1][v].insert( make_pair( u, i ) );
    }

    for( int i = 1; i <= int( 2e5 ); ++i ) {
        if( E[0][i].size() & 1 ) {
            dfs( i, 0 );
        }
        if( E[1][i].size() & 1 ) {
            dfs( i, 1);
        }
    }

    for( int i = 1; i <= int( 2e5 ); ++i ) {
        if( E[0][i].size() > 0 ) {
            dfs( i, 0 );
        }
    }

    for( int i = 1; i <= n; ++i )
        printf( "%c", ans[i] ? 'r' : 'b' );
}
