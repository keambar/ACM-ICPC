#include <bits/stdc++.h>
using namespace std;
int s[3];
double dp[109][109][109];
inline int ff (int x) {
	if (x == 0) return 0;
	return x * (x - 1) / 2;
}
inline double f (int a, int b, int c) {
	int n = a + b + c;
	int tem = ff (n) - ff (a) - ff (b) - ff (c);
	if (tem)	return (a * b * 1.) / tem;
	return 0;
}
int main() {
	cin >> s[0] >> s[1] >> s[2];
	for (int p = 0; p < 3; ++p) {
		memset (dp, 0, sizeof dp);
		double ans = 0;
		dp[s[p]][s[ (p + 1) % 3]][s[ (p + 2) % 3]] = 1.;
		for (int k = s[p]; k >= 1; --k) {
			for (int i = s[ (p + 1) % 3]; i >= 0; --i)
				for (int j = s[ (p + 2) % 3]; j >= 0; --j) {
					dp[k][i][j] += dp[k + 1][i][j] * f (k + 1, j, i);
					dp[k][i][j] += dp[k][i + 1][j] * f (i + 1, k, j);
					dp[k][i][j] += dp[k][i][j + 1] * f (j + 1, i, k);
				}
			ans += dp[k][0][0];
		}
		printf ("%.10f ", ans);
	}
}
