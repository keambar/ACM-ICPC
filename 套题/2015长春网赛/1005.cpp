#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
int fa[20010];
int seek( int v )
{
    return v == fa[v] ? v : fa[v]=seek( fa[v] );
}
struct Q {
    int id, val;
    bool operator <( Q a )const
    {
        return val < a.val;
    }
} qbx[5010];
struct E {
    int a, b, val;
    bool operator <( E one )const
    {
        return val < one.val;
    }
} ebx[100010];
int num[20010];
int asbx[5010];
int work( int x )
{
    return x * ( x - 1 );
}
int main()
{
    int T;
    scanf( "%d", &T );
    while( T-- ) {
        int n, m, q;
        scanf( "%d%d%d", &n, &m, &q );
        for( int i = 0; i < m; i++ )
            scanf( "%d%d%d", &ebx[i].a, &ebx[i].b, &ebx[i].val );
        for( int i = 0; i < q; i++ ) {
            scanf( "%d", &qbx[i].val );
            qbx[i].id = i;
        }
        for( int i = 1; i <= n; i++ ) {
            fa[i] = i;
            num[i] = 1;
        }
        sort( ebx, ebx + m );
        sort( qbx, qbx + q );
        int hehe = 0, ans = 0;
        for( int i = 0; i < q; i++ ) {
            while( hehe < m && ebx[hehe].val <= qbx[i].val ) {
                int t1 = seek( ebx[hehe].a ), t2 = seek( ebx[hehe].b );
                if( t1 != t2 ) {
                    ans -= work( num[t1] ) + work( num[t2] );
                    fa[t2] = t1;
                    num[t1] += num[t2];
                    ans += work( num[t1] );
                }
                hehe++;
            }
            asbx[qbx[i].id] = ans;
        }
        for( int i = 0; i < q; i++ )
            printf( "%d\n", asbx[i] );
    }
    return 0;
}