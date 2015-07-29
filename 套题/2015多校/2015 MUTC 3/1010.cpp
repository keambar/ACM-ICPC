/*
	hdu 开栈 需用c++提交
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 500007;
int a[N], s[N];
int n;
vector<int> E[N];

void dfs ( int u )
{
    s[u] = 1;
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i];
        if ( !s[v] ) dfs ( v );
        s[u] += s[v];
    }
}
int main()
{
    while ( scanf ( "%d", &n ) != EOF ) {
        memset ( s, 0, sizeof s );
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &a[i] );
            E[i].clear();
        }
        for ( int i = 1, u, v; i < n; ++i ) {
            scanf ( "%d %d", &u, &v );
            if ( a[v] < a[u] ) E[v].push_back ( u );
            else E[u].push_back ( v );
        }
        int ans = 0;
        for ( int i = 1; i <= n; ++i ) {
            if ( !s[i] )
                dfs ( i );
            ans = max ( ans, s[i] );
        }
        printf ( "%d\n", ans );
    }
    return 0;
}
