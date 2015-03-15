#include <iostream>
#include <cstring>
using namespace std;
const int mod = 101;
int n, m;
int c[10009];
//f[i][j]涂当前第i个球,和第i,第j个球的最小代价
//只保留最近的200个;
int f[200][200];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i];
	memset (f, 0x3f, sizeof f);
	f[1][0] = c[1];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j < i; j++)
			f[i][j] = c[i] + c[j];
	for (int j = 2; j < n; j++) {
		int tem = 0x3f3f3f3f;
		for (int i = j + m - 1; i > j; i--) {
			if (i <= m) break;
			tem = min (tem, f[j % mod][ (i - m) % mod]);
			f[i % mod][j % mod] = tem + c[i];
		}
	}
	int ans = 0x7fffffff;
	for (int i = n - m + 1; i <= n; i++)
		for (int j = i - 1; i - j < m && n - j < m; j--)
			ans = min (ans, f[i % mod][j % mod]);
	cout << ans;
	return 0;
}
