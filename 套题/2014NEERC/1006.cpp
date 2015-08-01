#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <set>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int N = 1009;
int m, n, k, q;
int a[N], sum[N];
bitset<N> bt[N];
char s[][10] = {
    ( "0000" ), ( "1000" ), ( "0100" ), ( "1100" ),
    ( "0010" ), ( "1010" ), ( "0110" ), ( "1110" ),
    ( "0001" ), ( "1001" ), ( "0101" ), ( "1101" ),
    ( "0011" ), ( "1011" ), ( "0111" ), ( "1111" )
};
char f[N];
string p[N];
vector<int> ans;
int main()
{
    freopen("filter.in","r",stdin);
    freopen("filter.out","w",stdout);
    scanf ( "%d %d", &m, &n );
    for ( int i = 1; i <= n; ++i ) {
        scanf ( "%d", &a[i] );
        a[i] %= m;
    }
    scanf ( "%d", &k );
    for ( int i = 1; i <= k; ++i ) {
        scanf ( "%s", f );
        int len = strlen ( f );
        for ( int j = 0; j < len; ++j ) {
            if ( f[j] >= '0' && f[j] <= '9' ) {
                p[i] += s[f[j] - '0'];
            } else {
                p[i] += s[f[j] - 'a' + 10];
            }
        }
        for ( int j = 0; j < p[i].size(); ++j ) {
            bt[i][j] = ( p[i][j] == '1' );
        }
    }
    int tol = 0;
    scanf ( "%d", &q );
    for ( int i = 1, t; i <= q; ++i ) {
        scanf ( "%d", &t );
        t %= m;
        bitset<N> tem;
        for ( int j = 1; j <= n; ++j ) {
            tem[a[j]*t % m] = 1;
        }
        for ( int j = 1; j <= k; ++j ) {
            if ( ( tem & bt[j] ) == tem ) {
                if ( ++sum[j] == 1 ) ans.push_back ( j - 1 );
            }
        }
    }
    printf ( "%d", ans.size() );
    sort(ans.begin(),ans.end());
    for ( int i = 0; i < ans.size(); ++i ) {
        printf ( " %d", ans[i] );
    }
    putchar ( 10 );
    return 0;
}