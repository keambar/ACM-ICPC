#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 200009;
const int MOD = int (1e9 + 7);

struct edge {
	int v, ne;
} E[N << 1];
int head[N], cnt;

LL sum[N], ans[N];

int n;

LL Quikpower (LL  Base, LL  Power)
{
	LL  k = 1;
	while ( Power > 0) {
		if (Power & 1) k = (k * Base) % MOD;
		Base = (Base * Base) % MOD;
		Power >>= 1;
	}
	return k;
}

inline void add (int u, int v)
{
	E[++cnt].v = v, E[cnt].ne = head[u];
	head[u] = cnt;
}

void dfs (int u, int from)
{
	sum[u] = 1;
	for (int i = head[u]; i; i = E[i].ne) {
		int v = E[i].v;
		if (v != from) {
			dfs (v, u);
			sum[u] = sum[u] * sum[v] % MOD;
		}
	}
	if (from != 0) ++sum[u];
}

void dfs2 (int u, int from)
{
	LL tem = 1;
	if (ans[from] != 0) {
		tem = ans[from] * Quikpower (sum[u], MOD - 2) % MOD + 1;
	}
	else {
		for (int i = head[from]; i; i = E[i].ne) {
			int v = E[i].v;
			if (v != u)
				tem = tem * sum[v] % MOD;
		}
		tem++;
	}
	sum[from] = tem;
	LL k = 1;
	for (int i = head[u]; i; i = E[i].ne) {
		int v = E[i].v;
		k = k * sum[v] % MOD;
	}
	ans[u] = k;

	int reset = sum[u];
	for (int i = head[u]; i; i = E[i].ne) {
		int v = E[i].v;
		if (v != from) {
			dfs2 (v, u);
			sum[u] = reset;
		}
	}
}
int main()
{
	ios::sync_with_stdio (0);

	cin >> n;
	for (int i = 2, x; i <= n; i++) {
		cin >> x;
		add (i, x), add (x, i);
	}

	dfs (1, 0);

	dfs2 (1, 0);

	for (int i = 1; i <= n; i++)
		cout << (ans[i] + MOD) % MOD << " ";
}
