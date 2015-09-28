// BEGIN CUT HERE

// END CUT HERE
#line 5 "LineMSTDiv2.cpp"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int MOD = 1000000007;
LL ans;
void dfs( int x, int n, int sta, LL res )
{
    if( x >= n ) {
        ans = ( ans + res ) % MOD;
        return ;
    }
    dfs( x + 1, n, sta | ( 1 << ( x - 1 ) ), res );
    for( int i = ( x - 2 ); i >= 0; --i ) {
        if( !( sta & ( 1 << i ) ) ) {
            res = ( res * 2 ) % MOD;
        } else {
            break;
        }
    }
    dfs( x + 1, n, sta, res );
}
class LineMSTDiv2
{
public:
    int count( int N )
    {
        if( N == 2 ) {
            ans = 2;
        } else {
            ans = 0;
            dfs( 1, N, 0, 1 );
            LL tmp = 1;
            for( int i = 1; i <= N; ++i ) {
                tmp *= i;
            }
            tmp /= 2;
            tmp %= MOD;
            ans = ( ans * tmp ) % MOD;
        }
        return ans;
    }
};
