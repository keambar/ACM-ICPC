/*
    ZOJ 1508 Intervals
    ²î·ÖÔ¼Êø
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

const int MAXN = 500009;
struct edge {
	int v, ne, c;
} G[MAXN << 1];
int head[MAXN], cnt;

int dis[MAXN], vis[MAXN];
int n, m, mr, ml;

inline void addE (int u, int v, int c) {
	G[++cnt].v = v, G[cnt].c = c, G[cnt].ne = head[u];
	head[u] = cnt;
}
inline int SPFA() {
	queue<int> ql;
	ql.push (mr);
	vis[mr] = 1, dis[mr] = 0;
	while (!ql.empty() ) {
		int x = ql.front(); ql.pop();
		for (int i = head[x]; i; i = G[i].ne) {
			int v = G[i].v;
			if (dis[x] + G[i].c < dis[v]) {
				dis[v] = dis[x] + G[i].c;
				if (!vis[v]) vis[v] = 1, ql.push (v);
			}
		}
		vis[x] = 0;
	}
	return -dis[ml - 1];
}
inline void init() {
	memset (head, 0, sizeof head);
	memset (dis, 1, sizeof dis);
	mr = 0, ml = 0x7fffffff;
	cnt = 0;
}

int main() {
	while (scanf ("%d", &n) == 1) {
		init();
		for (int i = 1, l, r, num; i <= n; i++) {
			scanf ("%d %d %d", &l, &r, &num);
			addE (r, l - 1, -num);
			mr = max (mr, r), ml = min (ml, l);
		}
		for (int i = ml; i <= mr; i++)
			addE (i - 1, i, 1), addE (i, i - 1, 0);
		printf ("%d\n", SPFA() );
	}
}
