#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef pair<int, int> ii;
map<ii, long long> s;
set<int> a;
int n, k;
long long ans;
int main()
{
    cin >> n >> k;
    for ( int i = 1, x; i <= n; ++i ) {
        cin >> x;
        a.insert ( x );
        if ( x % k == 0 ) {
            s[make_pair ( x, 3 )] += s[make_pair ( x / k, 2 )];
            s[make_pair ( x, 2 )] += s[make_pair ( x / k, 1 )];
        }
        ++s[make_pair ( x, 1 )];
    }
    for ( auto &i : a ) {
        ans += s[make_pair ( i, 3 )];
    }
    cout << ans << endl;
}