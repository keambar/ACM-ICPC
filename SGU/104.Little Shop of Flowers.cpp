#include <iostream>
#include <sstream>
#include <string>
using namespace std;
const int INF = 111;
int f[INF][INF], g[INF][INF];
string pos[INF][INF];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			f[j][i] = -INF;
		}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= min (i, n); j++) {
			if (i > j)  f[i][j] = f[i - 1][j], pos[i][j] = pos[i - 1][j];
			if (f[i][j] == -INF || f[i][j] < f[i - 1][j - 1] + g[j][i]) {
				f[i][j] = f[i - 1][j - 1] + g[j][i];
				stringstream s;
				s << i;
				if (pos[i - 1][j - 1] != "")
					pos[i][j] = pos[i - 1][j - 1] + " " + s.str();
				else
					pos[i][j] = s.str();
			}
		}
	}
	cout << f[m][n] << endl;
	cout << pos[m][n];
	return 0;
}
