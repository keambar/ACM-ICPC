/*
       前向星存边，对于一个完全子图用并查集进行合并,存入f[].
       寻找欧拉路时每次只在一个完全子图中用一条边,并标记走过的点,直接输出答案.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = int (1e4 + 9);
//前向星存边
struct Edge {
	int u, v, ne;
} edge[INF * 20];
int head[INF], deg[INF], vise[INF * 20], vis[INF], f[INF], cnt = 1;
int n, m, x, y;

void addedge (int u, int v) {
	edge[++cnt].u = u, edge[cnt].v = v;
	edge[cnt].ne = head[u], head[u] = cnt;
}
//合并完全子图
void change() {
	for (int i = 1; i <= n; i++)
		if (deg[i] > 2 && !vis[i]) {
			for (int j = head[i]; j != 0; j = edge[j].ne) {
				int v = edge[j].v;
				if (deg[v] > 2)
					f[v] = i, vis[v] = 1;
			}
		}
}
void EulerianPath (int x, int p) {
	vis[x] = 1;
	for (int i = head[x]; i != 0; i = edge[i].ne) {
		if (vise[i] || vis[edge[i].v]) continue;
		int u = edge[i].u, v = edge[i].v;
		if (p && f[u] == f[v]) {
			vise[i] = vise[i ^ 1] = 1;
			//由内传来
			EulerianPath (v, 0);
		}
		if (deg[x] == 2 || (!p && f[u] != f[v]) ) {
			vise[i] = vise[i ^ 1] = 1;
			//由外传来
			EulerianPath (v, 1);
		}
	}
	printf ("%d ", x);
}
//判断并寻找欧拉回路
void Eulerian() {
	int t = 0;
	for (int i = 1; i <= n; i++) {
		if (!f[i] && deg[i] & 1) {
			t++; break;
		}
		if (!f[i]) f[i] = i;
	}
	if (t != 0) {
		puts ("-1"); return;
	}
	memset (vis, 0, sizeof vis);
	EulerianPath (1, 0);//如果存在哈密顿回路以任意起点出发均可
}
int main() {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d", &x, &y);
		addedge (x, y), addedge (y, x);
		deg[x]++, deg[y]++;
	}
	change();
	Eulerian();
	return 0;
}
