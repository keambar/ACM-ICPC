#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int Mod = ( int ) 1e9 + 7;

int n, m, t;
int dfn[N], out[N];

vector<int> pos[N][30];
vector<int> E[N];
char s[N];
void dfs ( int u, int de )
{
    dfn[u] = ++t;
    pos[de][s[u] - 'a'].push_back ( dfn[u] );
    for ( auto &v : E[u] ) {
        dfs ( v, de + 1 );
    }
    out[u] = t;
}

int main()
{
    scanf ( "%d %d", &n, &m );
    for ( int i = 2, u; i <= n; ++i ) {
        scanf ( "%d", &u );
        E[u].push_back ( i );
    }
    scanf ( "%s", s + 1 );
    dfs ( 1 , 1 );
    for ( int i = 1, u, d; i <= m; ++i ) {
        scanf ( "%d %d", &u, &d );
        int ttt = 0;
        for ( int j = 0; j < 26; ++j ) {
            int t = upper_bound ( pos[d][j].begin() , pos[d][j].end(), out[u] ) -
                    lower_bound (  pos[d][j].begin() , pos[d][j].end(), dfn[u] );
            if ( t & 1 ) {
                ++ttt;
                if(ttt>1) break;
            }
        }
        if ( ttt <= 1 ) {
            puts ( "Yes" );
        } else {
            puts ( "No" );
        }
    }
    return 0;
}