#include <iostream>
using namespace std;
int n, ans;
int s[1009];

void dfs ( int x )
{
    if ( x - 2 > 0 && s[x - 2] != 0 ) return;
    if ( x == n + 1 ) {
        if ( s[n] == 0 ) ++ans;
        return ;
    }
    dfs ( x + 1 );
    int flag = 0;
    for ( int i = -1; i <= 1; ++i ) {
        if ( ( x + i > 0 && x + i <= n ) && --s[x + i] < 0 ) flag = 1;
    }
    if ( !flag ) dfs ( x + 1 );
    for ( int i = -1; i <= 1; ++i ) {
        if ( x + i > 0 ) ++s[x - i];
    }
}
int main()
{
    cin >> n;
    for ( int i = 1; i <= n; ++i ) {
        cin >> s[i];
    }
    dfs ( 1 );
    cout << ans << endl;
}
