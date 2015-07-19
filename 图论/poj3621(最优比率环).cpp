#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;

const int N = 5009;
const double Eps = 1e-3;
int n, m;
int u[N], v[N], w[N], val[N];
double rat[N];
double dis[N];

bool BF ( double k )
{
    int flag ;
    for ( int i = 1; i <= m; ++i )  rat[i] = k * w[i] - val[v[i]];
    for ( int i = 1; i <= n; ++i ) dis[i] = 0;
    for ( int i = 1; i <= n; ++i ) {
        flag = 0;
        for ( int j = 1; j <= m; ++j ) {
            if ( dis[u[j]] + rat[j] < dis[v[j]] ) {
                dis[v[j]] = dis[u[j]] + rat[j];
                flag = 1;
            }
        }
        if ( !flag ) return 0;
    }
    return 1;
}

int main()
{
    scanf ( "%d %d", &n, &m );
    for ( int i = 1; i <= n; ++i ) {
        scanf ( "%d", &val[i] );
    }
    for ( int i = 1; i <= m; ++i ) {
        scanf ( "%d %d %d", &u[i], &v[i], &w[i] );
    }
    double l = 0., r = 20000;
    while ( fabs ( r - l ) > Eps ) {
        double mid = ( r + l ) / 2;
        if ( BF ( mid ) ) l = mid;
        else r = mid;
    }
    printf ( "%.2f\n", l );
}
