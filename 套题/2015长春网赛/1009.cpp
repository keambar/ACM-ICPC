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

int n, m, p;
int Ap[202], Aw[202], As[202];
int FA[51005];
int Bw[202], Bp[202], Bs[202];
int FB[51005];
const int MAX_V = 51005;
inline void pack( int f[], int V, int v, int n, int w )
{
    if( n == 0 || v == 0 ) return;
    if( n == 1 ) {
        for( int i = V; i >= v; --i )
            if( f[i] < f[i - v] + w ) f[i] = f[i - v] + w;
        return;
    }
    if( n * v >= V - v + 1 ) {
        for( int i = v; i <= V; ++i )
            if( f[i] < f[i - v] + w ) f[i] = f[i - v] + w;
        return;
    }

    int va[MAX_V], vb[MAX_V];
    for( int j = 0; j < v; ++j ) {
        int *pb = va, *pe = va - 1;
        int *qb = vb, *qe = vb - 1;
        for( int k = j, i = 0; k <= V; k += v, ++i ) {
            if( pe  == pb + n ) {
                if( *pb == *qb ) ++qb;
                ++pb;
            }
            int tt = f[k] - i * w;
            *++pe = tt;
            while( qe >= qb && *qe < tt ) --qe;
            *++qe = tt;
            f[k] = *qb + i * w;
        }
    }
}
//“多重背包”通用模板
//v、n、w：当前所处理的这类物品的体积、个数、价值
//V：背包体积， MAX_V：背包的体积上限值
//f[i]：体积为i的背包装前几种物品，能达到的价值上限。
inline void pack2( int f[], int V, int v, int n, int w )
{
    if( n == 0 || v == 0 ) return;
    if( n == 1 ) {              //01背包
        for( int i = V; i >= v; --i )
            if( f[i] > f[i - v] + w ) f[i] = f[i - v] + w;
        return;
    }
    if( n * v >= V - v + 1 ) {  //完全背包(n >= V / v)
        for( int i = v; i <= V; ++i )
            if( f[i] > f[i - v] + w ) f[i] = f[i - v] + w;
        return;
    }

    int va[MAX_V], vb[MAX_V];   //va/vb: 主/辅助队列
    for( int j = 0; j < v; ++j ) {    //多重背包
        int *pb = va, *pe = va - 1;     //pb/pe分别指向队列首/末元素
        int *qb = vb, *qe = vb - 1;     //qb/qe分别指向辅助队列首/末元素
        for( int k = j, i = 0; k <= V; k += v, ++i ) {
            if( pe  == pb + n ) {      //若队列大小达到指定值，第一个元素X出队。
                if( *pb == *qb ) ++qb;  //若辅助队列第一个元素等于X，该元素也出队。
                ++pb;
            }
            int tt = f[k] - i * w;
            *++pe = tt;                  //元素X进队
            //删除辅助队列所有小于X的元素，qb到qe单调递减，也可以用二分法
            while( qe >= qb && *qe > tt ) --qe;
            *++qe = tt;              //元素X也存放入辅助队列
            f[k] = *qb + i * w;      //辅助队列首元素恒为指定队列所有元素的最大值
        }
    }
}
int main()
{
    int T;
    scanf( "%d", &T );
    while( T-- ) {
        memset( FA, 0x3f, sizeof FA );
        memset( FB, 0, sizeof FB );
        scanf( "%d %d %d", &n, &m, &p );
        int sva = 0, svb = 0;
        FA[0] = 0;
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d %d %d", &Aw[i], &Ap[i], &As[i] );
            pack2( FA, 51000, Aw[i], As[i], Ap[i] );
        }
        for( int i = 51000; i >= p; --i ) {
            FA[i] = min( FA[i], FA[i + 1] );
        }
        for( int i = 1; i <= m; ++i ) {
            scanf( "%d %d %d", &Bp[i], &Bw[i], &Bs[i] );
            svb += Bw[i] * Bs[i];
            pack( FB, 51000, Bw[i], Bs[i], Bp[i] );
        }
        int p1 = FA[p], p2;
        int flag = 0;
        for( p2 = 1; p2 <= svb; ++p2 ) {
            if( FB[p2] >= p1 ) {
                flag = 1;
                break;
            }
        }
        if( flag ) {
            printf( "%d\n", p2 );
        } else {
            puts( "TAT" );
        }
    }
}