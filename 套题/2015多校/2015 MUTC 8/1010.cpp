#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
#define pb push_back
#define mp make_pair
#define LL long long
#define sz( a ) (int)a.size()
#define all( a ) a.begin(), a.end()
#define second sd
#define first ft
const int N = 100005;
const int Mod = ( int ) 258280327;

int n, a[N];

LL f[2][10][10];

int T, A, B;
int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d %d %d", &n, &A, &B );
        A %= 9, B %= 9;
        memset ( f, 0, sizeof f );
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &a[i] );
        }
        int roll = 1;
        f[0][0][0] = 1;
        for ( int i = 1; i <= n; ++i ) {
            for ( int k = 0; k <= 9; ++k ) {
                for ( int t = 0; t <= 9; ++t ) {
                    if ( f[roll ^ 1][k][t] != 0 ) {
                        ( f[roll][ ( k * 10 + a[i] ) % 9][t] += f[roll ^ 1][k][t] ) %= Mod;
                        ( f[roll][k][ ( t * 10 + a[i] ) % 9] += f[roll ^ 1][k][t] ) %= Mod;
                    }
                }
            }
            memset ( f[roll ^ 1], 0, sizeof f[roll] );
            roll ^= 1;
        }
        int ans = int ( f[roll ^ 1][A][B] );
        printf ( "%d\n", ans );
    }
}