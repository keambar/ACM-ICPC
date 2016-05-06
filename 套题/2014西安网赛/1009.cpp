/*
* Problem: 
* Author: Leo Yu
* Time: 
* State: SOLVED
* Memo: 
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int    read()
{
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; ch < '0' || ch > '9'; ch = getchar())    if (ch == '-')  positive = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())    x = x * 10 + ch - '0';
    return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

const int MOD = 10000007;
int N, M;
LL a[15], b[15][15], c[15], d[15][15];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

    while (scanf("%d%d", &N, &M) != EOF)
    {
        for (int i = 1; i <= N; ++ i)    a[i] = read() % MOD;
        a[0] = 233;
        for (int i = 1; i <= N; ++ i)    a[i] = (a[i - 1] + a[i]) % MOD;
        a[N + 1] = 1;
        memset(b, 0, sizeof(b));
        b[0][0] = 10, b[N + 1][0] = 3;
        for (int i = 1; i <= N; ++ i)
        {
            for (int j = 0; j <= N + 1; ++ j)    b[j][i] = b[j][i - 1];
            b[i][i] = 1;
        }
        b[N + 1][N + 1] = 1;
        for (int i = M - 1; i; i /= 2)
        {
            if (i & 1)
            {
                memset(c, 0, sizeof(c));
                for (int i = 0; i <= N + 1; ++ i)
                for (int j = 0; j <= N + 1; ++ j)
                    c[i] = (c[i] + a[j] * b[j][i]) % MOD;
                memcpy(a, c, sizeof(c));
            }
            memset(d, 0, sizeof(d));
            for (int i = 0; i <= N + 1; ++ i)
            for (int j = 0; j <= N + 1; ++ j)
            for (int k = 0; k <= N + 1; ++ k)
                d[i][j] = (d[i][j] + b[i][k] * b[k][j]) % MOD;
            memcpy(b, d, sizeof(d));
        }
        printf("%d\n", int(a[N]));
    }

    return 0;
}