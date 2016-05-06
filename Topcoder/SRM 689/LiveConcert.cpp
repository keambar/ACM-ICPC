// BEGIN CUT HERE

// END CUT HERE
#line 5 "LiveConcert.cpp"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
class LiveConcert
{
public:
    int maxHappiness( vector <int> h, vector <string> s )
    {
        map<string, int> Sm;
        for( int i = 0; i < SZ( h ); ++i ) {
            Sm[s[i]] = max( Sm[s[i]], h[i] );
        }
        int ans = 0;
        for( auto &i : Sm ) {
            ans += i.se;
        }
        return ans;
    }
};
