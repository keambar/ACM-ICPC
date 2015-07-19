#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 1009;
const double Eps = 1e-4;
int n, k;
double x[N], y[N], h[N];
double dis[N][N], dh[N][N];
double prim ( double k )
{
    int vis[N] = {0, 1},pos[N]={0}, s = 1, u = 1, v;
    double c[N];
    double cost = 0., len = 0.;
    while ( s < n ) {
        double tem = 0x7fffffff;
        for ( int i = 1; i <= n; ++i ) {
            if ( !vis[i] ) {
                double bit = dh[u][i] - k * dis[u][i];
                if ( u == 1 || bit < c[i] ) {
                    c[i] = bit;
                    pos[i]=u;
                }
                if ( tem > c[i] ) {
                    tem = c[i];
                    v = i;
                }
            }
        }
        cost += dh[pos[v]][v], len += dis[pos[v]][v];
        vis[v] = 1;
        u = v;
        ++s;
    }
    return cost / len;
}

int main()
{
    while ( scanf ( "%d", &n ) != EOF ) {
        if ( n == 0 ) break;
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%lf %lf %lf", &x[i], &y[i], &h[i] );
        }
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = i + 1; j <= n; ++j ) {
                dis[i][j] = dis[j][i] = sqrt ( ( x[i] - x[j] ) * ( x[i] - x[j] ) + ( y[i] - y[j] ) * ( y[i] - y[j] ) );
                dh[i][j] = dh[j][i] = fabs ( h[i] - h[j] );
            }
        }
        double ans = 0., k;
        while ( 1 ) {
            k = prim ( ans );
            if ( fabs ( k - ans ) < Eps ) break;
            ans = k;
        }
        printf ( "%0.3f\n", ans );
    }
}
