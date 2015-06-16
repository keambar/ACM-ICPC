#include <bits/stdc++.h>
using namespace std;

const int N = 123456;
int a[N];
int n, m, t;
long long s;

inline bool check( long long x )
{
    int k = m;
    long long s = 0;
    for( int i = 1; i <= t; ++i ) {
        s += a[i];
        while( s + i >= x ) {
            s -= x - i;
            if( --k < 0 ) return 0;
        }
    }
    if(k==0) return s<=0;
    return 1;
}

int main()
{
    ios::sync_with_stdio( 0 );
    cin >> n >> m;
    for( int i = 1; i <= n; ++i ) {
        cin >> a[i];
        s += a[i];
        if( a[i] != 0 ) t = i;
    }
    long long  l = t + 1, r = s + t,ans=-1;
    while( l <= r ) {
        long long mid = ( l + r ) >> 1;
        if( check( mid ) ) r = mid - 1,ans=mid;
        else l = mid + 1;
    }
    cout << r + 1 << endl;

}
