#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define  LL long long
#define  ULL unsigned long long
#define eps 1e-12
using namespace std;

double n, p, s, v;

double fun ( double c )
{
    return n * pow ( log2 ( n ), c * sqrt ( 2.0 ) ) / ( p * 1e9 ) + ( 1 + 1 / c ) * s / v;

}


int main()
{
    ios_base::sync_with_stdio ( false );
    cin.tie ( 0 );
    while ( ~scanf ( "%lf %lf %lf %lf", &n, &p, &s, &v ) ) {
        double l = 0, r = 1;
        while ( fun ( r ) < fun ( r / 2 ) ) r *= 2;
        int st = 1000;
        double mid;
        double mid2;
        while ( st-- ) {
            mid = ( r + 2 * l ) / 3;
            mid2 = ( 2 * r + l ) / 3;
            double ans1 = fun ( mid );
            double ans2 = fun ( mid2 );
            if ( ans1 >= ans2 ) l = mid;
            else  r = mid2;
        }
        printf ( "%.10f %.10f\n", fun ( l ), l );
    }
    return 0;
}