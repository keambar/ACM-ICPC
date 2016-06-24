/*
    n<=8000 无重复
    每个数在多少个区间内第（k+1）/2大
    n^2
*/
#include <bits/stdc++.h>
using namespace std;

const int Max = 8009;

int a[Max], b[Max], c[Max], ans[Max];
int sum[Max << 1], s[Max];

int n;

bool cmp(int x, int y)
{
    return a[x] < a[y];
}


int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = i;
    }

    sort(b + 1, b + 1 + n, cmp);

    for(int i = 1; i <= n; ++i) {
        c[i] = 1;
    }

    for(int i = 1; i <= n; ++i) {
        memset(sum, 0, sizeof sum);
        sum[Max] = 1;
        c[b[i]] = 0;
        c[b[i - 1]] = -1;
        s[0] = 0;
        for(int j = 1; j <= n; ++j) {
            s[j] = s[j - 1] + c[j];
            if(j >= b[i]) ans[b[i]] += sum[Max + s[j]];
            if(j < b[i])  ++sum[Max + s[j]];
        }
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
