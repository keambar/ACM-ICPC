/*
    思路:先离散化,求出以所有位置结尾的最长递增序列的长度.并存下所有长度为i的序列的结尾下标.
    对下标按照数的大小排序.
    对每个长度len的下标,用树状数组维护长度为len-1,且比当前数小的方案数.
    最后统计所有长度最长的方案数的和.
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
#define pb push_back
#define mp make_pair
#define LL long long
#define sz( a ) int( a.size() )
#define all( a ) a.begin(), a.end()
#define second sd
#define first ft
const int N = 50004;
const int Mod = ( int ) 1e9 + 7;

int a[N], n;

vector<int> spr;
vector<int> s[N];

int sum[N], f[N], t[N];
inline void add ( int x , int k )
{
    for ( ; x < N; x += x & -x ) sum[x] = ( sum[x] + k ) % Mod;
}
inline int gets ( int x )
{
    int res = 0;
    for ( ; x > 0; x -= x & -x ) res = ( res + sum[x] ) % Mod;
    return res;
}
inline bool cmp ( int x, int y )
{
    return a[x] < a[y];
}
int main()
{
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i ) {
        scanf ( "%d", a + i );
        spr.push_back ( a[i] );
    }
    sort ( all ( spr ) );
    spr.erase ( unique ( all ( spr ) ), spr.end() );
    for ( int i = 1; i <= n; ++i ) {
        a[i] = lower_bound ( all ( spr ), a[i] ) - spr.begin();
    }
    vector<int> ast;
    vector<int> ::iterator it;
    for ( int i = 1; i <= n; ++i ) {
        it = lower_bound ( all ( ast ), a[i] );
        s[it - ast.begin() + 1].pb ( i );
        t[i] = it - ast.begin() + 1;
        if ( it == ast.end() ) ast.pb ( a[i] );
        else *it = min ( *it, a[i] );
    }
    int len = ast.size();
    for(int i=1;i<=len;++i){
        sort ( all ( s[i] ), cmp );
    }
    for ( int i = 0; i < s[1].size(); ++i ) {
        f[s[1][i]] = 1;
    }
    for ( int i = 2; i <= len; ++i ) {
        it = s[i - 1].begin();
        for ( int j = 0; j < s[i].size(); ++j ) {
            while ( it != s[i - 1].end() && ( a[*it] ) < a[s[i][j]] ) {
                add ( *it , f[*it] );
                ++it;
            }
            f[s[i][j]] = gets ( s[i][j] );
        }
        memset ( sum, 0, sizeof sum );
    }
    int ans = 0;
    for ( int i = 1; i <= n; ++i ) {
        if ( t[i] == len ) {
            ans = ( ans + f[i] ) % Mod;
        }
    }
    printf ( "%d\n", ans );
}
/*
9
12 14 6 16 3 2 15 5 7
*/
