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
const int N = 2000006;
const int Mod = ( int ) 1e9 + 7;


int n;
int pre[N], s[N];
vector<int> a;
int main()
{
    scanf( "%d", &n );
    int ma = 0;
    for( int i = 1, x; i <= n; ++i ) {
        scanf( "%d", &x );
        a.pb( x );
        s[x] = 1;
        ma = max( ma, x );
    }
    for( int i = 1; i <= ma * 2; ++i ) {
        if( s[i - 1] ) {
            pre[i] = i - 1;
        } else {
            pre[i] = pre[i - 1];
        }
    }
    int ans = 0;
    for( auto &i : a ) {
        for( int j = i + i; j <= ma + i; j += i ) {
            ans = max( ans, pre[j] % i );
        }
    }
    printf( "%d\n", ans );
}
