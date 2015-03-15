#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdio>
using namespace std;
const int INF = 1700;
struct node {
	int u, v, next;
} edge[100000];
int pHead[INF], vis[INF], pr[INF];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n, m, x, y, nCnt, an;
int exPath (int x) {
	for (int k = pHead[x]; k != 0; k = edge[k].next) {
		int x = edge[k].u, y = edge[k].v;
		if (!vis[y]) {
			vis[y] = 1;
			if ( !pr[y] || exPath (pr[y]) ) return pr[y] = x;
		}
	}
	return 0;
}
void addEdge (int u, int v) {
	edge[++nCnt].u = u, edge[nCnt].v = v;
	edge[nCnt].next = pHead[u];
	pHead[u] = nCnt;
}
int g[50][50];
int main() {
       //ofstream cout("out.txt");
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) g[i][j] = 1;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		g[x][y] = 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (g[i][j])
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k], y = j + dy[k];
					if (g[x][y])
						addEdge ( (i - 1) *n + j, (x - 1) *n + y);
				}
		}
	for (int i = 1; i <= n * n; i++) {
		if (exPath (i) ) an++;
		memset (vis, 0, sizeof vis);
	}
	int t1 = 0, t2 = 0;
	int ans[2][INF];
	for (int i = 1; i <= n * n; i++) {
		if (pr[i] && !vis[i]) {
			vis[i] = vis[pr[i]] = 1;
			if (abs (pr[i] - i) == n)
				ans[0][++t1] = min (i, pr[i]);
			else
				ans[1][++t2] = min (i, pr[i]);
		}
	}
	if (an == (n * n - m) ) {
		cout << "Yes" << endl;
		cout << t1 << endl;
		for (int i = 1; i <= t1; i++) {
			int l, r;
			if (ans[0][i] % n) l = ans[0][i] / n + 1, r = ans[0][i] % n;
			else
				l = ans[0][i] / n, r = n;
			cout << l << ' ' << r << endl;
		}
		cout << t2 << endl;
		for (int i = 1; i <= t2; i++) {
			int l, r;
			l = ans[1][i] / n + 1, r = ans[1][i] % n;
			cout << l << ' ' << r << endl;
		}
	}
	else
		cout << "No";
	return 0;
}
