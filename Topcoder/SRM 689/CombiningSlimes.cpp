// BEGIN CUT HERE

// END CUT HERE
#line 5 "CombiningSlimes.cpp"
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
class CombiningSlimes
{
public:
    int maxMascots( vector <int> a )
    {
        priority_queue<int> s;
        for( auto &i : a ) {
            s.push( -i );
        }
        int ans = 0;
        while( SZ( s ) > 1 ) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            ans += a * b;
            s.push( a + b );
        }
        return ans;
    }
};
