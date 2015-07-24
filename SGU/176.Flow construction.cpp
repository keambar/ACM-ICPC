/*
      有容量上下界的最大流算法
         1)cap(u,v)为u到v的边的容量
         2)Gup(u,v)为u到v的边流量上界
         3)Glow(u,v)为u到v的边流量下界
         4)st(u)代表点u的所有出边的下界之和
         5)ed(u)代表点u的所有入边的下界之和
         6)S为源点，T为汇点
       新网络D的构造方法:
         1)加入虚拟源点SS,ST
         2)如果边(u,v)的容量cap(u,v)=Gup(u,v)-Glow(u,v)
         3)对于每个点v,加入边(SS,v)=ed(v);
         4)对于每个点u,加入边(u,ST)=st(u);
         5)cap(T,S)=+∞;
         6)tflow为所有边的下界之和
       求SS到ST的最大流，若最大流不等于tflow，则不存在可行流，此问题无解。
       在新网络D中去掉所有与SS，ST相连的边。求最大流。
       最后将两个流值相加
       最小流，第二次最大流从T到S运行。

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int INF = 111;
struct node {
    int u, v, c, next;
} edge[INF * INF << 2];
int Gup[INF][INF], Glow[INF][INF], st[INF], ed[INF], cap[INF][INF], tflow;
int  pHead[INF*INF], SS, ST, S, T, nCnt, ans;
//同时添加弧和反向边, 反向边初始容量为0
void addEdge (int u, int v, int c) {
    edge[++nCnt].v = v, edge[nCnt].u = u, edge[nCnt].c = c;
    edge[nCnt].next = pHead[u]; pHead[u] = nCnt;
    edge[++nCnt].v = u, edge[nCnt].u = v, edge[nCnt].c = 0;
    edge[nCnt].next = pHead[v]; pHead[v] = nCnt;
}
int SAP (int pStart, int pEnd, int N) {
    int numh[INF], h[INF], curEdge[INF], pre[INF];
    int cur_flow, flow_ans = 0, u, neck, i, tmp;
    ms (h, 0); ms (numh, 0); ms (pre, -1);
    for (i = 0; i <= N; i++) curEdge[i] = pHead[i];
    numh[0] = N;
    u = pStart;
    while (h[pStart] <= N) {
        if (u == pEnd) {
            cur_flow = 1e9;
            for (i = pStart; i != pEnd; i = edge[curEdge[i]].v)
                if (cur_flow > edge[curEdge[i]].c) neck = i, cur_flow = edge[curEdge[i]].c;
            for (i = pStart; i != pEnd; i = edge[curEdge[i]].v) {
                tmp = curEdge[i];
                edge[tmp].c -= cur_flow, edge[tmp ^ 1].c += cur_flow;
            }
            flow_ans += cur_flow;
            u = neck;
        }
        for ( i = curEdge[u]; i != 0; i = edge[i].next) {
            if (edge[i].v > N) continue; //重要!!!
            if (edge[i].c && h[u] == h[edge[i].v] + 1)     break;
        }
        if (i != 0) {
            curEdge[u] = i, pre[edge[i].v] = u;
            u = edge[i].v;
        }
        else {
            if (0 == --numh[h[u]]) continue;
            curEdge[u] = pHead[u];
            for (tmp = N, i = pHead[u]; i != 0; i = edge[i].next) {
                if (edge[i].v > N) continue; //重要!!!
                if (edge[i].c)  tmp = min (tmp, h[edge[i].v]);
            }
            h[u] = tmp + 1;
            ++numh[h[u]];
            if (u != pStart) u = pre[u];
        }
    }
    return flow_ans;
}
int solve (int n) {
    //建立伴随网络
    SS = n + 1, ST = n + 2;
    for (int i = 1; i <= n; i++) {
        if (ed[i]) addEdge (SS, i, ed[i]);
        if (st[i]) addEdge (i, ST, st[i]);
    }
    //T到S添加一条无限容量边
    addEdge (T, S, 0x7ffffff);
    //判断可行流
    int tem = SAP (SS, ST, ST);
    if (tem != tflow) return -1;
    else {
        edge[nCnt].c = edge[nCnt - 1].c = 0; //删除S到T的无限容量边
        int kkk = SAP (T, S, T);
        return 1;
    }
}
int n, m, x, y, c, sta;
int main() {
    /*
           建图,前向星存边，表头在pHead[],边计数 nCnt.
           S,T分别为源点和汇点
    */
    scanf ("%d %d", &n, &m);
    nCnt = 1;
    for (int i = 1; i <= m; i++) {
        scanf ("%d %d %d %d", &x, &y, &c, &sta);
        Gup[x][y] = c;
        if (sta) {
            Glow[x][y] = c;
            st[x] += c, ed[y] += c;
            tflow += c;
        }
        addEdge (x, y, Gup[x][y] - Glow[x][y]);
    }
    S = 1, T = n;
    ans = 0;
    if (solve (n) > 0) {
        for (int i = 2; i <= nCnt; i += 2) {
            if (edge[i].v <= T && edge[i].u == 1)
                ans += Gup[edge[i].u][edge[i].v] - edge[i].c;
            if (edge[i].u <= T && edge[i].v == 1)
                ans -= Gup[edge[i].u][edge[i].v] - edge[i].c;
        }
        if (ans < 0) {
            S = 0;
            addEdge (S, 1, -ans);
            ans = 0;
            SAP (S, T, T);
        }
        printf ("%d\n", ans);
        for (int i = 2; i <= 2 * m; i += 2)
            printf ("%d ", Gup[edge[i].u][edge[i].v] - edge[i].c);
    }
    else puts ("Impossible");
    return 0;
}