#include <bits/stdc++.h>
#define lson x << 1
#define rson x << 1 | 1
#define LL long long
#define se second
#define fi first
using namespace std;

const int N = 500005;
LL T, n, m, z, l, ans;
int main()
{
    cin >> T;
    while ( T-- ) {
        cin >> n >> m >> z >> l;
        int a = 0;
        LL ans = 0;
        for ( int i = 1; i < n; ++i ) {
            a = ( a * m + z ) % l;
            ans^=a+a;
        }
        cout << ans << endl;
    }
}
