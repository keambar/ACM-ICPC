#include <bits/stdc++.h>
using namespace std;

const int N = 3009;

struct edge {
	int v, ne;
} E[N * N << 1];
int head[N], cnt;

int n, m, ans;
int s1, s2, t1, t2, l1, l2;

int dis[5][N];
int vis[N];

void SPFA (int S, int k) {
	queue<int> q;
	memset (vis, 0, sizeof vis);
	dis[k][S] = 0;
	vis[S] = 1;
	q.push (S);
	while (!q.empty() ) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = E[i].ne) {
			int v = E[i].v;
			if (dis[k][u] + 1 < dis[k][v]) {
				dis[k][v] = dis[k][u] + 1;
				if (!vis[v]) {
					vis[v] = 1;
					q.push (v);
				}
			}
		}
		vis[u] = 0;
	}
}

inline void  add (int u, int v) {
	E[++cnt].v = v, E[cnt].ne = head[u];
	head[u] = cnt;
}

int main() {
	ios::sync_with_stdio (0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		add (u, v), add (v, u);
	}
	cin >> s1 >> t1 >> l1;
	cin >> s2 >> t2 >> l2;
	memset (dis, 0x1f, sizeof dis);
	SPFA (s1, 0);
	SPFA (s2, 1);
	SPFA (t1, 2);
	SPFA (t2, 3);
	if (dis[0][t1] <= l1 && dis[1][t2] <= l2) {
		ans = dis[0][t1] + dis[1][t2];
		for (int i = 1; i <= n; ++i) {
			int flag = 0;
			for (int k = 1; k <= n; ++k) dis[4][k] = 33333;
			for (int j = i + 1; j <= n; ++j) {
				int tem1 = min (dis[0][i] + dis[2][j], dis[0][j] + dis[2][i]);
				int tem2 = min (dis[1][i] + dis[3][j], dis[1][j] + dis[3][i]);
				if (tem1 + tem2 < ans && tem1 < l1 && tem2 < l2) {
					if (!flag) {
						SPFA (i, 4);
						flag = 1;
					}
					if (tem1 + dis[4][j] <= l1 && tem2 + dis[4][j] <= l2) {
						ans = min (ans, tem1 + tem2 + dis[4][j]);
					}
				}
			}
		}
	}
	else {
		ans = m + 1;
	}
	cout << m - ans << endl;
}
