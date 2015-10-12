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

int n, m, k, t, a[2111], b[2111], pos[2111];
vector<int> x;
vector<int> y;

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i++ )cin >> a[i];
    for( int i = 1; i <= n; i++ )cin >> b[i], pos[b[i]] = i;
    int ans = 0;
    for( int i = 1; i <= n; i++ ) {
        k = i;
        while( 1 ) {
            if( pos[a[k]] == i )break;
            k++;
        }
        while( k != i ) {
            for( int j = i; j <= k; j++ )
                if( pos[a[j]] >= k ) {
                    x.push_back( k );
                    y.push_back( j );
                    ans += k - j;
                    swap( a[j], a[k] );
                    k = j;
                }
        }
    }
    cout << ans << endl << x.size() << endl;
    for( int i = 0; i < x.size(); i++ )printf( "%d %d\n", x[i], y[i] );
}
