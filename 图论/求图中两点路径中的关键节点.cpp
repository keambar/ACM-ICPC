/*
    求图中两点路径上的关键节点
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=1009,MAXM=50009;
struct Edge {
	int v, next;
} edge[MAXM];
bool vis[MAXM];
int Head[MAXN], ncnt = 1;
int dfn[MAXN], low[MAXN], t;
int n, m, ans, u, v;
inline void addedge (int u, int v) {
	edge[++ncnt].v = v, edge[ncnt].next = Head[u];
	Head[u] = ncnt;
}
bool DFS (int x) {
	if (!dfn[x]) dfn[x] = low[x] = ++t;
	bool Findv = (x==v);
	for (int i = Head[x]; i; i = edge[i].next) {
		if (!vis[i]) {
			bool Fv = 0;
			vis[i] = vis[i ^ 1] = 1;
			int vt = edge[i].v;
			if (!dfn[vt]) {
				Fv = DFS (vt);
				if (Fv) Findv = Fv;
				low[x] = min (low[vt], low[x]);
				if (Fv && low[vt] >= dfn[x]  && x != u && x != v) ans++;
			}
			else    low[x] = min (dfn[vt], low[x]);
		}
	}
	return Findv;
}
int main() {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d", &u, &v);
		addedge (u, v), addedge (v, u);
	}
	scanf ("%d %d", &u, &v);
	DFS (u);
	printf ("%d\n", ans);
}
