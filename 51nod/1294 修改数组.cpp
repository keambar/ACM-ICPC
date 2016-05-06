/*
	对每个数减去它的下标，就是求LIS了。
*/
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
const int N = 100005;
const int Mod = ( int ) 1e9 + 7;
int a[N], n;
int main()
{
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i ) {
        scanf ( "%d", &a[i] );
        a[i] -= i;
    }
    vector<int> tmp;
    for ( int i = 1; i <= n; ++i ) {
        if ( a[i] < 0 ) continue;
        auto it = upper_bound ( all ( tmp ), a[i] );
        if ( it == tmp.end() ) tmp.pb ( a[i] );
        else if ( a[i] < *it ) *it = a[i];
    }
    printf ( "%d", n - SZ ( tmp ) );
}
