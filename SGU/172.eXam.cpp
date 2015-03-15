#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m, x, y, tol;
bool g[209][209];
int f[30009];
int dfs (int x) {
	for (int i = 1; i <= n; i++) {
		if (!g[x][i]) continue;
		if (f[i] == -1) {
			f[i] = !f[x];
			if (f[i] == 0) tol++;
			if (dfs (i) ) return 1;
		}
		else if (f[i] == f[x])
			return 1;
	}
	return 0;
}
int main() {
	scanf ("%d %d", &n, &m);
	memset (g, 0, sizeof g);
	memset (f, -1, sizeof f);
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d", &x, &y);
		g[x][y] = g[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] != -1) continue;
		f[i] = 0, tol++;
		if (dfs (i) ) {
			puts ("no");
			return 0;
		}
	}
	printf ("yes\n%d\n", tol);
	for (int i = 1; i <= n; i++)
		if (f[i] == 0) printf ("%d ", i);
	return 0;
}
