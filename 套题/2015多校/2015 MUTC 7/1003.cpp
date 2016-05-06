#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#define LL long long
using namespace std;

const int N = 200005;

int Ma[N], Mp[N];
int s[N], n;

void Manacher ( int s[], int len )
{
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for ( int i = 0; i < len; i++ ) {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for ( int i = 0; i < l; i++ ) {
        Mp[i] = mx > i ? min ( Mp[2 * id - i], mx - i ) : 1;
        while ( Ma[i + Mp[i]] == Ma[i - Mp[i]] ) Mp[i]++;
        if ( i + Mp[i] > mx ) {
            mx = i + Mp[i];
            id = i;
        }
    }
    n = l;
}
/*
* abaaba
* i: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
* Ma[i]: $ # a # b # a # a $ b # a #
* Mp[i]: 1 1 2 1 4 1 2 7 2 1 4 1 2 1
*/

struct Comp {
    bool operator () ( const pair<int, int> &a, const pair<int, int> &b )
    {

    }
};
int main()
{
    int T;
    scanf ( "%d", &T );
    for ( int t = 1; t <= T; ++t ) {
        scanf ( "%d", &n );
        for ( int i = 0; i < n; ++i ) {
            scanf ( "%d", &s[i] );
        }
        Manacher ( s, n );
        int ans = 0;
        vector<pair<int, int> > se;
        set<int> p;
        set<int> ::iterator it;
        for ( int i = 1; i < n; i += 2 ) {
            se.push_back ( make_pair ( Mp[i], i ) );
        }
        sort ( se.begin(), se.end() );
        for ( int i = se.size() - 1; i >= 0; --i ) {
            int len = se[i].first, pos = se[i].second;
            it = p.lower_bound ( pos - len + 1 );
            if ( it != p.end() && *it < pos ) {
                ans = max ( ans, ( pos - *it + 1 ) / 2 );
            }
            it = p.upper_bound ( pos + len - 1 ) ;
            if ( it != p.begin() && *--it > pos ) {
                ans = max ( ans, ( *it - pos + 1 ) / 2 );
            }
            p.insert ( pos );
        }
        printf ( "Case #%d: %d\n", t, ans * 3 );
    }
    return 0;
}
