/*
	离线问题并排序，n*m的DP求出所求值，将所需要的值存下来。需要用滚动数组优化空间。
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
const int N = 20005;
const int Mod = ( int ) 1e9 + 7;

pair<int, int> a[N];
int p[N];
bool cmp( int x, int y )
{
    return a[x] < a[y];
}
int dp[2][N], f[N];

int n, m;

int ans[N];

int main()
{
    int T;
    scanf( "%d", &T );
    for( int i = 1; i <= T; ++i ) {
        p[i] = i;
        scanf( "%d %d", &n, &m );
        a[i] = mp( n, m );
    }
    sort( p + 1, p + 1 + T, cmp );

    int roll = 0, k = 1;

    while( a[p[k]].fi == 1 ) {
        if( a[p[k]].se == 0 ) ans[p[k]] = 1;
        else ans[p[k]] = 0;
        ++k;
    }

    dp[roll][0] = 1;
    for( int i = 2; i <= 1000; ++i ) {
        f[0] = dp[roll][0];
        for( int j = 1; j <= min( 20000, i * ( i - 1 ) / 2 ); ++j ) {
            f[j] = ( f[j - 1] + dp[roll][j] ) % Mod;
        }
        roll ^= 1;
        for( int j = 0; j <= min( 20000, i * ( i - 1 ) / 2 ); ++j ) {
            if( j - i >= 0 ) {
                dp[roll][j] = ( f[j] - f[j - i] + Mod ) % Mod;
            } else {
                dp[roll][j] = f[j];
            }
        }
        while( a[p[k]].fi == i ) {
            ans[p[k]] = dp[roll][a[p[k]].se];
            ++k;
        }
    }
    for( int i = 1; i <= T; ++i )
        printf( "%d\n", ans[i] );
}
