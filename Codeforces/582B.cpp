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
LL a[N], b[N], f[N];

int main()
{
    LL n, T;
    cin >> n >> T;
    for( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    for( int i = 0; i < n * 105; ++i ) {
        f[i] = 1;
        for( int j = max( i - ( int )n, 0 ); j < i; ++j ) {
            if( a[i % n] >= a[j % n] ) {
                f[i] = max( f[i], f[j] + 1 );
            }
        }
    }
    LL ans = 0;
    for( int i = 0; i < n; ++i ) {
        b[i] = f[i + 104 * n] - f[i + n * 103];
    }
    if( T <= 105 ) {
        for( int i = 0; i < T * n; ++i ) {
            ans = max( ans, f[i] );
        }
    } else {
        T -= 105;
        for( int i = 0; i < n; ++i ) {
            ans = max( ans, f[104 * n + i] + b[i] * T );
        }
    }
    cout << ans << endl;
}