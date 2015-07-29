#include <bits/stdc++.h>
#define LL long long
using namespace std;
int l, r, flag, n;
int dfs ( int l, int r )
{
    int len = ( r - l + 1 );
    if ( l == 0 ) {
        flag = 1;
        n = min ( n, r );
        return flag;
    }
    if ( len  > l + 1 ) return 0;
    if ( !dfs ( l - len, r ) && ( l >= len + 1 ) )
        dfs ( l - len - 1, r );
    if ( !dfs ( l, r + len - 1 ) )
        dfs ( l, r + len );
}
int main()
{
    while ( scanf ( "%d %d", &l, &r ) != EOF ) {
        flag = 0;
        n = 0x7fffffff;
        if ( l == r ) {
            flag = 1;
            n = r;
        } else
            dfs ( l, r );
        if ( !flag ) {
            puts ( "-1" );
        } else printf ( "%d\n", n );
    }
    return 0;
}
