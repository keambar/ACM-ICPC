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
const int N = 110;

int meet[N][N];
char g[N][N];
int n;
int main()
{
    int T;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%s", g[i] );
        }
        memset( meet, 0, sizeof meet );
        for( int i = 0; i < n; ++i ) {
            meet[i][( i + 1 ) % n] = 1;
        }
        for( int j = 2; j <= n; ++j ) {
            for( int i = 0; i < n; ++i ) {
                int r = ( i + j ) % n;
                for( int k = i + 1; k < i + j; ++k ) {
                    if( meet[i][k % n] && meet[k % n][r] && ( g[i][k % n] == '1' || g[r][k % n] == '1' ) ) {
                        meet[i][r] = 1;
                        break;
                    }
                }
            }
        }
        vector<int> out;
        for( int i = 0; i < n; ++i ) {
            if( meet[i][i] ) {
                out.pb( i + 1 );
            }
        }
        printf( "%d\n", SZ( out ) );
        for( int i = 0; i < SZ( out ); ++i ) {
            printf( "%d\n", out[i] );
        }
    }
    return 0;
}
