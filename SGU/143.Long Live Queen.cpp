#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define INf 16666
#define Maxn 0xfffffff
using namespace std;
vector<int> g[INf];
int val[INf], f[INf];
int n, x, y, tem;
int dfs (int x, int fa) {
	f[x] = val[x];
	for (int i = 0; i < g[x].size(); i++) {
              tem=0;
		if (g[x][i] != fa)
			tem = dfs (g[x][i], x);
		if (tem > 0) f[x] += tem;
	}
	return f[x];
}
int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", &val[i]);
	for (int i = 1; i < n; i++) {
		scanf ("%d %d", &x, &y);
		g[x].push_back (y);
		g[y].push_back (x);
	}
	dfs (1, -1);
	int ans = -Maxn;
	for (int i = 1; i <=n; i++)
		ans = max (ans, f[i]);
	printf ("%d", ans);
}
