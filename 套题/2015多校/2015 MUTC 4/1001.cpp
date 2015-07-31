#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int N = 100009;
int f[N];
int main()
{
    for ( int i = 1, k; i <= 100000; ++i ) {
        int vis[10] = {0};
        for ( k = i; k; k /= 10 ) {
            if ( ++vis[k % 10] > 1 ) break;
        }
        f[i] = f[i - 1] + ( k == 0 );
    }
    int T, l, r;
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d %d", &l, &r );
        printf ( "%d\n", f[r] - f[l - 1] );
    }
    return 0;
}
