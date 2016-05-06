#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
LL l, r , ans;
int main()
{
    while ( cin >> l >> r ) {
        if ( l == 0 && r == 0 ) return 0;
        ans = 0;
        if ( l % 5 != 0 ) {
            ++ans;
        }
        while ( l % 5 != 0 && l < r ) ++l;
        if ( l % 5 == 0 ) ++ans;
        cout << ans + ( ( r - l ) / 5 ) << endl;
    }
}