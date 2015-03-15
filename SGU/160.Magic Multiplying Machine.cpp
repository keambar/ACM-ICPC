#include<cstdio>
int n, m, x;
int g[10009], pr[1009][2], f[1009][2];
void write (int x) {
	if (pr[x][0] != 0) write (pr[x][0]);
	printf ("%d ", pr[x][1]);
}
int main() {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf ("%d", &x), g[i] = x % m;
	int p = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = p; j != 0; j = f[j][1]) {
			int tem = (g[i] * j) % m;
			if (tem > 1 && !f[tem][0]) {
				f[tem][0] = 1; f[tem][1] = p;
				p = tem, pr[tem][0] = j, pr[tem][1] = i;
				if (tem > ans) ans = tem;
			}
		}
		if (!f[g[i]][0]) {
			f[g[i]][0] = 1, f[g[i]][1] = p;
			p = g[i], pr[g[i]][1] = i;
			if (g[i] > ans) ans = g[i];
		}
	}
	if (ans > 0) {
		printf ("%d\n", ans);
		write (ans);
		return 0;
	}
	puts ("1");
	return 0;
}
