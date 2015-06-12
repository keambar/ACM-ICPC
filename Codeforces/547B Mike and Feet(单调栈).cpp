#include <bits/stdc++.h>

using namespace std;

const int N = 200009;

int a[N], l[N], r[N], ans[N];
typedef pair<int, int> ii;
stack<ii> s, t;

int n;

int main()
{
    ios::sync_with_stdio( 0 );
    cin >> n;
    for( int i = 1; i <= n; ++i ) {
        cin >> a[i];
    }

    s.push( make_pair( 0, 0 ) );
    for( int i = 1; i <= n; ++i ) {
        while( a[i] <= s.top().first ) s.pop();
        l[i] = s.top().second + 1;
        s.push( make_pair( a[i], i ) );
    }

    while( !s.empty() ) s.pop();
    s.push( make_pair( 0, n + 1 ) );
    for( int i = n; i > 0; --i ) {
        while( a[i] <= s.top().first ) s.pop();
        r[i] = s.top().second - 1;
        s.push( make_pair( a[i], i ) );
    }

    for( int i = 1; i <= n; ++i ) {
        int k = r[i] - l[i] + 1;
        ans[k] = max( ans[k], a[i] );
    }
    for( int i = n; i > 0; --i ) {
        ans[i] = max( ans[i], ans[i + 1] );
    }

    for( int i = 1; i <= n; ++i ) {
        cout << ans[i] << ' ';
    }
}
