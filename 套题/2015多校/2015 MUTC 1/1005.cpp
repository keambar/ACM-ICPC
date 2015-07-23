#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int s[] = { -1, 1, 1, -1, 1, -1, 0, 0, 1, -1, -1, 1, 0, 0, -1, 1, -1, 1, 1, -1, 0, 0, 0, 0};
int T;
int main()
{
    scanf ( "%d", &T );
    for ( int k = 1; k <= T; ++k ) {
        char color[2];
        int n = 0;
        for ( int i = 0; i < 24; ++i ) {
            scanf ( "%s", color );
            if ( color[0] == 'o' || color[0] == 'r' ) {
                n += s[i];
            }
        }
        printf ( "Case #%d: ", k );
        puts ( n % 3 ? "NO" : "YES" );
    }
}