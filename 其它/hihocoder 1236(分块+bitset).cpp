/*
  思路：分别对5维量排序，分块，bitset存集合。求交集
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
const int N = 50004;
const int Mod = ( int ) 1e9 + 7;

struct node {
    int x, p;
} a[5][N];

bool cmp( node a, node b )
{
    return a.x < b.x;
}

int n, mc , q;

bitset<N> s[5][300], res[5];
int pos[N], l[300], r[300], qus[5];

int main()
{
    int T;
    scanf( "%d", &T );
    while( T-- ) {
        for( int i = 0; i < 5; ++i ) {
            for( int j = 1; j < 300; ++j ) {
                s[i][j].reset();
            }
        }
        scanf( "%d %d", &n, &mc );
        for( int i = 1; i <= n; ++i ) {
            for( int j = 0, x; j < 5; ++j ) {
                scanf( "%d", &x );
                a[j][i].x = x;
                a[j][i].p = i;
            }
        }
        for( int i = 0; i < 5; ++i ) {
            sort( a[i] + 1, a[i] + n + 1, cmp );
        }
        int bk = sqrt(n);
        int m = ( n - 1 ) / bk + 1;
        for( int i = 1; i <= m; ++i ) {
            l[i] = ( i - 1 ) * bk + 1;
            r[i] = i * bk;
        }
        r[m] = n;
        for( int i = 1; i <= n; ++i ) {
            pos[i] = ( i - 1 ) / bk + 1;
        }
        for( int i = 0; i < 5; ++i ) {
            for( int j = 1; j <= m; ++j ) {
                s[i][j] |= s[i][j - 1];
                for( int k = l[j]; k <= r[j]; ++k ) {
                    s[i][j][a[i][k].p] = 1;
                }
            }
        }
        int ans = 0;
        scanf( "%d", &q );
        while( q-- ) {
            for( int i = 0; i < 5; ++i ) {
                scanf( "%d", &qus[i] );
                qus[i] ^= ans;
                res[i].reset();
            }
            for( int i = 0; i < 5; ++i ) {
                int L = 0, R = n;
                while( L <= R ) {
                    int mid = ( L + R ) >> 1;
                    if( qus[i] >= a[i][mid].x ) {
                        L = mid + 1;
                    } else {
                        R = mid - 1;
                    }
                }
                int p = L - 1;
                if( p == 0 ) continue;
                int k = pos[p];
                res[i] |= s[i][k - 1];
                for( int j = l[k]; j <= p; ++j ) {
                    res[i][a[i][j].p] = 1;
                }
            }
            res[0] = res[0] & res[1] & res[2] & res[3] & res[4];
            ans = res[0].count();
            printf( "%d\n", ans );
        }
    }
}
