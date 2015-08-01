#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
string s;
int n, len;
bool vis[100];
vector<int>ans;
bool dfs ( int pos )
{
    if ( pos == len )
        return 1;
    int t = s[pos] - '0';
    if ( t == 0 )
        return 0;
    if ( !vis[t] && t <= n ) {
        vis[t] = 1;
        if ( dfs ( pos + 1 ) ) {
            ans.push_back ( t );
            return 1;
        }
        vis[t] = 0;
    }
    if ( pos + 1 < len ) {
        t = t * 10 + s[pos + 1] - '0';
        if ( !vis[t] && t <= n ) {
            vis[t] = 1;
            if ( dfs ( pos + 2 ) ) {
                ans.push_back ( t );
                return 1;
            }
            vis[t] = 0;
        }
    }
    return 0;
}
int main()
{
    freopen ( "joke.in", "r", stdin );
    freopen ( "joke.out", "w", stdout );
    cin >> s;
    n = len = s.length();
    if ( n > 9 )
        n = ( n - 9 ) / 2 + 9;
    dfs ( 0 );
    for ( int i = n - 1; i > -1; i-- ) {
        cout << ans[i];
        if ( i > 0 )
            cout << " ";
    }
}