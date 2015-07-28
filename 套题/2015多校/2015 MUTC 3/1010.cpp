#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int N = 111;
vector<int> E[N];
int s[N], sum[N];
int T, n, m;


int dfs ( int u )
{
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i];
        sum[u] += dfs ( v );
    }
    return sum[u] + 1;
}
void init()
{
    for ( int i = 1; i <= n; ++i ) E[i].clear();
    memset ( s, 0, sizeof s );
    memset ( sum, 0, sizeof sum );
}
int main()
{

    while ( scanf ( "%d %d", &n, &m ) != EOF ) {
        init();
        for ( int i = 1, u, v; i < n; ++i ) {
            scanf ( "%d %d", &u, &v );
            E[u].push_back ( v );
            ++s[v];
        }
        int boss;
        for ( int i = 1; i <= n; ++i ) {
            if ( s[i] == 0 ) boss = i;
        }
        dfs ( boss );
        int ans = 0;
        for ( int i = 1; i <= n; ++i ) {
            if ( sum[i] == m ) ++ans;
        }
        printf ( "%d\n", ans );
    }
    return 0;
}