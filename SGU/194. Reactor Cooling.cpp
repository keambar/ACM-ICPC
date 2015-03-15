/*
       无汇源有上下界的网络流
*/
#include <iostream>
#include <cstring>
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int MAXN = 209;

struct node {
	int u, v, c, ne;
} edge[MAXN * MAXN << 2];
int pHead[MAXN*MAXN], SS, ST, T, ncnt, ans;
int Gup[MAXN][MAXN], Glow[MAXN][MAXN], st[MAXN], ed[MAXN], cap[MAXN][MAXN], tflow;

void addEdge (int u, int v, int c) {
	edge[++ncnt].v = v, edge[ncnt].c = c, edge[ncnt].u = u;
	edge[ncnt].ne = pHead[u], pHead[u] = ncnt;
	edge[++ncnt].v = u, edge[ncnt].c = 0, edge[ncnt].u = v;
	edge[ncnt].ne = pHead[v], pHead[v] = ncnt;
}

int SAP (int pStart, int pEnd, int N) {
	int numh[MAXN], h[MAXN], curEdge[MAXN], pre[MAXN];
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
		for ( i = curEdge[u]; i != 0; i = edge[i].ne) {
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
			for (tmp = N, i = pHead[u]; i != 0; i = edge[i].ne) {
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
	SS = n + 1, ST = n + 2;
	for (int i = 1; i <= n; i++) {
		if (ed[i]) addEdge (SS, i, ed[i]);
		if (st[i]) addEdge (i, ST, st[i]);
	}
	int tem = SAP (SS, ST, ST);
	if (tem != tflow) return 0;
	else
              return 1;
}
int n, m;
int main() {
	ios::sync_with_stdio (0);
	ncnt = 1;
	cin >> n >> m;
	for (int i = 1, u, v, x, y; i <= m; i++) {
		cin >> u >> v >> x >> y;
		Gup[u][v] = y, Glow[u][v] = x;
		st[u] += x, ed[v] += x;
		tflow += x;
		addEdge (u, v, y - x);
	}
	if (solve (n) ) {
		cout << "YES\n";
		for (int i = 2, x, y; i <= m * 2; i += 2) {
			x = edge[i].u, y = edge[i].v;
			cout << Gup[x][y]-edge[i].c << '\n';
		}
	}
	else
		cout << "NO\n";
	return 0;
}
