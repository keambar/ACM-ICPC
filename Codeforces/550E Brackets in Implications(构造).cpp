#include <bits/stdc++.h>

using namespace std;

int a[213456], n, x = 0;
main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for( int i = 1; i <= n ;++i) {
        cin >> a[i];
        x += !a[i];
    }
    if( !a[n] && ( a[n - 1] || x != 2 ) ) {
        cout << "YES\n";
        for( int i = 1; i <= n - 2 ;++i) cout << "(" << a[i] << "->";
        cout << a[n - 1];
        for( int i = 1; i <= n - 2 ;++i) cout << ")";
        if( n - 1 ) cout << "->0";
    } else cout << "NO";
}
