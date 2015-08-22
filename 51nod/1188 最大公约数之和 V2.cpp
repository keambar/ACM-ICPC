/*
	线性筛出每个数的欧拉函数值
	利用欧拉函数计算GCD，求出前缀和
*/
#include<stdio.h>
#include<string.h>
#define MAXN 5000010
const int N = 5000000;
typedef long long LL;

inline void rd( int &xx )
{
    char ch = getchar();
    while( ch < '0' || ch > '9' ) ch = getchar();
    for( xx = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        xx = xx * 10 + ( ch - '0' );
}
char o[35];
inline void putnum( LL x )
{
    if( x == 0 ) {
        puts( "0" );
        return;
    }
    int i;
    for( i = 0; x != 0; i++, x /= 10 ) o[i] = x % 10 + '0' ;
    for( i--; i >= 0; i-- ) putchar( o[i] );
    putchar( 10 );
}
bool com[MAXN];
int primes, prime[MAXN], phi[MAXN];
LL a[MAXN];
int main()
{

    phi[1] = 1;
    for( int i = 2; i <= N; ++i ) {
        if( !com[i] ) {
            prime[primes++] = i;
            phi[i] = i - 1;
        }
        for( int j = 0; j < primes && i * prime[j] <= N; ++j ) {
            com[i * prime[j]] = true;
            if( i % prime[j] )
                phi[i * prime[j]] = phi[i] * ( prime[j] - 1 );
            else {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
        for( int j = 1; j * i <= N; j ++ )
            a[j * i] += j * phi[i];
    }
    for( int i = 1; i <= N; i ++ ) a[i] += a[i - 1];
    int n, T;
    rd( T );
    while( T-- ) {
        rd( n );
        putnum( a[n] );
    }
    return 0;
}
