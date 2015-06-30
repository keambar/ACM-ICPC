#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

vector<int> E[N], out;
set<pair<double, int>> s;
int deg[N], vis[N], dg[N];
int n, m, k;

int main()
{
    ios::sync_with_stdio ( 0 );
    cin >> n >> m >> k;

    for ( int i = 1, x; i <= k; ++i ) {
        cin >> x;
        vis[x] = 1;
    }

    for ( int i = 1, u, v; i <= m; ++i ) {
        cin >> u >> v;
        E[u].push_back ( v ), ++deg[u];
        if ( !vis[v] ) ++dg[u];
        E[v].push_back ( u ), ++deg[v];
        if ( !vis[u] ) ++dg[v];
    }

    for ( int i = 1; i <= n; ++i ) {
        if (!vis[i])
            s.insert ( make_pair ( 1.*dg[i] / deg[i], i ) );
    }

    double ans = -1;
    while (!s.empty() ) {
        auto it = *s.begin();
        if (it.first > ans) {
            ans=it.first;
            out.clear();
            for (auto &i : s) {
                out.push_back (i.second);
            }
        }
        s.erase (s.begin() );
        vis[it.second] = 1;
        for (auto &i : E[it.second]) {
            if (!vis[i]) {
                s.erase (make_pair (1.*dg[i] / deg[i], i) );
                --dg[i];
                s.insert (make_pair (1.*dg[i] / deg[i], i) );
            }
        }
    }

    cout << out.size() << endl;
    for (auto &i : out) {
        cout << i << " ";
    }
}
