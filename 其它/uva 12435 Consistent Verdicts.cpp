#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int MAXN = 1009;
struct node {
    int x, y;
} p[MAXN];
int n;
vector<int> d;
int main()
{
    int T, cases = 0;
    int n;
    scanf ( "%d", &T );
    while ( T-- ) {
        d.clear();
        scanf ( "%d", &n );
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d %d", &p[i].x, &p[i].y );
        }
        int mk = 0;
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = i + 1; j <= n; ++j ) {
                int tem = ( p[i].x - p[j].x ) * ( p[i].x - p[j].x ) + ( p[i].y - p[j].y ) * ( p[i].y - p[j].y );
                d.push_back ( tem );
            }
        }
        sort ( d.begin(), d.end() );
        int ans = 1 + ( unique (  d.begin(), d.end() ) - d.begin() );
        printf ( "Case %d: %d\n", ++cases, ans );
    }
    return 0;
}
