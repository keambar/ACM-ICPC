/*
    POJ 3169 Layout
    ²î·ÖÔ¼Êø
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1009;
struct edge {
	int v, c, ne;
} G[MAXN*MAXN];
int head[MAXN], cnt;
int sum[MAXN], vis[MAXN], dis[MAXN];

int n, ML, MD;

inline void addE (int u, int v, int c) {
	G[++cnt].v = v, G[cnt].c = c, G[cnt].ne = head[u];
	head[u] = cnt;
}

inline void init() {
	memset (vis, 0, sizeof vis);
	memset (head, 0, sizeof head);
	memset (dis, 1, sizeof dis);
	memset (sum, 0, sizeof sum);
	cnt = 0;
}

inline int SPFA() {
	queue<int> ql;
	dis[1] = 0, vis[1] = 1;
	ql.push (1);
	while (!ql.empty() ) {
		int x = ql.front(); ql.pop();
		for (int i = head[x]; i; i = G[i].ne) {
			int v = G[i].v;
			if (dis[x] + G[i].c < dis[v]) {
				dis[v] = dis[x] + G[i].c;
				if (!vis[v]) vis[v] = 1, ql.push (v), sum[v]++;
				if (sum[v] >= n) return -1;
			}
		}
		vis[x] = 0;
	}
	if (dis[n] == 0x01010101) return -2;
	return dis[n];
}

int main() {
	int u, v, c;
	init();
	scanf ("%d %d %d", &n, &ML, &MD);
	for (int i = 1; i <= ML; ++i) {
		scanf ("%d %d %d", &u, &v, &c);
		addE (u, v, c);
	}
	for (int i = 1; i <= MD; ++i) {
		scanf ("%d %d %d", &u, &v, &c);
		addE (v, u, -c);
	}
	for (int i = 2; i <= n; i++)
		addE (i, i - 1, 0);
	printf ("%d\n", SPFA() );
}
