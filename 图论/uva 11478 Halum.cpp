#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN = 600;
struct edge {
	int v, c, ne;
} G[MAXN*MAXN];
int head[MAXN], cnt;
int vis[MAXN], sum[MAXN], dis[MAXN];

int n, m;

inline void add (int u, int v, int d) {
	G[++cnt].v = v, G[cnt].c = d, G[cnt].ne = head[u];
	head[u] = cnt;
}

inline bool SPFA() {
	memset (dis, 0, sizeof dis);
	queue<int> q;
	for (int i = 1; i <= n; i++)
		vis[i] = 1, sum[i] = 1,	q.push (i);
	while (!q.empty() ) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int i = head[u]; i != 0; i = G[i].ne) {
			int v = G[i].v;
			if (dis[u] + G[i].c < dis[v]) {
				dis[v] = dis[u] + G[i].c;
				if (!vis[v]) q.push (v), vis[v] = 1;
				if (++sum[v] >= n)		return 0;
			}
		}
	}
	return true;
}

inline bool make (int x) {
	for (int i = 1; i <= cnt; i++) 	G[i].c -= x;
	bool ok = SPFA();
	for (int i = 1; i <= cnt; i++)	G[i].c += x;
	return ok;
}

int  main() {
	while (~scanf ("%d%d", &n, &m) ) {
		memset (head, 0, sizeof (head) );
		cnt = 0;
		int u, v, x;
		for (int i = 0; i < m; i++) {
			scanf ("%d%d%d", &u, &v, &x);
			add (u, v, x);
		}
		if (make (10009) ) puts ("Infinite");
		else if (!make (1) ) puts ("No Solution");
		else {
			int l = 1, r = 10009, ans = 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (make (mid) )
					ans = mid, l = mid + 1;
				else
					r = mid - 1;
			}
			printf ("%d\n", ans);
		}
	}
}
