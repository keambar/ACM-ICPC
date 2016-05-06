#include <cstdio>
#include <algorithm>
using namespace std;
int d[1010][1010];
int rd[1010][1010];
int done[1010];
int n, m, s, t;
int dfs(int v, int f) {
	done[v] = 1;
	if (v == t) return f;
	for (int i = 0; i < n; i++) {
		if (done[i]) continue;
		if (d[v][i]) {
			int q = dfs(i, min(f, d[v][i]));
			if (q) {
				d[v][i] -= q;
				rd[i][v] += q;
				return q;
			}
		}
		if (rd[v][i]) {
			int q = dfs(i, min(f, rd[v][i]));
			if (q) {
				rd[v][i] -= q;
				d[i][v] += q;
				return q;
			}
		}
	}
	return 0;
}
int mf() {
	int res = 0, f;
	for (;;) {
		for (int i = 0; i < n; i++) done[i] = 0;
		f = dfs(s, 100000);
		if (!f) return res;
		res += f;
	}
}
int ss[1010], tt[1010];
void dfs2(int v) {
	done[v] = 1;
	tt[v] = 1;
	for (int i = 0; i < n; i++) {
		if (done[i]) continue;
		if (d[i][v] || rd[i][v]) dfs2(i);
	}
}
void dfs3(int v) {
	done[v] = 1;
	ss[v] = 1;
	for (int i = 0; i < n; i++) {
		if (done[i]) continue;
		if (d[v][i] || rd[v][i]) dfs3(i);
	}
}
int a[10010], b[10010];
int main() {
	while (scanf("%d%d%d%d", &n, &m, &s, &t), n) {
		--s; --t;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = rd[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a[i], &b[i]);
			--a[i]; --b[i];
			d[a[i]][b[i]]++;
		}
		int f = mf();
		for (int i = 0; i < n; i++) {
			done[i] = 0;
			tt[i] = 0;
		}
		dfs2(t);
		for (int i = 0; i < n; i++) {
			done[i] = 0;
			ss[i] = 0;
		}
		dfs3(s);
		int can = 0, k = 0;
		for (int i = 0; i < m; i++) {
			if (tt[a[i]] && ss[b[i]] && d[a[i]][b[i]]) {
				can = 1;
				++k;
			}
		}
		if (can) {
			printf("%d %d\n", f + 1, k);
		} else {
			printf("%d %d\n", f, 0);
		}
	}
	return 0;
}