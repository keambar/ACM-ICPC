/*
    ZOJ 1060 King
    ²î·ÖÔ¼Êø
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
const int MAXN = 1009;

struct edge {
	int v, c, ne;
} G[MAXN*MAXN];
int head[MAXN], cnt;
int dis[MAXN], vis[MAXN], sum[MAXN];

int n, m;

inline void addE (int u, int v, int c) {
	G[++cnt].v = v, G[cnt].c = c, G[cnt].ne = head[u];
	head[u] = cnt;
}

inline void init() {
	memset (head, 0, sizeof head);
	memset (dis, 1, sizeof dis);
	memset (vis, 0, sizeof vis);
	memset (sum, 0, sizeof sum);
	cnt = 0;
}

inline bool SPFA() {
	queue<int> ql;
	dis[n] = 0;
	for(int i=1;i<=n;i++){
        ql.push(i),vis[i]=1;
	}
	while (!ql.empty() ) {
		int x = ql.front(); ql.pop();
		for (int i = head[x]; i; i = G[i].ne) {
			int v = G[i].v;
			if (dis[x] + G[i].c < dis[v]) {
				dis[v] = dis[x] + G[i].c;
				if (!vis[v]) vis[v] = 1, ql.push (v), sum[v]++;
				if (sum[v] > n) return 0;
			}
		}
		vis[x] = 0;
	}
	return 1;
}
int main() {
	char s[10];
	while (scanf ("%d", &n) == 1 && n) {
		scanf ("%d", &m);
		init();
		for (int i = 1, l, r, c; i <= m; i++) {
			scanf ("%d %d %s %d", &l, &r, s, &c);
			r = l + r;
			if (s[0] == 'g')     addE (r, l-1, -c - 1);
			else                addE (l-1, r, c - 1);
		}
		if (SPFA() ) puts ("lamentable kingdom");
		else puts ("successful conspiracy");
	}
}
