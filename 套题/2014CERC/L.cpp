#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define LL long long
#define sz( a ) int( a.size() )
#define all( a ) a.begin(), a.end()
#define sd second
#define ft first
const int INF = 0x3f3f3f3f;
const int N = 400;
int a[N], b[N], d[N];
int dp[2 * N][2 * N];
int posa[N], posb[N];
int main()
{
    int T;
    scanf ( "%d", &T );
    while ( T-- ) {
        int n;
        memset ( dp, 0, sizeof dp );
        scanf ( "%d", &n );
        vector<int> tem;
        for ( int i = 0; i < n; i++ ) {
            scanf ( "%d %d %d", &a[i], &b[i], &d[i] );
            tem.pb ( a[i] ), tem.pb ( b[i] );
        }
        tem.pb ( -INF ), tem.pb ( +INF );
        sort ( all ( tem ) );
        tem.erase ( unique ( all ( tem ) ), tem.end() );
        int m = sz ( tem );
        for ( int i = 0; i < n; ++i ) {
            for ( int j = m; j > 0; --j ) {
                if ( a[i] == tem[j] ) {
                    posa[i] = j;
                }
                if ( b[i] == tem[j] ) {
                    posb[i] = j;
                }
            }
        }
        for ( int j = 1; j < m; ++j ) {
            for ( int l = 0; l + j < m; ++l ) {
                int r = l + j, p = -1;
                for ( int i = 0; i < n; ++i ) {
                    if ( ( a[i] > tem[l] ) && ( b[i] < tem[r] ) ) {
                        if ( p == -1 || d[i] > d[p] ) {
                            p = i;
                        }
                    }
                }
                if ( p != -1 ) {
                    dp[l][r] = INF;
                    int nl = posa[p], nr = posb[p];
                    for ( int i = nl; i <= nr; i++ )
                        dp[l][r] = min ( dp[l][r], d[p] + dp[l][i] + dp[i][r] );
                }
            }
        }
        printf ( "%d\n", dp[0][m - 1] );
    }
}
