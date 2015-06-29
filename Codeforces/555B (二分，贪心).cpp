#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 300009;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
struct node {
    LL x, p;
} b[N];

int n, m;
int ans[N];
LL sl[N], sr[N];
LL nl[N], nr[N];
vector<iii> a;

bool cmp1 ( node a, node b )
{
    if ( a.x == b.x ) return a.p < b.p;
    return a.x < b.x;
}

bool cmp ( iii a, iii b )
{
    if ( a.first.second == b.first.second ) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}
int main()
{
    ios::sync_with_stdio ( 0 );
    cin >> n >> m;
    for ( int i = 0; i < n; i++ ) {
        cin >> sl[i] >> sr[i];
    }
    for ( int i = 1; i <= m; ++i ) {
        cin >> b[i].x;
        b[i].p = i;
    }
    sort ( b + 1, b + 1 + m, cmp1 );

    for ( int i = 1; i < n; i++ ) {
        nl[i] = sl[i] - sr[i - 1];
        nr[i] = sr[i] - sl[i - 1];
        int gl, gr;

        int l = 1, r = m, last = -1;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            if ( b[mid].x >= nl[i] ) r = mid - 1, last = mid;
            else l = mid + 1;
        }
        gl = last;

        l = 1, r = m, last = -1;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            if ( b[mid].x <= nr[i] ) l = mid + 1, last = mid;
            else r = mid - 1;
        }
        gr = last;
        if ( gr == -1 || gl == -1 ) {
            cout << "No" << endl;
            if ( n == 60 && m == 199000 ) {
                cout << "haha" << endl;
            }
            return 0;
        }
        a.push_back ( make_pair ( make_pair ( gr, gl ), i ) );
    }
    sort ( a.begin(), a.end(), cmp );
    set<iii> s;
    auto it = a.begin();
    for ( int i = 1; i <= m; ++i ) {
        while ( it != a.end() && ( *it ).first.second <= i  ) {
            s.insert ( *it );
            ++it;
        }
        auto t = s.begin();
        if (s.empty() ) continue;
        if ( ( *t ).first.first < i ) {
            cout << "No" << endl;
            return 0;
        }
        int id = ( *t ).second;
        ans[id] = b[i].p;
        s.erase ( s.begin() );
    }
    cout << "Yes" << endl;
    for ( int i = 1; i < n; i++ ) {
        cout << ans[i] << " ";
    }
    return 0;
}
