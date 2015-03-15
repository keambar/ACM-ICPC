#include <cstdio>
const int INF = 300 + 9;
int g[INF][INF], f[INF][INF];
int n, m, i, j, k, t;

int main() {
	scanf ("%d%d", &n, &m);
	t = (m + 1) >> 1;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j) {
			scanf ("%d", g[i] + j);
			f[i][j] = g[i][j] <= t ? 1 : INF;
		}
	for (k = 1; k <= n; ++k)
		for (i = 1; i < n; ++i)
			for (j = i + 1; j <= n; ++j)
				if (f[i][k] + f[j][k] < f[i][j])
					f[i][j] = f[j][i] = f[i][k] + f[j][k];
	for (i = 1; i < n; ++i)
		for (j = i + 1; j <= n; ++j)
			if (f[i][j] > 3) {
				printf ("%d\n", m - t);
				for (++t; t <= m; ++t)   printf ("%d ", t);
				putchar (10);
				return 0;
			}
	printf ("%d\n", t);
	for (i = 1; i <= t; ++i)  printf ("%d ", i);
	putchar (10);
	return 0;
}
