#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
const int N = 2;
ll n, k, l, m;

struct Mat {
    ll mat[N + 1][N + 1];
} A, B;

Mat operator * ( Mat a, Mat b )
{
    Mat c;
    memset ( c.mat, 0, sizeof c.mat );
    for ( int k = 0; k <  N; k++ )
        for ( int i = 0; i <  N; i++ )
            for ( int j = 0; j <  N; j++ )
                ( c.mat[i][j] += ( a.mat[i][k] * b.mat[k][j] ) % m ) %= m;
    return c;
}

Mat operator ^ ( Mat a, ll pow )
{
    Mat c;
    for ( int i = 0; i <  N; i++ )
        for ( int j = 0; j <  N; j++ )
            c.mat[i][j] = ( i == j );
    while ( pow ) {
        if ( pow & 1 )     c = c * a;
        a = a * a;
        pow >>= 1;
    }
    return c;
}

ll quickp( ll x )
{
    ll s = 1, c = 2;
    while( x ) {
        if( x & 1 ) s = ( s * c ) % m;
        c = ( c * c ) % m;
        x >>= 1;
    }
    return s;
}
int main()
{
    ios::sync_with_stdio( 0 );
    Mat p, a;
    p.mat[0][0] = 0, p.mat[0][1] = 1;
    p.mat[1][0] = 1, p.mat[1][1] = 1;
    a.mat[0][0] = 1, a.mat[0][1] = 2;
    a.mat[1][0] = 0, a.mat[1][1] = 0;
    cin >> n >> k >> l >> m;

    ll ans = 0;
    if(  l == 64 || ( 1uLL << l ) > k  ) {
        ans++;
        p = p ^ n;
        a = a * p;
        ll t1 = a.mat[0][0], t2 = ( m + quickp( n ) - t1 ) % m;
        for( int i = 0; i < l; ++i ) {
            if( k & ( 1uLL << i ) ) ans = ( ans * t2 ) % m;
            else ans = ( ans * t1 ) % m;
        }
    }

    cout << ans%m << endl;

}
