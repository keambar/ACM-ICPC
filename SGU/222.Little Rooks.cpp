#include <iostream>
using namespace std;
int f[11][11], n, m, ans;
int main() {
	ios::sync_with_stdio (0);
	cin >> n >> m;
	if (m <= n) {
        f[0][0]=1;
		for (int j = 0; j <= m; j++)
			for (int i = 1; i <= n; i++) {
				if (j > 0) f[i][j] = f[i - 1][j - 1] * (n - j + 1) + f[i-1][j];
				if (j == m) ans += f[i][j];
			}
		if (m == 0) ans = 1;
	}
	cout << ans << endl;
}
