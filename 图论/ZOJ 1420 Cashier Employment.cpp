/*
    ZOJ 1420 Cashier Employment
    ²î·ÖÔ¼Êø
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 1009;
struct edge {
	int v, c, ne;
} G[MAXN<<4];
int head[MAXN], cnt;
int dis[MAXN], vis[MAXN], sum[MAXN];

int need[MAXN], join[MAXN], s[MAXN];
int  n, m;

inline void addE (int u, int v, int c) {
	G[++cnt].v = v, G[cnt].c = c, G[cnt].ne = head[u];
	head[u] = cnt;
}

inline void init() {
	memset (head, 0, sizeof head);
	memset (sum, 0, sizeof sum);
	memset (vis, 0, sizeof vis);
	memset (dis, 1, sizeof dis);
	cnt = 0;
}

inline bool SPFA() {
	queue<int> ql;
	dis[24] = 0;
	for (int i = 0; i <= 24; i++)
		ql.push (i), vis[i] = 1;
	while (!ql.empty() ) {
		int x = ql.front(); ql.pop();
		for (int i = head[x]; i; i = G[i].ne) {
			int v = G[i].v;
			if (dis[x] + G[i].c < dis[v]) {
				dis[v] = dis[x] + G[i].c;
				if (!vis[v]) vis[v] = 1, ql.push (v), sum[v]++;
				if (sum[v] >= 23) return 0;
			}
		}
		vis[x]=0;
	}
	return 1;
}

inline bool make (int ans) {
	init();
	addE (24, 0, -ans);
	for (int i = 1; i <= 24; i++) {
		addE (i, i - 1, 0);
		addE ( i - 1, i, join[i]);
	}
	for (int i = 9; i <= 24; i++)    addE (i, i - 8, -need[i]);
	for (int i = 1; i <= 8; i++) addE (i, i + 16, ans - need[i]);
	return SPFA();
}

int main() {
	int Case;
	scanf ("%d", &Case);
	while (Case--) {
		for (int i = 1; i <= 24; i++) scanf ("%d", &need[i]);
		scanf ("%d", &n);
		for (int i = 1, x; i <= n; i++) {
			scanf ("%d", &x);
			join[x+1]++;
		}
		int l = 0, r = n, last = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (make (mid) )
				last = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		if (last != -1) printf ("%d\n", last);
		else    puts ("No Solution");
	}
}
