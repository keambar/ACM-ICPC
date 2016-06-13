#include <bits/stdc++.h>
using namespace std;

int fa[20000], n;

int main( int argc , char **argv )
{
    srand( time( NULL ) );
    freopen( "b.out", "w", stdout );
    int t;
    sscanf( argv[1], "%d", &t );
    if( t == 1 ) {
        printf( "3\n-1 -2 -3\n1 2\n2 3\n" );

    } else if( t == 2 ) {
        printf( "5\n-1 1 3 1 -1\n4 1\n1 3\n1 2\n4 5\n" );

    } else if( t == 28 ) {
        puts( "16000" );
        for( int i = 1; i <= 16000; ++i ) {
            printf( "%d ", rand() % 1001 );
        }
        putchar( 10 );
        for( int i = 16000; i > 1; --i ) {
            printf( "%d %d\n", i, i - 1 );
        }

    } else if( t == 29 ) {
        puts( "16000" );
        for( int i = 1; i <= 16000; ++i ) {
            printf( "%d ", ( rand() % 2001 ) - 1000 );
        }
        putchar( 10 );
        for( int i = 16000; i > 1; --i ) {
            printf( "%d %d\n", 1, i );
        }
    } else if( t == 30 ) {
        puts( "16000" );
        for( int i = 1; i <= 16000; ++i ) {
            printf( "%d ", ( rand() % 2001 ) - 1000 );
        }
        putchar( 10 );
        for( int i = 16000; i > 1; --i ) {
            printf( "%d %d\n", i, i - 1 );
        }
    } else {
        if( t <= 10 ) n = rand() % 40 + 10;
        else if( t <= 20 ) n = rand() % 3000 + 1000;
        else if( t <= 30 ) n = rand() % 5000 + 3000;
        printf( "%d\n", n );
        for( int i = 1; i <= n; ++i ) {
            printf( "%d ", ( rand() % 2001 ) - 1000 );
        }
        putchar( 10 );
        for( int i = 2; i <= n; ++i ) {
            fa[i] = rand() % ( i - 1 ) + 1;
        }
        for( int i = 2; i <= n; ++i ) {
            printf( "%d %d\n", i, fa[i] );
        }
    }
}
