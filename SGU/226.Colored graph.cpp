#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define INF 300
using namespace std;
struct node {
    int v, ne, c;
} edge[INF * INF];
queue<int> ql;
int head[INF], pd[INF];
int dis[INF][4], cnt,n,m;
void added (int u, int v, int c) {
    edge[++cnt].v = v, edge[cnt].c = c;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}
void spfa() {
    while (!ql.empty() ) {
        int x = ql.front();
        pd[x] = 0,ql.pop();
        for (int i = head[x]; i != 0; i = edge[i].ne) {
            int j = edge[i].v, color = edge[i].c;
            for (int k = 1; k <= 3; k++) {
                if (k == color || dis[x][k] == -1) continue;
                if (dis[j][color] == -1 || dis[j][color] > dis[x][k] + 1) {
                    dis[j][color] = dis[x][k] + 1;
                    if (!pd[j])
                        pd[j] = 1, ql.push (j);
                }
            }
        }
    }
}
int main() {
    int  x, y, c;
    scanf ("%d %d", &n, &m);
    memset (dis, -1, sizeof dis);
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d%d", &x, &y, &c);
        added (x, y, c);
    }
    ql.push (1); pd[1] = 1;
    dis[1][1] = dis[1][2] = dis[1][3] = 0;
    spfa();
    int ans = INF<<12;
    for (int i = 1; i <= 3; i++)
        if (dis[n][i] != -1)
            ans = min (ans, dis[n][i]);
    if (ans != INF<<12) printf ("%d", ans);
    else
        puts ("-1");
    return 0;
}