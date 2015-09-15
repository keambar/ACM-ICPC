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

const double eps = 1e-8;
const double pi = acos( -1.0 );
int sgn( double x )
{
    return fabs( x ) < eps ? 0 : x < 0 ? -1 : 1;
}
struct point {
    double x, y;
    point() {}
    point( double x, double y )
    {
        this->x = x;
        this->y = y;
    }
    point operator +( point a )
    {
        return point( x + a.x, y + a.y );
    }
    point operator -( point a )
    {
        return point( x - a.x, y - a.y );
    }
    double operator *( point a )
    {
        return x * a.x + y * a.y;
    }
    double operator /( point a )
    {
        return x * a.y - y * a.x;
    }
    bool operator <( point a )const
    {
        return x != a.x ? x < a.x : y < a.y;
    }
} p[200], q[200];
int covexhull( point p[], int n, point ch[] )
{
    sort( p, p + n );
    int m = 0;
    for( int i = 0; i < n; i++ ) {
        while( m > 1 && sgn( ( ch[m - 1] - ch[m - 2] ) / ( p[i] - ch[m - 2] ) ) <= 0 )
            m--;
        ch[m++] = p[i];
    }
    int k = m;
    for( int i = n - 2; i > -1; i-- ) {
        while( m > k && sgn( ( ch[m - 1] - ch[m - 2] ) / ( p[i] - ch[m - 2] ) ) <= 0 )
            m--;
        ch[m++] = p[i];
    }
    if( n > 1 )
        m--;
    return m;
}

double dis( point a, point b )
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
int n;
int main()
{
    while( scanf( "%d", &n ) != EOF && n ) {
        for( int i = 0, x, y; i < n; ++i ) {
            scanf( "%d %d", &x, &y );
            p[i] = point( x, y );
        }
        if( n == 1 ) {
            printf( "0.00\n" ) ;
            continue ;
        }
        if( n == 2 ) {
            printf( "%.2f\n" , dis( p[0] , p[1] ) ) ;
            continue ;
        }
        int m = covexhull( p, n, q );
        double ans = 0;
        for( int i = 1; i < m; ++i ) {
            ans += dis( q[i], q[i - 1] );
        }
        ans += dis( q[0], q[m - 1] );
        printf( "%.2f\n", ans );
    }
}
