/*
    欧拉回路的性质
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;

int deg[MAXN], n, m, nCnt;

vector<int > ans;
multiset <int> G[MAXN];

inline void EulerianP (int x) {
	while (!G[x].empty() ) {
		int v = *G[x].begin();
		G[x].erase (G[x].begin() );
		G[v].erase (G[v].find (x) );
		EulerianP (v);
	}
	ans.push_back (x);
}
int  main() {
	scanf ("%d %d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf ("%d %d", &u, &v);
		G[u].insert (v), G[v].insert (u);
		deg[u]++, deg[v]++;
		nCnt ++;
	}
	vector<int> s;
	for (int i = 1; i <= n; i++)
		if (deg[i] & 1) s.push_back (i);
	for (int i = 0; i < int (s.size() - 1); i += 2)
		G[s[i]].insert (s[i + 1]), G[s[i + 1]].insert (s[i]), nCnt ++;
	if (s.size() & 1)  nCnt ++;
	nCnt += nCnt & 1;
	EulerianP (1);
	printf ("%d\n", nCnt);
	for (int i = 0; i < (int) ans.size() - 1; i++) {
		if (i & 1)  printf ("%d %d\n", ans[i], ans[i + 1]);
		else     printf ("%d %d\n", ans[i + 1], ans[i]);
	}
	if (ans.size() % 2 == 0) puts ("1 1");
}
