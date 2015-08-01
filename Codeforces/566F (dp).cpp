#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, ans;
int f[N];
int main()
{
    scanf ( "%d", &n );
    for ( int i = 1, k; i <= n; ++i ) {
        scanf ( "%d", &k );
        for ( int j = k + k; j <= 1000000; j += k ) {
            f[j] = max ( f[j], f[k] + 1 );
        }
        ans = max ( ans, f[k] );
    }
    printf ( "%d\n", ans+1 );
}
