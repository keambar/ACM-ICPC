#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct node {
	int x, y;
} p;
int dirx[4] = {0, 0, -1, 1}, diry[4] = {1, -1, 0, 0};
int g[5][5], f[5][5], pd[5][5];
int n, t, k;
queue<node> ql;
void BFS (int x, int y, int k) {
	node p;
	for (int i = 0; i <= 3; i++) {
		p.x = x + dirx[i], p.y = y + diry[i];
		if (f[p.x][p.y] == 0) {
			g[p.x][p.y] = k, t++;
			f[p.x][p.y] = -1, pd[p.x][p.y] = 1;
			BFS (p.x, p.y, k);
		}
		else if (f[p.x][p.y] > 0)
			if ( (--f[p.x][p.y]) == 0) ql.push (p);
	}
}
int main() {
	cin >> n;
	memset (f, -1, sizeof f);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> f[i][j];
			if (f[i][j] == 0) {
				p.x = i, p.y = j;
				ql.push (p);
			}
		}
	k = n * n;
	for (node p; !ql.empty(); ql.pop(), k--) {
		p = ql.front();
		if (pd[p.x][p.y]) continue;
		pd[p.x][p.y] = 1, g[p.x][p.y] = k, f[p.x][p.y] = -1, t++;
		BFS (p.x , p.y, k);
	}
	if (t != n * n) cout << "NO SOLUTION";
	else
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cout << g[i][j] << ' ';
			cout << endl;
		}
	return 0;
}
