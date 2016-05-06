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
const int N = 1003;
const int Mod = ( int ) 1e9 + 7;
char G[1003][1003];
int f[1003][1003];
int n, m, ans;
int cacl()
{
    int res = 0;
    stack<int> s, p;
    for( int i = 1; i <= n; ++i ) {
        f[i][m + 1] = 0;
        for( int j = 1; j <= m + 1; ++j ) {
            int w = 0;
            while( !s.empty() && f[i][j] < s.top() ) {
                w += p.top();
                res = max( res, ( w + s.top() ) * 2 );
                s.pop(), p.pop();
            }
            if( f[i][j] > 0 ) {
                s.push( f[i][j] ), p.push( w + 1 );
            }
        }
    }
    return res;
}

int main()
{
    int T;
    scanf( "%d", &T );
    int cs = 0;
    while( T-- ) {
        scanf( "%d %d", &n, &m );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%s", G[i] + 1 );
        }
        ans = 0;
        for( int j = 1; j <= m; ++j ) {
            for( int i = 1; i <= n; ++i ) {
                if( G[i][j] == 'B' ) {
                    f[i][j] = f[i - 1][j] + 1;
                } else {
                    f[i][j] = 0;
                }
            }
        }
        ans = max( ans, cacl() );

        for( int j = 1; j <= m; ++j ) {
            for( int i = 1; i <= n; ++i ) {
                if( G[i][j] == 'R' ) {
                    f[i][j] = f[i - 1][j] + 1;
                } else {
                    f[i][j] = 0;
                }
            }
        }
        ans = max( ans, cacl() );

        for( int j = 1; j <= m; ++j ) {
            for( int i = 1; i <= n; ++i ) {
                if( G[i][j] != G[i - 1][j] ) {
                    f[i][j] = f[i - 1][j] + 1;
                } else {
                    f[i][j] = 1;
                }
            }
        }
        int  s[N], p[N];
        for( int i = 1; i <= n; ++i ) {
            f[i][m + 1] = 0;
            int top = 0;
            for( int j = 1; j <= m + 1; ++j ) {
                int w = 0;
                while( top != 0 && ( f[i][j] < s[top] || ( j != 0 && G[i][j] == G[i][j - 1] ) ) ) {
                    w += p[top];
                    ans = max( ans, min( w , s[top] ) * 4 );
                    --top;
                }
                if( f[i][j] > 0 ) {
                    s[++top] = f[i][j];
                    if( G[i][j] != G[i][j - 1] )
                        p[top] = w + 1;
                    else
                        p[top] = 1;
                }
            }
        }
        printf( "Case #%d: %d\n", ++cs, ans );
    }
}
/*
1
5 6
BRRBRB
RBBRBR
RBRBRB
BBBRBR
BRRBRB
*/
