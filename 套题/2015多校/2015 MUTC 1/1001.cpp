#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

#define sz(a) (int)(a).size()
#define ll long long
using namespace std;


const int INF = 200009;
const int mod = ( int ) 1e9 + 7;
vector<int> pos[10009], a[10009];
int n;
ll ans = 0;
void init()
{
    for ( int i = 1; i <= 10000; ++i ) pos[i].clear();
    ans = 0;
}

void make ( int x )
{
    set<int> p;
    set<int>::iterator it;
    for ( int i = 0; i < sz ( a[x] ); ++i ) {
        for ( int j = 0; j < sz ( pos[a[x][i]] ); ++j )
            p.insert ( pos[a[x][i]][j] );
    }
    for ( int i = 0; i < sz ( pos[x] ); ++i ) {
        it = p.find ( pos[x][i] );
        int a, b;
        if ( it == p.begin() ) a = 1;
        else {
            --it;
            a = ( *it ) + 1;
            ++it;
        }
        if ( ( ++it ) == p.end() ) b = n;
        else {
            b = ( *it ) - 1;
        }
        ans = ( ans + ( pos[x][i] - a + 1 ) * ( b - pos[x][i] + 1 ) ) % mod;
    }
}
int main()
{
    for ( int i = 1; i <= 10000; ++i ) {
        for ( int j = i; j <= 10000; j += i ) {
            a[j].push_back ( i );
        }
    }
    while ( scanf ( "%d", &n ) != EOF ) {
        init();
        for ( int i = 1, k; i <= n; ++i ) {
            scanf ( "%d", &k );
            pos[k].push_back ( i );
        }
        for ( int i = 1; i <= 10000; ++i ) {
            if ( sz ( pos[i] ) ) {
                make ( i );
            }
        }
        cout << ans << endl;
    }
    return 0;
}
