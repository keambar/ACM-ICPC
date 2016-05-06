#include <bits/stdc++.h>
#define LL long long
using namespace std;
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int INF = 311;
struct node {
	int u, v, c, next;
} edge[INF*INF];
int  pHead[INF*INF], SS, ST, nCnt = 1;
int n, m;
void addEdge (int u, int v, int c) {
	edge[++nCnt].v = v; edge[nCnt].c = c, edge[nCnt].next = pHead[u]; pHead[u] = nCnt;
	edge[nCnt].u = u;
	edge[++nCnt].v = u; edge[nCnt].c = 0, edge[nCnt].next = pHead[v]; pHead[v] = nCnt;
	edge[nCnt].u = v;
}
int SAP (int pStart, int pEnd, int N) {
	int numh[INF], h[INF], curEdge[INF], pre[INF];
	int cur_flow, flow_ans = 0, u, neck, i, tmp;
	ms (h, 0); ms (numh, 0); ms (pre, -1);
	for (i = 0; i <= N; i++) curEdge[i] = pHead[i];
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

int out[INF][INF];
int s[INF], t[INF];
int need;
int main() {
	ios::sync_with_stdio (0);

	cin >> n >> m;
	SS = 0, ST = n * 2 + 1;
	int tem=0;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		tem+=s[i];
		addEdge (SS, i, s[i]);
		addEdge (i, i + n, s[i]);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		need += t[i];
		addEdge (n + i, ST, t[i]);
	}
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		addEdge (u, n + v, s[u]);
		addEdge (v, n + u, s[v]);
	}
	int ans = SAP (SS, ST, 2 * n + 1);
	if (ans != need||tem!=need) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
}