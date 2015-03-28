/*
    ZOJ 2770 Burn the Linked Camp
    ²î·ÖÔ¼Êø
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 1009;

struct Edge {
	int v, ne, c;
} G[MAXN*MAXN];
int head[MAXN], cnt;

int C[MAXN], S[MAXN], dis[MAXN];
int vis[MAXN], sum[MAXN];

int n, m;

inline void addE (int u, int v, int c) {
	G[++cnt].v = v, G[cnt].c = c, G[cnt].ne = head[u];
	head[u] = cnt;
}

inline int SPFA() {
	queue<int> Q;
	dis[n] = 0, vis[n] = 1;
	Q.push (n);
	while (!Q.empty() ) {
		int k = Q.front(); Q.pop();
		for (int i = head[k]; i; i = G[i].ne) {
			int v = G[i].v;
			if (dis[k] + G[i].c < dis[v]) {
				dis[v] = dis[k] + G[i].c;
				if (!vis[v]) Q.push (v), vis[v] = 1, sum[v]++;
				if (sum[v] >= n) return -1;
			}
		}
		vis[k] = 0;
	}
	return -dis[0];
}

inline void init() {
	memset (head, 0, sizeof head);
	memset (sum, 0, sizeof sum);
	memset (vis, 0, sizeof vis);
	memset (dis, 1, sizeof dis);
	cnt = 0;
}

int main() {
	while (scanf ("%d %d", &n, &m) == 2) {
		init();
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &C[i]);
			S[i] = S[i - 1] + C[i];
			addE (i, i - 1, 0);
		}
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				addE (i - 1, j, S[j] - S[i - 1]);
		for (int i = 1, l, r, num; i <= m; i++) {
			scanf ("%d %d %d", &l, &r, &num);
			addE (r, l - 1, -num);
		}
		int ans = SPFA();
		if (ans != -1) printf ("%d\n", ans);
		else puts ("Bad Estimations");
	}
}
