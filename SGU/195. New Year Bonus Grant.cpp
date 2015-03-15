#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 510000;
int f[INF], vis[INF], ans[INF], tol, n;
int main() {
	scanf ("%d", &n);
	for (int i = 1; i < n; i++)
		scanf ("%d", &f[i + 1]);
	for (int i = n; i > 1; i--)
		if (!vis[i] && !vis[f[i]]) {
			vis[f[i]] = vis[i] = 1;
			ans[++tol] = i;
		}
	printf ("%d\n", tol * 1000);
	for (int i = tol; i > 0; i--)
		printf ("%d ", ans[i]);
	return 0;
}
