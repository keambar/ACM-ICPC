#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define LL long long
#define sz( a ) (int)a.size()
#define all( a ) a.begin(), a.end()
#define second sd
#define first ft
const int N = 100004;
const int Mod = ( int ) 1e9 + 7;

int a[N], n;

vector<int> s[N];

int f[N], t[N], pd[N];


int main()
{
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d", a + i );
    }
    vector<int> ast;
    vector<int> ::iterator it;
    for( int i = 1; i <= n; ++i ) {
        it = lower_bound( all( ast ), a[i] );
        t[i] = it - ast.begin() + 1;
        if( it == ast.end() ) ast.pb( a[i] );
        else *it = min( *it, a[i] );
    }
    ast.clear();
    for( int i = n; i > 0; --i ) {
        it = lower_bound( all( ast ), -a[i] );
        f[i] = it - ast.begin() + 1;
        if( it == ast.end() ) ast.pb( -a[i] );
        else *it = min( *it, -a[i] );
    }
    int len = ast.size();
    for( int i = 1; i <= n; ++i ) {
        if( t[i] + f[i] - 1 == len ) {
            s[t[i]].pb( i );
            ++pd[i];
        }
    }
    for( int i = 1; i <= len; ++i ) {
        if( sz( s[i] ) == 1 ) {
            ++pd[s[i][0]];
        }
    }
    for( int i = 1; i <= n; ++i ) {
        printf( "%d", pd[i]+1);
    }
    putchar( 10 );
}
