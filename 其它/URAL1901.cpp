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
const int MAXN = 10 + ( int ) 1e5;
int n, m;
int a[MAXN], b[MAXN];
int main()
{
    while ( ~scanf ( "%d %d", &n, &m ) ) {
        for ( int i = 0; i < n; ++i ) {
            scanf ( "%d", &a[i] );
        }
        sort ( a, a + n );
        int l = 0, r = n - 1;
        int ans = 0;
        int cnt = 0;
        while ( l < r ) {
            if ( a[r] + a[l] > m ) {
                b[cnt++] = a[l++], b[cnt++] = a[r--];
            } else {
                b[cnt++] = a[l++];
                b[cnt++] = a[l++];
            }
        }
        if ( l == r ) b[cnt++] = a[l];
        for ( int i = 0; i < cnt; ++i ) {
            ++ans;
            if ( b[i] + b[i + 1] <= m )
                ++i;
        }
        printf ( "%d\n", ans );
        for ( int i = 0; i < n; ++i ) {
            printf ( i == n - 1 ? "%d\n" : "%d ", b[i] );
        }
    }
    return 0;
}

