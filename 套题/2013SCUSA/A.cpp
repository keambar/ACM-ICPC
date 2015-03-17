/*
      最大流SAP
      邻接表
      思路：基本源于FF方法，给每个顶点设定层次标号，和允许弧。
      优化:
      1、当前弧优化（重要）。
      1、每找到以条增广路回退到断点（常数优化）。
      2、层次出现断层，无法得到新流（重要）。
      时间复杂度（m*n^2）
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int INF = 6111;
struct node {
	int v, c, next;
} edge[100000];
int  pHead[100000], SS, ST, nCnt;
int n, m;
int g[200][200];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//同时添加弧和反向边, 反向边初始容量为0
void addEdge (int u, int v, int c) {
	edge[++nCnt].v = v; edge[nCnt].c = c, edge[nCnt].next = pHead[u]; pHead[u] = nCnt;
	edge[++nCnt].v = u; edge[nCnt].c = 0, edge[nCnt].next = pHead[v]; pHead[v] = nCnt;
}
inline int SAP (int pStart, int pEnd, int N) {
	//层次点的数量  点的层次   点的允许弧     当前走过边的栈
	int numh[INF], h[INF], curEdge[INF], pre[INF];
	//当前找到的流, 累计的流量, 当前点, 断点, 中间变量
	int cur_flow, flow_ans = 0, u, neck, i, tmp;
	//清空层次数组,
	ms (h, 0); ms (numh, 0); ms (pre, -1);
	//将允许弧设为邻接表的任意一条边
	for (i = 0; i <= N; i++) curEdge[i] = pHead[i];
	numh[0] = N;//初始全部点的层次为0
	u = pStart;//从源点开始
	//如果从源点能找到增广路
	while (h[pStart] <= N) {
		//找到增广路
		if (u == pEnd) {
			cur_flow = 1e9;
			//找到当前增广路中的最大流量, 更新断点
			for (i = pStart; i != pEnd; i = edge[curEdge[i]].v)
				if (cur_flow > edge[curEdge[i]].c) neck = i, cur_flow = edge[curEdge[i]].c;
			//增加反向边的容量
			for (i = pStart; i != pEnd; i = edge[curEdge[i]].v) {
				tmp = curEdge[i];
				edge[tmp].c -= cur_flow, edge[tmp ^ 1].c += cur_flow;
			}
			flow_ans += cur_flow;//累计流量
			u = neck;//从断点开始找新的增广路
		}
		//找到一条允许弧
		for ( i = curEdge[u]; i != 0; i = edge[i].next)
			if (edge[i].c && h[u] == h[edge[i].v] + 1)     break;
		//继续DFS
		if (i != 0) {
			curEdge[u] = i, pre[edge[i].v] = u;
			u = edge[i].v;
		}
		//当前起点没有允许弧,从u找不到增广路
		else {
			//u所在的层次点减少一,且如果没有与当前点一个层次的点, 退出.
			if (0 == --numh[h[u]]) continue;
			//有与u相同层次的点, 更新u的层次 ,回到上一个点
			curEdge[u] = pHead[u];
			for (tmp = N, i = pHead[u]; i != 0; i = edge[i].next)
				if (edge[i].c)  tmp = min (tmp, h[edge[i].v]);
			h[u] = tmp + 1;
			++numh[h[u]];
			if (u != pStart) u = pre[u];
		}
	}
	return flow_ans;
}
inline void build() {
	char ch;
	scanf ("%d %d", &n, &m);
	ms (g, -1), ms (pHead, 0), nCnt = 1;
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			ch = getchar();
			if (ch == '.')  g[i][j] = 0;
			if (ch == 'D') g[i][j] = 1;
		}
	}
	n += 2, m += 2;
	SS = n * m, ST = SS + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u = i * m + j;
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				addEdge (u, ST, 4);
				continue;
			}
			if (g[i][j] == 0)  {
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k], y = j + dy[k];
					int v = m * x + y;
					if (g[x][y] != 1)	addEdge (u, v, 1);
				}
			}
			if (g[i][j] == 1) {
				addEdge (SS, u, 4);
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k], y = j + dy[k];
					int v = m * x + y;
					if (g[x][y] != 1 ) 	addEdge (u, v, 1);
				}
			}
		}
	}
}
int cs;
int main() {
	/*
	       建图,前向星存边，表头在pHead[],边计数 nCnt.
	       SS,ST分别为源点和汇点
	*/
	scanf ("%d", &cs);
	while (cs--) {
		build();
		printf ("%d\n", SAP (SS, ST, n * m + 1) );
	}
	return 0;
}
