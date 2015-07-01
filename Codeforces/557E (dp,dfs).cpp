#include <bits/stdc++.h>
using namespace std;
const int N = 5009;
string s;
int f[N][N];
int a[N];
int k;

bool by_s ( int i, int j )
{
    if ( i == j ) {
        return false;
    }
    while ( s[i] == s[j] ) {
        i ++;
        j ++;
    }
    return s[i] < s[j];
}
char pos ( int i, int p )
{
    return s[a[i] + p];
}
void Solve ( int l, int r, int len )
{
    for ( int i = l; i < r; ) {
        int j = i;
        while ( j < r && pos ( i, len ) == pos ( j, len ) ) {
            ++j;
        }
        if ( a[i] + len < s.size() ) {
            for ( int t = i; t < j; ++t ) {
                if ( f[a[t]][a[t] + len] ) {
                    if ( --k == 0 ) {
                        for ( int i = 0; i <= len; ++i ) {
                            putchar ( pos ( t, i ) );
                        }
                    }
                }
            }
            Solve ( i, j, len + 1 );
        }
        i = j;
    }
}
int main()
{
    cin >> s >> k;
    int n = s.size();
    for ( int i = n - 1; i >= 0; -- i ) {
        for ( int j = i; j < n; ++ j ) {
            f[i][j] = s[i] == s[j];
            if ( i + 2 <= j - 2 ) {
                f[i][j] &= f[i + 2][j - 2];
            }
        }
    }
    for ( int i = 0; i < n; ++i ) a[i] = i;
    sort ( a, a + n , by_s );
    Solve ( 0, n, 0 );
}
