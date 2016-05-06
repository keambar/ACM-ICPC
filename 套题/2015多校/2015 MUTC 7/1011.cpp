#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL long long
using namespace std;

const int N = 200005;
const int Mod = int ( 1e9 + 7 );

struct Edge {
    int v, ne;
} E[N];
int head[N], cnt;

void add ( int u, int v )
{
    E[++cnt].v = v, E[cnt].ne = head[u];
    head[u] = cnt;
}

int n;
int num[N];
LL fac[N];
void calc ( int u, int pre )
{
    num[u] = 1;
    for ( int i = head[u]; i; i = E[i].ne ) {
        int v = E[i].v;
        if ( v == pre ) continue;
        calc ( v, u );
        num[u] += num[v];
    }
}

LL DFS ( int u, int pre )
{
    int sum1 = 0, sum2 = 0;
    int sv[3];
    for ( int i = head[u]; i; i = E[i].ne ) {
        int v = E[i].v;
        if ( v == pre ) continue;
        if ( num[v] == 1 ) {
            ++sum1;
        } else {
            if ( ++sum2 > 2 ) return 0;
            sv[sum2] = v;
        }
    }
    LL ret = 1;
    for ( int i = 1; i <= sum2; ++i ) {
        ret = ( ret * DFS ( sv[i] , u ) ) % Mod;
    }
    if ( sum2 ) ret = ret * 2 % Mod;
    return fac[sum1] * ret % Mod;
}

int main()
{
    fac[0] = 1;
    for ( int i = 1; i <= 100000; i++ ) {
        fac[i] = fac[i - 1] * i % Mod;
    }
    int T;
    scanf ( "%d", &T );
    for ( int t = 1; t <= T; ++t ) {
        scanf ( "%d", &n );
        if ( n == 1 ) {
            printf ( "Case #%d: 1\n", t );
            continue;
        }
        memset ( head, cnt = 0, sizeof head );
        for ( int i = 1, u, v; i < n; ++i ) {
            scanf ( "%d %d", &u, &v );
            add ( u, v ), add ( v, u );
        }
        calc ( 1, 0 );
        printf ( "Case #%d: %d\n", t, int ( DFS ( 1, 0 ) * 2 % Mod ) );
    }
    return 0;
}
