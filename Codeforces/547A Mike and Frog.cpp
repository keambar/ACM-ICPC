#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
typedef long long LL;

int n , a , b , c , d;
int s0 , t0 , a0 , b0;
int s1 , t1 , a1 , b1;

int main()
{
    cin >> n;
    cin >> s0 >> t0 >> a0 >> b0;
    cin >> s1 >> t1 >> a1 >> b1;

    int x;
    x = s0 , a = b = -1;
    for ( int i = 0 ; i < N + N && !~b ; ++ i ) {
        if ( x == t0 ) {
            if ( !~a )
                a = i;
            else
                b = i;
        }
        x = ( ( LL ) x * a0 + b0 ) % n;
    }
    x = s1 , c = d = -1;
    for ( int i = 0 ; i < N + N && !~d ; ++ i ) {
        if ( x == t1 ) {
            if ( !~c )
                c = i;
            else
                d = i;
        }
        x = ( ( LL ) x * a1 + b1 ) % n;
    }

    if( !~a || !~c ) {
        cout << -1;
    } else if( !~b && !~d ) {
        cout << ( a == b ? a : -1 );
    } else if( !~b ) {
        cout << ( a == c || ( ( a > c ) && ( a - c ) % ( d - c ) == 0 ) ? a : -1 );
    } else if( !~d ) {
        cout << ( c == a || ( ( c > a ) && ( c - a ) % ( b - a ) == 0 ) ? c : -1 );
    } else {
        b -= a;
        d -= c;
        for( int i = 0; i < N; ++i ) {
            LL t = ( LL )i * b + a;
            if( t >= c && ( t - c ) % d == 0 ) {
                cout << t;
                return 0;
            }
        }
        cout << -1;
    }
}
