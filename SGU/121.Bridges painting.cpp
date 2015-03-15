#include <iostream>
#include <cstring>
#define INF 111
using namespace std;
int edge[INF][INF], color[INF][INF], sed[INF];
int n, x, sum, t;
void dfs (int x, int k) {
	for (int i = 1, j; i <= sed[x]; i++) {
		j = edge[x][i];
		if (!color[x][j]) {
			color[x][j] = color[j][x] = k == 0 ? 2 : 1;
			dfs (j, k ^ 1);
			k ^= 1;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		while (cin >> x && x != 0)
			edge[i][++sed[i]] = x;
	for (int i = 1; i <= n; i++)
		if (sed[i] & 1) dfs (i, 1);
	for (int i = 1; i <= n; i++)
		dfs (i, 1);
	for (int i = 1, k; i <= n; i++) {
		if (sed[i] <= 1) continue;
		k = 0;
		for (int j = 1; j <= sed[i]; j++) {
			k |= color[i][edge[i][j]];
		}
		if (k != 3) {t = 0;cout << "No solution"; return 0;}
	}
       for (int i = 1; i <= n; i++) {
              for (int j = 1; j <= sed[i]; j++) {
                     int p = edge[i][j];
                     cout << color[i][p] << ' ';
              }
              cout << 0 << endl;
       }
}
