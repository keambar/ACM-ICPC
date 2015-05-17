#include <iostream>
#include <queue>
using namespace std;

const int N = 209;

queue<int> q;
bool G[N][N];
int deg[N], ans[N];
int n, m;

int main()
{
	ios::sync_with_stdio (0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		if(!G[u][v]){
            G[u][v]=1;
            deg[v]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i]==0) q.push (i);
	}
	int now = 0;
	while (!q.empty() ) {
		int u = q.front(); q.pop();
		ans[u] = ++now;
		for (int i = 1; i <= n; i++) {
			if (G[u][i] && (--deg[i]) == 0) {
				q.push (i);
			}
		}
	}
	if (now == n) {
		for (int i = 1; i <= n; i++)
			cout << ans[i] << ' ';
	}
	else {
		cout << "No solution\n";
	}
	return 0;
}
