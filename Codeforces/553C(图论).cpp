#include <bits/stdc++.h>

using namespace std;
const int N = 100009;
typedef pair<int, int> ii;
int  vis[N], n, m , flag , s;
vector<ii> E[N];

void dfs (int x, int k)
{
    vis[x] = k;
    --s;
    for (auto &i : E[x]) {
        if (!~vis[i.first]) {
            dfs (i.first, k ^ i.second);
        } else {
            if ( (vis[x]^vis[i.first]) != i.second) {
                flag = 1;
                return ;
            }
        }
        if (flag) return;
    }
}

int main()
{
    memset (vis, -1, sizeof vis);
    ios::sync_with_stdio ( 0 );
    cin >> n >> m;
    s = n;
    for ( int i = 1, u, v, c; i <= m; ++i ) {
        cin >> u >> v >> c;
        E[u].push_back (make_pair (v, c ^ 1) );
        E[v].push_back (make_pair (u, c ^ 1) );
    }
    for (int i = 1; i <= n; ++i) {
        if (!~vis[i] && !E[i].empty() ) {
            ++s;
            dfs (i, 1);
        }
        if (flag) {
            cout << 0 << endl;
            return 0;
        }
    }
    long long  ans = 1, p = 2;
    --s;
    while ( s > 0 ) {
        if ( s & 1 ) ans = ans * p % 1000000007;
        p = ( p * p ) % 1000000007;
        s >>= 1;
    }
    cout << ans << endl;
}
