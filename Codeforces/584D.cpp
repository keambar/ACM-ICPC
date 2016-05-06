#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;

inline bool ok( int x )
{
    for( int i = 2; i * i <= x; ++i ) {
        if( x % i == 0 ) return 0;
    }
    return 1;
};

int main()
{
    int n;
    cin >> n;
    if( ok( n ) ) {
        cout << "1\n" << n << endl;
        return 0;
    }
    if( ok( n - 2 ) ) {
        cout << "2\n" << "2 " << ( n - 2 ) << endl;
        return 0;
    }
    cout << "3\n3 ";
    n -= 3;
    for( int i = 3; i < n; i+=2 ) {
        if( ok( i ) && ok( n - i ) ) {
            cout << i << " " << ( n - i ) << endl;
            return 0;
        }
    }
}
