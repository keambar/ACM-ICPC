#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#define INF 16666
using namespace std;
struct node {
    int v, ne;
} edge[INF<<2];
queue<int> ql;
int head[INF], fa[INF], pd[INF];
int sum[INF], cnt, nCnt[INF];
vector<int>  out[INF];
int n, m, ans = INF;
void added (int u, int v) {
    edge[++cnt].v = v;
    edge[cnt].ne = head[u];head[u] = cnt;
}
int Count (int x) {
    pd[x] = sum[x] = 1;
    for (int i = head[x]; i != 0; i = edge[i].ne) {
        int j = edge[i].v;
        if (!pd[j]) {
            fa[j] = x;
            sum[x] += Count (j);
        }
    }
    return sum[x];
}
void make (int x) {
    int k=0;
    if (fa[x] != 0) k = sum[fa[x]] - sum[x];
    for (int i = head[x]; i != 0; i = edge[i].ne) {
        int j = edge[i].v;
        if (j != fa[x]){
            k = max (k, sum[j]);
            if(fa[x]!=0) sum[x]=sum[fa[x]];
            make(j);
        }
    }
    if (ans >= k) {
        ans = k;
        out[k].push_back (x);
        nCnt[k]++;
    }
}
int main() {
    int x, y, c;
    scanf ("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        scanf ("%d %d", &x, &y);
        added (x, y), added (y, x);
    }
    Count (1);
    make (1);
    printf ("%d %d\n", ans, nCnt[ans]);
    sort (out[ans].begin(), out[ans].end() );
    for (int i = 0; i <= out[ans].size() - 1; i++)
        printf ("%d ", out[ans][i]);
    return 0;
}