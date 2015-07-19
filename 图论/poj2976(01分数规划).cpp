#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 1009;
const double Eps = 1e-7;
int n, k;
double a[N], b[N];
double l, r, mid;
int main() {
    while ( scanf ( "%d %d", &n, &k ) != EOF ) {
        if ( n == 0 && k == 0 ) break;
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%lf", &a[i] );
        }
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%lf", &b[i] );
        }
        l = 0., r = 1.;
        double t[N], sum;
        while ( fabs ( r - l ) > Eps ) {
            sum = 0;
            mid = 1.* ( l + r ) / 2;
            for ( int i = 1; i <= n; ++i ) {
                t[i] = 1.*a[i] - mid * b[i];
            }
            sort ( t + 1, t + 1 + n );
            for ( int i = k + 1; i <= n; ++i ) {
                sum += t[i];
            }
            if ( sum > 0 ) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf ( "%.0f\n",  100 * l );
    }
}
