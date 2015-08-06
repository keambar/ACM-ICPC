#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef pair<int , int > ii;
const int N = 100005;

int T, n, m , flag;
int l[N], r[N];
vector<ii> a[N];
vector<int> ans, tem;
set<ii> s;
set<ii>::iterator it;
int main()
{
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d", &n );
        for ( int i = 0; i < N; ++i ) a[i].clear();
        s.clear(), ans.clear(), tem.clear();
        int tol = 0;
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &l[i] );
        }
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &r[i] );
        }

        for ( int i = 1; i <= n; ++i ) {
            a[l[i]].push_back ( mp ( r[i], i ) );
        }

        for ( int i = 0; i <= n; ++i ) {
            if ( tol == i ) s.insert ( a[i].begin(), a[i].end() );
            else {
                for ( int j = 0; j < a[i].size(); ++j )
                    tem.push_back ( a[i][j].se );
                continue;
            }
            while ( !s.empty() && ( *s.begin() ).fi < i ) {
                tem.push_back ( ( *s.begin() ).se );
                s.erase ( s.begin() );
            }
            if ( s.empty() ) continue;
            it = s.begin();
            ans.push_back ( ( *it ).se );
            s.erase ( it );
            ++tol;
        }
        printf ( "%d\n", ans.size() );
        for ( int i = 0; i < tem.size(); ++i ) {
            ans.push_back ( tem[i] );
        }
        for ( int i = 0; i < ans.size(); ++i ) {
            printf ( "%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ' );
        }
    }
    return 0;
}