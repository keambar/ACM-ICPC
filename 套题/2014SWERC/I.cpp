#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define LL long long
using namespace std;
const int N = 502;

int a[N];
char s[N];
LL dp1[N][N], dp2[N][N];

int n;
int main()
{
    while ( scanf ( "%d", &n ) != EOF ) {
        char sym[2];
        for ( int i = 0, x; i < n; ++i ) {
            scanf ( "%d %s", &x, sym );
            a[i] = a[i + n] = x;
            s[i] = s[i + n] = sym[0];
        }
        for ( int i = 0; i < ( n << 1 ); ++i ) {
            for ( int j = 0; j < ( n << 1 ); ++j ) {
                dp1[i][j] = ( 1LL << 60 );
                dp2[i][j] = - ( 1LL << 60 );
            }
            dp1[i][i] = dp2[i][i] = a[i];
        }
        for ( int len = 1; len <= n; ++len ) {
            for ( int l = 0; l + len < ( n << 1 ); ++l ) {
                for ( int k = l; k + 1 <= l + len; ++k ) {
                    int r = l + len;
                    if ( s[k] == '+' || s[k] == '?' ) {
                        dp1[l][r] = min ( dp1[l][r], dp1[l][k] + dp1[k + 1][r] );
                        dp2[l][r] = max ( dp2[l][r], dp2[l][k] + dp2[k + 1][r] );
                    }
                    if ( s[k] == '-' || s[k] == '?' ) {
                        dp1[l][r] = min ( dp1[l][r], dp1[l][k] - dp2[k + 1][r] );
                        dp2[l][r] = max ( dp2[l][r], dp2[l][k] - dp1[k + 1][r] );
                    }
                    if ( s[k] == '*' || s[k] == '?' ) {
                        dp1[l][r] = min ( dp1[l][r], dp1[l][k] * dp1[k + 1][r] );
                        dp1[l][r] = min ( dp1[l][r], dp1[l][k] * dp2[k + 1][r] );
                        dp1[l][r] = min ( dp1[l][r], dp2[l][k] * dp1[k + 1][r] );
                        dp1[l][r] = min ( dp1[l][r], dp2[l][k] * dp2[k + 1][r] );

                        dp2[l][r] = max ( dp2[l][r], dp2[l][k] * dp2[k + 1][r] );
                        dp2[l][r] = max ( dp2[l][r], dp2[l][k] * dp1[k + 1][r] );
                        dp2[l][r] = max ( dp2[l][r], dp1[l][k] * dp2[k + 1][r] );
                        dp2[l][r] = max ( dp2[l][r], dp1[l][k] * dp1[k + 1][r] );
                    }
                }
            }
        }
        for ( int l = 0; l < n; ++l ) {
            int r = l + n - 1;
            cout << abs ( dp1[l][r] ) << abs ( dp2[l][r] );
        }
        cout << endl;
    }
}
