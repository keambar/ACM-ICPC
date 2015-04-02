/*
    置换群
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3009;

int f[MAXN], g[MAXN], pos[MAXN];

int n, m, ans, sum, t;
int  main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &g[i]), pos[g[i]] = i;

	scanf ("%d", &m);

	for (int i = 1; i <= n; i++)
		if (!f[i]) {
			f[i] = ++sum;
			for (int x = i; !f[g[x]]; x = g[x])	f[g[x]] = f[i];
		}

	t = n - sum;
	printf ("%d\n", m - t > 0 ? m - t : t - m);

	for (int i = 2; t < m; i++)
		if (f[1] != f[i]) {
			t++;
			for (int x = i; f[x] != f[1]; x = g[x])		f[x] = f[1];
			printf ("1 %d ", i);
		}

	for (int i = 1; t > m; i++) {
		if (g[i] != i)
			for (int j = i + 1; j <= n && t > m; j++)
				if (f[i] == f[j]) {
					printf ("%d %d ", i, j);
					swap (g[i], g[j]);
					t--;
					if (g[i] == i) {
						f[i] = -1; break;
					}
					else
						f[i] = f[g[i]];

					if (g[j] == j)  f[j] = -1;
					else {
						f[j] = ++sum;
						for (int x = j; f[g[x]] != sum; x = g[x])		f[g[x]] = sum;
					}
				}
	}
	return 0;
}
