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

struct node {
    int k;
    int ch[2];
} Tr[2000];
int cnt, n, root, m;
string ans[N];

void add( int x , int  key )
{
    if( Tr[x].k == 0 ) {
        Tr[x].k = key;
        return ;
    }
    if( key < Tr[x].k ) {
        if( !Tr[x].ch[0] ) Tr[x].ch[0] = ++cnt;
        add( Tr[x].ch[0] , key );
    }
    if( key > Tr[x].k ) {
        if( !Tr[x].ch[1] ) Tr[x].ch[1] = ++cnt;
        add( Tr[x].ch[1] , key );
    }
}

void dfs( int x , string tem )
{
    int t = Tr[x].k;
    ans[t] = tem;
    if( Tr[x].ch[0] ) {
        dfs( Tr[x].ch[0], tem + 'E' );
    }
    if( Tr[x].ch[1] ) {
        dfs( Tr[x].ch[1], tem + 'W' );
    }
}

int main()
{
    int T;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &n );
        cnt = 0;
        for( int i = 1; i <= n; ++i ) {
            ans[i].clear();
        }
        memset( Tr, 0, sizeof Tr );
        for( int i = 1, x; i <= n; ++i ) {
            scanf( "%d", &x );
            add( 0 , x );
        }
        dfs( root , "" );
        scanf( "%d", &m );
        for( int i = 1, x; i <= m; ++i ) {
            scanf( "%d", &x );
            cout << ans[x] << endl;
        }
    }
    return 0;
}