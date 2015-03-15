#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define INF 1111
using namespace std;
bool edge[INF][INF];
int ans[INF], vis[INF];
int n, tol = 2, t, s = 1;
void expand() {
	int i;
	while (1) {
		for (i = 1; i <= n; i++) {
			if (edge[t][i] && !vis[i]) {
				ans[tol++] = i;
				t = i, vis[i] = 1;
				break;
			}
		}
		if (i > n) return;
	}
}
void Hamiton() {
	int i, j;
	for (i = 1; i <= n; i++) if (edge[s][i]) break;
	t = i;
	ans[0] = s, ans[1] = t;
	vis[s] = vis[t] = 1;
	while (1) {
		expand();
		reverse (ans, ans + tol);
		swap (s, t);
		expand();
		if (!edge[s][t]) {
			for (i = 1; i < tol - 2; i++)
				if (edge[ans[i]][t] && edge[ans[i + 1]][s]) break;
			reverse (ans + i + 1, ans + tol);
			t = ans[tol - 1];
		}
		if (tol == n) return;
		for (j = 1; j <= n; j++) {
			if (vis[j]) continue;
			for (i = 1; i < tol - 1; i++)
				if (edge[ans[i]][j])	break;
			if (edge[ans[i]][j]) break;
		}
		s = ans[i - 1], t = j;
		reverse (ans, ans + i);
		reverse (ans + i, ans + tol);
		ans[tol++] = j, vis[j] = 1;
	}
}
int main() {
	char ci;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &t);
		edge[i][t] = edge[t][i] = 1;
		ci = getchar();
		while (ci != '\n' && ci != '\r' && ci != EOF)
			scanf ("%d", &t), edge[i][t] = edge[t][i] = 1, ci = getchar();
	}
	Hamiton();
	int i;
	for (i = 0; i < n; i++)
		if (ans[i] == 1) break;
	for (int j = 0; j < n; j++) {
		printf ("%d ", ans[i]);
		i++;
		if (i == n) i = 0;
	}
	putchar ('0' + 1);
	return 0;
}
