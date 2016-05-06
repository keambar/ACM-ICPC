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
const int N = 4000006;
const int Mod = ( int ) 1e9 + 7;

char s[N];
int main()
{
    int T, cs = 0;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%s", s );
        int n = strlen( s );
        int ans = 0;
        for( int i = n; i < n + n; ++i ) {
            s[i] = s[i - n];
            if( s[i] != 'c' && s[i] != 'f' ) {
                ans = -1;
                break;
            }
        }
        if( ans == -1 ) {
            printf( "Case #%d: %d\n", ++cs, ans );
            continue;
        }
        int i = 0;
        for( ; i < n + n; ++i ) {
            if( s[i] == 'c' ) break;
        }
        if( i == n + n ) {
            ans = n / 2 + ( n & 1 );
        } else {
            ++ans;
            int p = i;
            for( int j = i + 1; j - i + 1 <= n; ++j ) {
                if( s[j] == 'c' ) {
                    if( j - p - 1 >= 2 ) {
                        ++ans;
                        p = j;
                    } else {
                        ans = -1;
                        break;
                    }
                }
            }
            if( i + n - p - 1 < 2 ) {
                ans = -1;
            }
        }
        printf( "Case #%d: %d\n", ++cs, ans );
    }
}