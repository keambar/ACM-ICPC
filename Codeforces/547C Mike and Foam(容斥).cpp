#include<bits/stdc++.h>
#define LL long long

using namespace std;

const LL N = 500010;
LL n, q, a[N], dp[N], cnt[N], m = 500000;
bool vis[N];
vector<LL> d[N];

int main()
{
    ios::sync_with_stdio(0);
    LL i, j, k;
    dp[1] = 1;
    for ( j = 1; j <= m; ++j ) {
        d[j].push_back( j );
        for ( i = j + j; i <= m; i += j )
            d[i].push_back( j ), dp[i] -= dp[j];
    }
    cin>>n>>q;
    for ( i = 1; i <= n; ++i ) cin>>a[i];
    LL ans = 0;
    while ( q-- ) {
        cin>>i;
        if ( !vis[i] )
            for ( LL y : d[a[i]] ) ans += dp[y] * ( cnt[y]++ );
        else
            for ( LL y : d[a[i]] ) ans -= dp[y] * ( --cnt[y] );
        vis[i] ^= 1;
        cout<<ans<<"\n";
    }

    return 0;
}
