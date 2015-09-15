/*
	必须存在长度为1或者2的环
	存在长度为1的环i 输出 i j(j!=i)
	仅有长度为2的环时,其他环的长度必须为偶数
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
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;
int n, m;
int a[N], f[N], s[N];
int main()
{
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d", &a[i] );
    }
    int root = -1;
    int ok = 1;
    for( int i = 1; i <= n; ++i ) {
        if( a[a[i]] == i ) {
            root = i;
        }
        if( a[i] == i ) {
            root = i;
            break;
        }
    }
    int tol = 0;
    for( int i = 1; i <= n; ++i ) {
        int k = i, tol = 0;
        while( !f[k] ) {
            ++tol;
            f[k] = 1;
            k = a[k];
        }
        if( tol > 1 && ( tol & 1 ) ) {
            ok = 0;
        }
    }
    if( root == -1 || ( a[root] != root && ok == 0 ) ) {
        puts( "NO" );
        return 0;
    }
    puts( "YES" );
    memset( f, 0, sizeof f );
    if( a[root] != root ) {
        printf( "%d %d\n", a[root], root );
        f[root] = f[a[root]] = 1;
        for( int i = 1; i <= n; ++i ) {
            int k = i;
            while( !f[k] ) {
                printf( "%d %d\n", a[root], k );
                f[k] = 1;
                if( a[k] != k ) {
                    printf( "%d %d\n", root, a[k] );
                    f[a[k]] = 1;
                }
                k = a[a[k]];
            }
        }
    } else {
        f[root] = 1;
        for( int i = 1; i <= n; ++i ) {
            if( f[i] ) continue ;
            printf( "%d %d\n", root, i );
            f[i] = 1;
        }
    }
    return 0;
}
