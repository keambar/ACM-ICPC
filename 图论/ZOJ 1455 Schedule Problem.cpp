/*
    ZOJ 1455 Schedule Problem
    差分约束
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 10009;
struct edge {
	int v, c, ne;
} G[MAXN << 4];
int head[MAXN], cnt;
int sum[MAXN], vis[MAXN], dis[MAXN];

int n;
int  Len[MAXN];

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
	dis[0] = 0, vis[0] = 1, ql.push (0);
	while (!ql.empty() ) {
		int x = ql.front(); ql.pop();
		for (int i = head[x]; i; i = G[i].ne) {
			int v = G[i].v;
			if (dis[x] + G[i].c < dis[v]) {
				dis[v] = dis[x] + G[i].c;
				if (!vis[v]) vis[v] = 1, ql.push (v), sum[v]++;
				if (sum[v] >= n) return 0;
			}
		}
		vis[x] = 0;
	}
	return 1;
}
int main() {
	char s[10];
	int Cs = 0;
	while (scanf ("%d", &n) == 1 && n) {
		init();
		for (int i = 1; i <= n; i++) {
                scanf ("%d", &Len[i]);
                addE (0, i, -Len[i]);
		}
		int u, v;
		while (scanf ("%s", s) == 1 && s[0] != '#') {
			scanf ("%d %d", &u, &v);
			if (!strcmp (s, "FAS") ) addE (u, v, Len[u]);
			if (!strcmp (s, "FAF") ) addE (u, v, Len[u] - Len[v]);
			if (!strcmp (s, "SAF") ) addE (u, v, -Len[v]);
			if (!strcmp (s, "SAS") ) addE (u, v, 0);
		}
		printf ("Case %d:\n", ++Cs);
		if (SPFA() ) {
		    int t=~(1<<31);
            for (int i = 1; i <= n; i++) t=min(t,dis[i]);
			for (int i = 1; i <= n; i++)
				printf ("%d %d\n", i, dis[i]-t);
		}
		else puts ("impossible");
		puts("");
	}
}
