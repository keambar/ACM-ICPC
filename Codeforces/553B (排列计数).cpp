#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n, k;
LL dp[50][30];
LL fs[50];

int main()
{
    for( int i = 0; i <= 50; i++ ) {
        dp[i][0] = 1;
        for( int j = 1; j <= i / 2; ++j ) {
            dp[i][j] = dp[i - 1][j] + dp[i - 2][j - 1];
        }
    }
    for( int i = 1; i <= 50; ++i ) fs[i] = 1;
    for( int i = 1; i <= 50; ++i ) {
        for( int j = 1; j <= i / 2; ++j )
            fs[i] =  fs[i] + dp[i][j] ;
    }

    cin >> n >> k;
    vector<int> p;
    for( int i = 1; i <= n; ++i ) p.push_back( i );
    for( int i = 1; i <= n; i++ ) {
        long long j;
        for( j = 1; j < p.size(); ++j ) {
            if( j * ( fs[n - i] ) >= k ) {
                break;
            }
        }
        --j;
        k -= j * fs[n - i];
        cout << p[j] << " ";
        p.erase( p.begin() + j );
    }
}
