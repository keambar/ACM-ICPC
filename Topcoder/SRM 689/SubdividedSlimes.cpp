// BEGIN CUT HERE

// END CUT HERE
#line 5 "SubdividedSlimes.cpp"
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
class SubdividedSlimes
{
public:
    int needCut( int S, int M )
    {
        for( int i = 1; i < S; ++i ) {
            int res = 0;
            int t = S;
            for( int j = 0; j < i; ++j ) {
                int take = t / ( i - j + 1 );
                res += take * ( t - take );
                t -= take;
            }
            if(res>=M){
                return i;
            }
        }
        return -1;
    }
};
