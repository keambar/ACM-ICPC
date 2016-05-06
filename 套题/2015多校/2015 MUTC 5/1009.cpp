#include <bits/stdc++.h>
#define lson x << 1
#define rson x << 1 | 1
#define LL long long
#define se second
#define fi first
#define LL long long
using namespace std;

const int N = 1003;

string  fib[N], m, ans;

inline string add ( string a, string b )
{
    if ( a.size() < b.size() ) swap ( a, b );
    int la = a.size(), lb = b.size(), x = 0, i = 0;
    for ( i = 0; i < lb; ++i ) {
        x += ( a[i] - '0' + b[i] - '0' );
        a[i] = '0' + x % 10;
        x /= 10;
    }
    while ( x && i < la ) {
        x += ( a[i] - '0' );
        a[i] = '0' + x % 10;
        x /= 10;
        ++i;
    }
    if ( x ) a += '0' + x;
    return a;
}

inline string sub ( string a, string b )
{
    int la = a.size(), lb = b.size(), x = 0, i = 0;
    for ( i = 0; i < lb; ++i ) {
        if ( a[i] - x >= b[i] ) {
            a[i] = a[i] - x - b[i] + '0';
            x = 0;
        } else {
            a[i] = 10 + '0' + a[i] - b[i] - x;
            x = 1;
        }
    }
    while ( x && i < la ) {
        if ( a[i] != '0' ) {
            a[i] = a[i] - 1;
            x = 0;
        } else {
            a[i] = '9';
            ++i;
        }
    }
    i = la - 1;
    while ( a[i] == '0' && i != 0 ) {
        a.erase ( a.begin() + i );
        --i;
    }
    return a;
}

int T, n;

inline bool pd ( string a, string b )
{
    if ( a.size() == b.size() )  {
        for ( int i = a.size() - 1; i >= 0; --i ) {
            if ( a[i] != b[i] ) return a[i] > b[i];
        }
        return 0;
    }
    return a.size() > b.size();
}

void make ( int n, string m )
{
    if ( n < 4 ) {
        ans = "0";
        return ;
    }
    if ( pd ( m, fib[n - 1] ) ) {
        string s1 = sub ( fib[n], "2" );
        if ( !pd ( m, s1 ) ) {
            ans = sub ( m, fib[n - 2] );
        } else {
            ans = sub ( m, fib[n - 1] );;
        }
        return ;
    } else make ( n - 1, m );
}

void MOD ( string s, LL k )
{
    LL tem = 0;
    for ( int i = s.size() - 1; i >= 0; --i ) {
        tem = ( tem * 10 + s[i] - '0' ) % k;
    }
    cout << tem << endl;
}
int main()
{
    fib[0] = "0";
    fib[1] = "1";
    for ( int i = 2; i <= 1000; ++i ) {
        fib[i] = add ( fib[i - 1] , fib[i - 2] );
    }
    cin >> T;
    while ( T-- ) {
        cin >> n >> m;
        reverse ( m.begin(), m.end() );
        make ( n, m );
        MOD ( ans, 258280327 );
    }
}
