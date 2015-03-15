#include<cstdio>
int sum[10009], n, m, x, y;
int main() {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d", &x, &y);
		sum[x]++, sum[y]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += sum[i] * sum[i];
	printf ("%d", ans);
	return 0;
}

