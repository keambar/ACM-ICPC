#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

const int prime[19] = { -2, -3, -5, -7, -11, -13, -17, -19, -23, -29, -31, -37, -41, -43, -47, -53, -59, -61, -67};
ll n;
int r;
vector <int> iout;

void get_iout()
{
    iout.clear();
    for ( int i = 0; abs ( prime[i] ) <= r; i++ ) {
        int k = iout.size();
        for ( int j = 0; j < k; j++ ) {
            if ( abs ( prime[i]*iout[j] ) <= 63 )
                iout.push_back ( prime[i]*iout[j] );
        }
        iout.push_back ( prime[i] );
    }
}

ll cal ( ll x )
{
    if ( x == 1 )     return 0;
    ll ans = x;
    for ( int i = 0; i < iout.size(); i++ ) {
        ll temp = ( ll ) ( pow ( x + 0.5, 1.0 / abs ( iout[i] ) ) ) - 1;
        if ( iout[i] < 0 )
            ans -= temp;
        else
            ans += temp;
    }
    return ans - 1;
}

int main()
{
    int T;
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%I64d%d", &n, &r );
        get_iout();
        ll ans = n;
        while ( 1 ) {
            ll temp = cal ( ans );
            if ( temp == n ) {
                break;
            }
            ans += n - temp;
        }
        printf ( "%I64d\n", ans );
    }
    return 0;
}
