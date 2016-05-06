/*
    思路：用并查集维护相同的关系，对每个父节点用set存下不等关系，启发式合并加速
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

map<int, int> p;
set<int> hs[N];
int f[N];
int n, cmd;

int Find( int x )
{
    return f[x] == x ? x : f[x] = Find( f[x] );
}

inline void Merge( int x, int y )
{
    int u = Find( x ), v = Find( y );
    if( cmd == 1 ) {
        if( hs[u].find( v ) != hs[u].end() || hs[v].find( u ) != hs[v].end() ) {
            puts( "NO" );
            return ;
        }
        puts( "YES" );
        if( u == v ) {
            return ;
        }
        if( hs[u].size() < hs[v].size() ) swap( u, v );
        f[v] = u;
        for( auto &it : hs[v] ) {
            int tmp = Find( it );
            hs[u].insert( tmp );
        }
        hs[v].clear();
    }
    if( cmd == 0 ) {
        if( u == v ) {
            puts( "NO" );
            return ;
        }
        puts( "YES" );
        hs[u].insert( v );
        hs[v].insert( u );
    }
}
int main()
{
    scanf( "%d", &n );
    for( int i = 1; i <= ( n << 1 ); ++i ) {
        f[i] = i;
    }
    int cnt = 0, x, y;
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d %d %d", &x, &y, &cmd );
        if( p[x] == 0 ) {
            p[x] = ++cnt;
        }
        int u = p[x];

        if( p[y] == 0 ) {
            p[y] = ++cnt;
        }
        int v = p[y];
        Merge( u, v );
    }
}
