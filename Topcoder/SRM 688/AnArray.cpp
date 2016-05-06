// BEGIN CUT HERE

// END CUT HERE
#line 5 "AnArray.cpp"
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
int ma[1000006];

LL gcd( LL a, LL b )
{
    return b == 0 ? a : gcd( b, a % b );
}

class AnArray
{
public:
    int solveProblem( vector<int> A, int K )
    {
        for( auto a : A ) {
            for( int i = 1; i * i <= a; i++ ) {
                if( a % i == 0 ) {
                    ma[i]++;
                    int t = a / i;
                    if( i * i != a && t <= 1000000 )ma[t]++;
                }
            }
        }
        LL res = 0;
        for( int i = 0; i < A.size(); i++ )
            for( int j = 0; j < A.size(); j++ ) {
                if( i == j )continue;
                LL tmp = 1;
                tmp = tmp * A[i] * A[j];
                int g = gcd( tmp, K );
                int t = K / g;
                res = res + ma[K / g];
                if( A[i] % t == 0 )res--;
                if( A[j] % t == 0 )res--;
            }
        return res / 6;
    }
};
