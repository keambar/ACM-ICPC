#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <map>
#define ll long long
using namespace std;

const int N = 50;
const int M = ( int ) 1e9 + 7;
struct Mat {
    ll mat[N+1][N + 1];
} A, B;
int n, m;
string s[N];

Mat operator * ( Mat a, Mat b )
{
    Mat c;
    memset ( c.mat, 0, sizeof c.mat );
    for ( int k = 0; k <  N; k++ )
        for ( int i = 0; i <  N; i++ )
            for ( int j = 0; j <  N; j++ )
                ( c.mat[i][j] += ( a.mat[i][k] * b.mat[k][j] ) % M ) %= M;
    return c;
}

Mat operator ^ ( Mat a, int pow )
{
    Mat c;
    for ( int i = 0; i <  N; i++ )
        for ( int j = 0; j <  N; j++ )
            c.mat[i][j] = ( i == j );
    while ( pow ) {
        if ( pow & 1 )     c = c * a;
        a = a * a;
        pow >>= 1;
    }
    return c;
}

int main()
{
    int T;
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d %d", &n, &m );
        for ( int i = 0; i < n; ++i ) {
            cin>>s[i];
        }
        sort ( s, s + n );
        n = unique ( s, s + n ) - s;
        memset ( B.mat, 0, sizeof B.mat );
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                int li = s[i].size(), lj = s[j].size();
                int len = min ( li, lj );
                for ( int k = 2; k <= len; ++k ) {
                    int flag = 1;
                    for ( int t = 0; t < k; ++t ) {
                        if ( s[i][li - k +t] != s[j][t] ) {
                            flag = 0;
                            break;
                        }
                    }
                    if ( flag ) {
                        B.mat[i][j] = 1;
                        break;
                    }
                }
            }
        }
        memset ( A.mat, 0, sizeof A );
        for ( int i = 0; i < n; ++i ) {
            A.mat[0][i] = 1;
        }
        B = B ^ (m-1);
        A = A * B;
        ll ans = 0;
        for ( int i = 0; i < n; ++i ) {
            ans = ( ans + A.mat[0][i] ) % M;
        }
        printf ( "%I64d\n", ans );
    }
    return 0;
}
