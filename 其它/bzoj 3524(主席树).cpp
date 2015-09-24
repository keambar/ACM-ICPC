/*
    bzoj3524 主席树
*/
#include <iostream>
#include <cstdio>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int N = 500005;
const int Mod = ( int ) 1e9 + 7;

int ls[N*200], rs[N*200], sum[N*200];
int root[N];
int cnt, n, m;

//构造n颗线段树，保存在区间1~i的数的数目
void update( int l, int r, int k, int x, int &y )
{
    y = ++cnt;
    sum[y] = sum[x] + 1;
    if( l == r ) return;
    ls[y] = ls[x], rs[y] = rs[x];
    int mid = ( l + r ) >> 1;
    if( k <= mid ) {
        update( l, mid, k, ls[x], ls[y] );
    } else {
        update( mid + 1, r, k, rs[x], rs[y] );
    }
}

//利用第r颗和第l颗线段树求差，找到一个数字k（即区间[k,k]）
//在两颗树的数目差大于( r - l + 1 ) >> 1
int query( int l, int r )
{
    int h = 1, t = n, mid;
    int x = root[l - 1], y = root[r], tem = ( r - l + 1 ) >> 1;
    while( h != t ) {
        if( sum[y] - sum[x] <= tem ) return 0;
        mid = ( h + t ) >> 1;
        if( sum[ls[y]] - sum[ls[x]] > tem ) {
            t = mid, x = ls[x], y = ls[y];
        } else if( sum[rs[y]] - sum[rs[x]] > tem ) {
            h = mid + 1, x = rs[x], y = rs[y];
        } else return 0;
    }
    return h;
}

int main()
{
    scanf( "%d %d", &n, &m );
    for( int i = 1, x; i <= n; ++i ) {
        scanf( "%d", &x );
        update( 1, n, x, root[i - 1], root[i] );
    }
    for( int i = 1, l, r; i <= m; ++i ) {
        scanf( "%d %d", &l, &r );
        printf( "%d\n", query( l, r ) );
    }
}
