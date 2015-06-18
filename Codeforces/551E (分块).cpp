#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> s[1000];
ll add[1000], a[512346], pos[512346];
ll n, q, bk, N;

bool cmp( int x, int y )
{
    if( a[x] == a[y]  ) return x < y;
    return a[x] < a[y];
}

inline void modify( ll l, ll r, ll x )
{
    int k = pos[l], t = pos[r];

    if( k == t ) {
        for( ll i = l; i <= r; ++i )
            a[i] += x;
        sort( s[k].begin(), s[k].end(), cmp );
        return ;
    }

    for( ll i = k + ( pos[l - 1] == k ); i <= t - ( pos[r + 1] == t ) ; ++i )
        add[i] += x;

    if( pos[l - 1] == k ) {
        for( ll i = l; pos[i] == k; ++i ) {
            a[i] += x;
        }
        sort( s[k].begin(), s[k].end(), cmp );
    }

    if( pos[r + 1] == t ) {
        for( ll i = r; pos[i] == t; --i ) {
            a[i] += x;
        }
        sort( s[t].begin(), s[t].end(), cmp );
    }
}

inline ll query( ll x )
{
    int l = -1, r = -1, i;
    for( i = 1; i <= N; ++i ) {
        a[0] = x - add[i];
        auto it = lower_bound( s[i].begin(), s[i].end(), 0, cmp );
        if( it == s[i].end() ) continue;
        if( a[*it] + add[i] == x ) {
            l = *it;
            break;
        }
    }

    if( l == -1 ) return l;
    for( int  j = N; j >= i; --j ) {
        a[n + 1] = x - add[j];
        auto it = lower_bound( s[j].begin(), s[j].end(), n + 1, cmp );
        if( it == s[j].begin() ) continue;
        it--;
        if( a[*it] + add[j] == x ) {
            r = *it;
            break;
        }
    }
    return r - l;
}

int main()
{
    ios::sync_with_stdio( 0 );
    cin >> n >> q;
    bk = ceil( sqrt( 1.*n ) + 0.005 );
    for( int i = 1; i <= n; ++i ) {
        cin >> a[i];
        pos[i] = ( i - 1 ) / bk + 1;
        s[pos[i]].push_back( i );
    }
    N = ( n - 1 ) / bk + 1;
    for( int i = 1; i <= N; ++i ) {
        sort( s[i].begin(), s[i].end(), cmp );
    }
    ll cmd, l, r, x;
    for( int i = 1; i <= q; ++i ) {
        cin >> cmd;
        if( cmd == 1 ) {
            cin >> l >> r >> x;
            modify( l, r, x );
        } else {
            cin >> x;
            cout << query( x ) << "\n";
        }
    }
}
