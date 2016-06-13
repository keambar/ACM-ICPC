#include <cstdio>
#include <cstring>
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
char s[200];
int dp[100][100];
int main()
{
    int CS;
    //freopen( "A.in", "r", stdin );
    //freopen( "A.txt", "w", stdout );
    scanf( "%d", &CS );
    while( CS-- ) {
        scanf( "%s", s );
        memset( dp, 0, sizeof dp );
        int len = strlen( s );
        for( int k = 2; k <= len; ++k ) {
            for( int i = 0; i + k -1 <= len; ++i ) {
                int j = i + k - 1;
                if( ( s[i] == '(' || s[i] == '?' ) && ( s[j] == ')' || s[j] == '?' ) ) {
                    if( k > 2 )dp[i][j] |= dp[i + 1][j - 1];
                    else dp[i][j] = 1;
                    for( int t = i + 1; t < j && !dp[i][j]; ++t ) {
                        dp[i][j] |= dp[i][t] & dp[t + 1][j];
                    }
                }
            }
        }
        if( dp[0][len - 1] ) puts( "yes" );
        else puts( "no" );
    }

}
