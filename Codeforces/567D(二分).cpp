#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, k, a, m;
set<int> s;
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> a;
    int now = 1 + ( n - a ) / ( a + 1 );
    cin >> m;
    s.insert ( 0 ), s.insert ( n + 1 );
    for ( int i = 1, x; i <= m; ++i ) {
        cin >> x;
        auto it = s.lower_bound ( x );
        int r = * ( it ) - 1;
        int l = * ( --it ) + 1;
        int len = ( r - l + 1 );
        int tem = 0, da = 0, db = 0;
        if ( len >= a ) {
            tem = ( 1 + ( len - a ) / ( a + 1 ) );
        }
        if ( x - l >= a ) {
            da = ( 1 + ( x - l - a ) / ( a + 1 ) );
        }
        if ( r - x >= a ) {
            db = ( 1 + ( r - x - a ) / ( a + 1 ) );
        }
        now -= tem - da - db;
        if ( now < k ) {
            cout << i << endl;
            return 0;
        }
        s.insert(x);
    }
    cout << -1 << endl;
}