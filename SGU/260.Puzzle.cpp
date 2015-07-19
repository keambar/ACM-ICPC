/*
       解异或方程组
*/
#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;
const int N = 209;
bitset<N> a[N], mask[N];
int base[N];
int Gauss ( int n )
{
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= n; ++j ) {
            if ( a[i][j] ) {
                if ( !~base[j] ) {
                    mask[i][i] = 1;
                    base[j] = i;
                    break;
                }
                a[i] ^= a[base[j]];
                mask[i] ^= mask[base[j]];
            }
        }
    }
}

int n, m;
int main()
{
    ios::sync_with_stdio ( 0 );
    cin >> n;
    for ( int i = 1, k; i <= n; ++i ) {
        cin >> k;
        for ( int j = 1, t; j <= k; ++j ) {
            cin >> t;
            a[i][t] = 1;
        }
    }
    memset ( base, -1, sizeof base );
    Gauss ( n );
    for ( int i = 1, k; i <= n; ++i ) {
        cin >> k;
        a[n + 1][i] = k;
        a[n + 2][i] = k ^ 1;
    }
    int k;
    for ( k = 1; k <= n; ++k ) {
        if ( a[n + 1][k] == 1 ) {
            if ( !~base[k] ) {
                break;
            }
            a[n + 1] ^= a[base[k]];
            mask[n + 1] ^= mask[base[k]];
        }
    }
    if ( k > n ) {
        cout << mask[n + 1].count() << endl;
        for ( int i = 1; i <= n; ++i ) {
            if ( mask[n + 1][i] )
                cout << i << " ";
        }
    } else {
        for ( k = 1; k <= n; ++k ) {
            if ( a[n + 2][k] ) {
                if ( !~base[k] ) {
                    break;
                }
                a[n + 2] ^= a[base[k]];
                mask[n + 2] ^= mask[base[k]];
            }
        }
        if ( k > n ) {
            cout << mask[n + 2].count() << endl;
            for ( int i = 1; i <= n; ++i ) {
                if ( mask[n + 2][i] )
                    cout << i << " ";
            }
        } else {
            cout << -1 << endl;
        }
    }
}
