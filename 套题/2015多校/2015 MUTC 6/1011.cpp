#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define  LL long long
#define  ULL unsigned long long
using namespace std;

long long quickPower ( long long a, long long b, long long m )
{
    long long ans = 1;
    while ( b ) {
        if ( b & 1 ) {
            ans = ( ans * a ) % m, b--;
        }
        b /= 2, a = a * a % m;
    }
    return ans;
}


int main()
{
    int t;
    cin >> t;
    while ( t-- ) {
        LL x;
        cin >> x;
        --x;
        LL ans = quickPower ( 2, x, 1000000007 );
        cout << ( ( ans - 1 ) % 1000000007 ) << endl;
    }
    return 0;
}
