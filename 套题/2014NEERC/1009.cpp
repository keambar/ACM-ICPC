#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int N = 200010;

int A[N], n;

int Q[N], len;
int L[N], R[N];

int main()
{
    freopen ( "improvements.in", "r", stdin );
    freopen ( "improvements.out", "w", stdout );
    int a;
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; ++i ) {
        scanf ( "%d", &a );
        A[a] = i;
    }
    len = 0;
    for ( int i = 1; i <= n; ++i ) {
        int pos = lower_bound ( Q + 1, Q + len + 1, A[i] ) - Q;
        Q[pos] = A[i];
        if ( pos > len ) len++;
        L[i] = len;
    }
    memset ( Q, 0, sizeof ( Q ) );
    len = 0;
    for ( int i = n; i >= 1; --i ) {
        int pos = lower_bound ( Q + 1, Q + len + 1, A[i] ) - Q;
        Q[pos] = A[i];
        if ( pos > len ) len++;
        R[i] = len;
    }

    int ans = 0;
    for ( int i = 1; i <= n; ++i ) {
        ans = max ( ans, L[i] + R[i] - 1 );
    }
    printf ( "%d\n", ans );
    return 0;
}