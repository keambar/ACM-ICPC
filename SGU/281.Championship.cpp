#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
map<string, int> pos;
vector<string> Rank;
int n;
int main()
{
    ios::sync_with_stdio ( 0 );
    cin >> n;
    string name;
    for ( int i = 1; i <= n; ++i ) {
        cin >> name;
        pos[name] = i;
    }
    int r = 0, l = 0;
    for ( int i = 1; i <= n; ++i ) {
        cin >> name;
        Rank.push_back ( name );
        r = max ( r, pos[name] );
        if ( i == r ) {
            sort ( Rank.begin() + l, Rank.begin() + r);
            l = r;
        }
    }
    for ( int i = 0; i < n; ++i ) {
        cout << Rank[i] << "\n";
    }
}
