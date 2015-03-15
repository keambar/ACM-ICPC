#include <cstdio>
const int INF = 111;
int g[INF][INF], vis[INF], path[INF];
int n, m, k, x, y, z, l, r, mid, leSum;
int S, T, pd, len, tol;
void dfs (int x, int dis) {
	vis[x] = 1;
	if (x == T) {
		if (dis < mid)  leSum++;
		if (!pd && dis == mid) leSum++, pd = 1;
	}
	else
		for (int i = 1; i <= n; i++)
			if (!vis[i] && g[x][i] && dis + g[x][i] <= mid)
				dfs (i, dis + g[x][i]);
	vis[x] = 0;
}
int check (int x) {
	pd = leSum = 0;
	dfs (S, 0);
	return leSum;
}
int getPath (int x, int dis) {
	vis[x] = 1;
	if (x == T && dis == len) {
		path[++tol] = x;
		return pd = 1;
	}
	else
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && g[x][i] && g[x][i] + dis <= len) {
				if (getPath (i, dis + g[x][i]) ) path[++tol] = x;
				if (pd) return 1;
			}
		}
	vis[x] = 0;
}
int Search () {
	while (l <= r) {
		mid = l + (r - l >> 1);
		int tem = check (mid);
		if (tem == k)
			return mid;
		else if (tem > k)
			r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}
int main() {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d %d", &x, &y, &z);
		g[x][y] = g[y][x] = z, r += z;
	}
	scanf ("%d %d", &S, &T);
	len = Search();
	pd = tol = 0;
	getPath (S, 0);
	printf ("%d %d\n", len, tol);
	for (int i = tol; i > 1; i--)
		printf ("%d ", path[i]);
		printf("%d\n",path[1]);
	return 0;
}
