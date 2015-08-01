#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int N = 1009;
int n, m;
int s[N], l[N], r[N];

int main()
{
    freopen("knockout.in","r",stdin);
    freopen("knockout.out","w",stdout);
    scanf ( "%d %d", &n, &m );
    for ( int i = 1; i <= n; ++i ) {
        scanf ( "%d %d", &l[i], &r[i] );
        s[i] = ( r[i] - l[i] );
    }
    for ( int i = 1, sl, sr, t; i <= m; ++i ) {
        scanf ( "%d %d %d", &sl, &sr, &t );
        int ans = 0;
        for ( int j = 1; j <= n; ++j ) {
            int pos = t % ( s[j] * 2 );
            if ( pos > s[j] ) pos = 2 * s[j] - pos;
            pos += l[j];
            if ( pos >= sl && pos <= sr ) ++ans;
        }
        printf ( "%d\n", ans );
    }
    return 0;
}