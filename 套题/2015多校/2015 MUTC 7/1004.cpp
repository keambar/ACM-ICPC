#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 500005;

int sl[N], sr[N];
int a[N], b[N], tl[N], tr[N], tol;

int n;

void add ( int *s, int x, int k )
{
    for ( ; x < N; x += x & -x ) s[x] += k;
}

int gets ( int *s, int x )
{
    int ret = 0;
    for ( ; x > 0; x -= x & -x ) ret += s[x];
    return ret;
}
int main()
{
    int cs = 0;
    while ( scanf ( "%d", &n ) != EOF ) {
        memset ( sl, 0, sizeof sl );
        memset ( sr, 0, sizeof sr );
        printf ( "Case #%d:\n", ++cs );
        vector<int> spr;
        tol=0;
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d %d", &a[i], &b[i] );
            if ( a[i] == 0 ) {
                spr.push_back ( b[i] );
                spr.push_back ( b[i] + (++tol) );
            }
        }
        sort ( spr.begin(), spr.end() );
        spr.erase ( unique ( spr.begin(), spr.end() ), spr.end() );
        tol = 0;
        for ( int i = 1; i <= n; ++i ) {
            if ( a[i] == 0 ) {
                int l = lower_bound ( spr.begin(), spr.end(), b[i] ) - spr.begin() + 1;
                int r = lower_bound ( spr.begin(), spr.end(), b[i] + (++tol) ) - spr.begin() + 1;
                tl[tol] = l, tr[tol] = r;
                printf ( "%d\n", gets ( sr, r ) - gets ( sl, l - 1 ) );
                add ( sl, l, 1 );
                add ( sr, r, 1 );
            } else {
                add ( sl, tl[b[i]], -1 );
                add ( sr, tr[b[i]], -1 );
            }
        }
    }
}
