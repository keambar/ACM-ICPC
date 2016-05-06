#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#define pb push_back
using namespace std;
const int N = 1009;

struct edge {
	int u, v;
};
vector<edge> E[109];
int a[N][N];
int f[N * N << 1];
int cs, n, m, ans;
int dx[] = { -1, 0}, dy[] = {0, -1};

inline void init() {
	ans = 0;
	for (int i = 0; i <= 100; ++i) E[i].clear();
	memset (a, -1, sizeof a);
	for (int i = 1; i <= n * m; ++i) f[i] = i;
}

inline int Getroot (int x) {
	return f[x] == x ? x : f[x] = Getroot (f[x]);
}
int main() {
	scanf ("%d", &cs);
	for (int t = 1; t <= cs; ++t) {
		printf ("Case #%d:\n", t);
		scanf ("%d %d", &n, &m);
		init();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				int u = (i - 1) * m + j;
				scanf ("%d", &a[i][j]);
				for (int k = 0; k < 2; ++k) {
					int x = i + dx[k], y = j + dy[k];
					if (a[x][y] >= 0) {
						int v = (x - 1) * m + y;
						int d = abs (a[i][j] - a[x][y]);
						edge tem;
						tem.u = u, tem.v = v;
						E[d].pb (tem);
					}
				}
			}
		for (int i = 0; i <= 100; ++i) {
			for (int j = 0; j < E[i].size(); ++j) {
				int u = E[i][j].u, v = E[i][j].v;
				int x = Getroot (u), y = Getroot (v);
				if (x != y) {
					ans += i;
					if ( (x + y) & 1)
						f[x] = y;
					else
						f[y] = x;
				}
			}
		}
		printf ("%d\n", ans);
	}
}
