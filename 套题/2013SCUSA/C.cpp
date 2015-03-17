#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
map<string, int> pos;
struct Edge {
	int v, c, next;
} edge[3000];
int head[3000], cnt;
int vis[3000], amm[3000], aim[3000],sum[3000];
int cs, n, m, ans;
string s, t;

void addedge (int u, int v, int c) {
	edge[++cnt].v = v, edge[cnt].c = c;
	edge[cnt].next = head[u];
	head[u] = cnt;
}
void dfs (int x, int s, int k) {
	if(k>=ans) return;
	if (aim[x]) {
		ans = min (ans, k);
		return ;
	}
	if (!vis[x]) s += amm[x], vis[x] = 1;
	if(vis[x]&&sum[x]>=s) return;
	sum[x]=max(sum[x],s);
	for (int i = head[x]; i; i = edge[i].next) {
		int v = edge[i].v, c = edge[i].c;
		if (s >= c)  dfs (v, s - c, k + c);
	}
	vis[x] = 0;
}
int main() {
	scanf ("%d", &cs);
	while (cs--) {
		pos.clear();
		memset (head, 0, sizeof head);
		memset(sum,0,sizeof sum);
		memset(vis,0,sizeof vis);
		cnt = 1, ans = 0x7fffffff;
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			cin >> s;
			pos[s] = i;
			cin >> amm[i] >> s;
			if (s[0] == 'y') aim[i] = 1;
			else aim[i] = 0;
		}
		for (int i = 1, x; i <= m; i++) {
			cin >> s >> t >> x;
			int u = pos[s], v = pos[t];
			addedge (u, v, x);
			addedge (v, u, x);
		}
		dfs (1, 0, 0);
		if (ans != 0x7fffffff) printf ("%d\n", ans);
		else puts ("No safe path");
	}
}
